/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:24:02 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/07 10:31:01 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

#include <stddef.h>

#include "ray.h"
#include "lib/libft/src/vector/vector.h"
#include "normals.h"
#include "rt_maths.h"
#include "render.h"

t_fcolor	indirect_light(t_world *w, t_pre_compute *pc, int n)
{
	t_ray			r;
	t_fcolor		rcolor;
	t_intersections	xs;
	t_intersection	*i;
	double			distance;

	if (n < 1)
		return (fcolor(0, 0, 0));
	r = ray(pc->over_point, random_bounce(pc->normalv));
	xs = world_intersec(w, r);
	i = hit(&xs);
	w->xs.count -= xs.count;
	if (!i)
		return (fcolor(0, 0, 0));
	distance = i->t;
	rcolor = color_at(w, r, n - 3);
	return (col_scalar(color_mul(rcolor, obj_color(pc->obj, pc->uv)),
			1.0 / (1 + distance * distance)));
}

t_fcolor	blend_additives(t_world *w, t_fcolor col, t_pre_compute *pc, int n)
{
	double		reflectance;

	if (pc->obj->mat.reflective > 0 && pc->obj->mat.transparency > 0
		&& w->gparam & REFLECT && w->gparam & TRANSPARENCY)
	{
		reflectance = schlick(pc);
		col = color_add(col, col_scalar(reflect_color(w, pc, n), reflectance));
		col = color_add(col, col_scalar(refract_color(w, pc, n),
					1 - reflectance));
		return (col);
	}
	if (w->gparam & REFLECT)
		col = color_add(col, reflect_color(w, pc, n));
	if (w->gparam & TRANSPARENCY)
		col = color_add(col, refract_color(w, pc, n));
	if ((w->gparam & INDIRECT) && !(w->gparam & EDIT))
		col = color_add(col, indirect_light(w, pc, n));
	return (col);
}

t_fcolor	light_hit(t_world *w, t_pre_compute *pc, int n)
{
	t_fcolor	color;
	size_t		i;
	t_amb		amb;

	i = -1;
	color = fcolor(0, 0, 0);
	if (w->gparam & AMBIENT)
	{
		amb = w->amb;
		if (pc->obj->mat.has_aomap)
			amb.i *= map_to_ao(&pc->obj->mat.aomap, pc->uv);
		color = col_scalar(color_mul(obj_color(pc->obj, pc->uv), amb.col),
				amb.i);
	}
	while (++i < vct_size(w->lights))
	{
		if (w->gparam & SHADOWS)
			is_in_shadow(w, pc->over_point, w->lights + i);
		color = color_add(color, phong(pc->obj->mat,
					w->lights[i], pc, w->gparam));
	}
	return (blend_additives(w, color, pc, n));
}

t_fcolor	color_at(t_world *w, t_ray r, int n)
{
	t_intersections	xs;
	t_intersection	*i;
	t_pre_compute	pc;

	xs = world_intersec(w, r);
	i = hit(&xs);
	if (!i)
	{
		w->xs.count -= xs.count;
		return (w->back_col);
	}
	pc = pre_compute(i, r, &xs);
	w->xs.count -= xs.count;
	return (light_hit(w, &pc, n));
}

t_fcolor	reflect_color(t_world *w, t_pre_compute *pc, int n)
{
	t_fcolor	rcolor;
	t_ray		r;

	if (n < 1 || d_equal(pc->obj->mat.reflective, 0))
		return (fcolor(0, 0, 0));
	r = ray(pc->over_point, pc->reflectv);
	rcolor = color_at(w, r, n - 1);
	return (col_scalar(rcolor, pc->obj->mat.reflective));
}
