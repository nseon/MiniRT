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
		if (!is_in_shadow(w, pc->over_point, l))
			color = color_add(color, phong(pc->obj->mat, l, pc));
	}
	color = col_scalar(color, 1 - pc->obj->mat.transparency
		- pc->obj->mat.reflective);
	color = color_add(color, reflect_color(w, pc, n));
	color = color_add(color, refract_color(w, pc, n));
	return (color);
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
		return (fcolor(0, 0, 0));
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
