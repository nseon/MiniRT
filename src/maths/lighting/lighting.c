/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:24:02 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/15 15:24:02 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

#include <stddef.h>

#include "ray.h"
#include "lib/libft/src/vector/vector.h"
#include "normals.h"
#include "rt_maths.h"

t_fcolor	blend_additives(t_world *w, t_fcolor col, t_pre_compute *pc, int n)
{
	double		reflectance;

	if (pc->obj->mat.reflective > 0 && pc->obj->mat.transparency > 0)
	{
		reflectance = schlick(pc);
		// col = col_scalar(col, 1 - pc->obj->mat.transparency * (1 - reflectance)
		// - pc->obj->mat.reflective * reflectance);
		col = color_add(col, col_scalar(reflect_color(w, pc, n), reflectance));
		col = color_add(col, col_scalar(refract_color(w, pc, n), 1 - reflectance));
		return (col);
	}
	// col = col_scalar(col, 1 - pc->obj->mat.transparency
	// 	- pc->obj->mat.reflective);
	col = color_add(col, reflect_color(w, pc, n));
	col = color_add(col, refract_color(w, pc, n));
	return (col);
}

t_fcolor		light_hit(t_world *w, t_pre_compute *pc, int n)
{
	t_fcolor	color;
	t_light		l;
	size_t		i;

	i = -1;
	if (pc->obj->mat.has_pat)
		color = col_scalar(color_mul(pattern_at_obj(pc->obj->mat.pat, pc->obj,
			pc->pos), w->amb.col), w->amb.i);
	else
		color = col_scalar(color_mul(pc->obj->mat.col, w->amb.col), w->amb.i);
	while (++i < vct_size(w->lights))
	{
		l = w->lights[i];
		if (!is_in_shadow(w, pc->over_point, &l))
			color = color_add(color, phong(pc->obj->mat, l, pc));
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
