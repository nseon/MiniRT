/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:39:13 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/01 09:39:13 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ray.h"
#include "rt_maths.h"

void	sphere_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	t_tuple const	d = tp_sub(r.ori, point(0, 0, 0));
	double const	b = 2 * tp_dot(r.dir, d);
	double const	a = tp_dot(r.dir, r.dir);
	double const	dis = b * b - 4 * a * (tp_dot(d, d) - 1);

	if (dis >= 0)
	{
		xs->i[xs->count] = intersection((0 - b - sqrt(dis)) / (2 * a), o);
		if (d_equal(0, dis))
			xs->i[xs->count + 1] = xs->i[0];
		else
			xs->i[xs->count + 1] = intersection((0 - b + sqrt(dis))
					/ (2 * a), o);
		xs->count += 2;
	}
}
