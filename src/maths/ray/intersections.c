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
#include <stdlib.h>

#include "ray.h"
#include "rt_maths.h"
#include "lib/libft/src/vector/vector.h"

t_intersection	intersection(double t, t_obj *obj)
{
	return ((t_intersection){t, obj});
}

void	intersect_calc(t_ray r, t_obj *o, t_intersections *xs)
{
	t_tuple const	d = tp_sub(r.origin, point(0, 0, 0));
	double const		b = 2 * tp_dot(r.dir, d);
	double const		a = tp_dot(r.dir, r.dir);
	double const		dis = b * b - 4 * a * (tp_dot(d, d) - 1);

	if (dis >= 0)
	{
		xs->i[xs->count] = intersection((- b - sqrtf(dis)) / (2 * a), o);
		if (f_equal(0, dis))
			xs->i[xs->count + 1] = xs->i[0];
		else
			xs->i[xs->count + 1] = intersection((- b + sqrtf(dis)) / (2 * a), o);
		xs->count += 2;
	}
}

void intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	return (intersect_calc(ray_transform(r, o->inv_transform), o, xs));
}

t_intersection	*hit(t_intersections *inters)
{
	t_intersection	*min;
	int32_t			i;

	min = NULL;
	i = -1;
	while (++i < inters->count)
	{
		if (inters->i[i].t < 0)
			continue ;
		if (min == NULL || inters->i[i].t < min->t)
			min = inters->i + i;
	}
	return (min);
}
//
// int32_t	free_intersections(t_intersections *inters)
// {
// 	free(inters->i);
// 	return (0);
// }
