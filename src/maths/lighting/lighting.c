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

t_pre_compute	pre_compute(t_intersection *i, t_ray r)
{
	t_pre_compute	pc;

	pc.t = i->t;
	pc.obj = i->obj;
	pc.pos = position(r, pc.t);
	pc.eyev = tp_negate(r.dir);
	pc.normalv = obj_normal(i->obj, pc.pos);
	if (tp_dot(pc.normalv, pc.eyev) < 0)
	{
		pc.inside = true;
		pc.normalv = tp_negate(pc.normalv);
	}
	else
		pc.inside = false;
	pc.over_point = tp_add(pc.pos, tp_mul(pc.normalv, DEPSILON));
	return (pc);
}

t_fcolor		light_hit(t_world *w, t_pre_compute *pc)
{
	t_fcolor	color;
	size_t		i;

	i = -1;
	if (pc->obj->mat.has_pat)
		color = col_scalar(color_mul(pattern_at_obj(pc->obj->mat.pat, pc->obj,
			pc->pos), w->amb.col), w->amb.i);
	else
		color = col_scalar(color_mul(pc->obj->mat.col, w->amb.col), w->amb.i);
	while (++i < vct_size(w->lights))
	{
		if (!is_in_shadow(w, pc->over_point, w->lights[i]))
			color = color_add(color, phong(pc->obj->mat, w->lights[i], pc));
	}
	return (color);
}

t_fcolor	color_at(t_world *w, t_ray r)
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
	pc = pre_compute(i, r);
	w->xs.count -= xs.count;
	return (light_hit(w, &pc));
}

