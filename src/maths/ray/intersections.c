/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:26:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 20:26:28 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ray.h"
#include "rt_maths.h"

t_intersection	intersection(float t, t_obj *obj)
{
	return ((t_intersection){t, obj});
}

t_intersections	intersect(t_ray r, t_obj *o)
{
	t_intersections	inter;
	t_tuple const	d = tp_sub(r.origin, o->pos);
	float const		b = 2 * tp_dot(r.dir, d);
	float const		a = tp_dot(r.dir, r.dir);
	float const		dis = b * b - 4 * a * (tp_dot(d, d) - 1);

	if (dis < 0)
		inter.count = 0;
	else
	{
		inter.count = 2;
		inter.i[0] = intersection((- b - sqrtf(dis)) / (2 * a), o);
		if (f_equal(0, dis))
			inter.i[1] = inter.i[0];
		else
			inter.i[1] = intersection((- b + sqrtf(dis)) / (2 * a), o);
	}
	return (inter);
}
