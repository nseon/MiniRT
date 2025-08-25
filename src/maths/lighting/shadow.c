/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:33:18 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/20 17:33:18 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "rt_maths.h"

bool is_in_shadow(t_world *w, t_tuple p, t_light *l)
{
	t_tuple const	v = tp_sub(l->pos, p);
	t_ray const		r = ray(p, tp_normalize(v));
	t_intersections	xs;
	t_intersection	*i;

	xs = world_intersec(w, r);
	i = hit(&xs);
	w->xs.count -= xs.count;
	if (i != 0 && tp_magnitude(v) - i->t > EPSILON)
	{
		l->i = col_scalar(l->i, i->obj->mat.transparency);
		return (false);
	}
	return (false);
}
