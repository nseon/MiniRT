/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:40:54 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/01 09:40:54 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include <stdio.h>

#include "ray.h"
#include "rt_maths.h"

void	trunc_intersec(t_ray r, double dis, double b, t_intersections *xs)
{
	double const	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	double			y;
	double			t0;
	double			t1;

	t0 = (- b - sqrt(dis)) / (2 * a);
	t1 = (- b + sqrt(dis)) / (2 * a);
	if (t0 > t1)
		dswap(&t0, &t1);
	y = r.origin.y + r.dir.y * t0;
	if (xs->i[xs->count].obj->min < y && y < xs->i[xs->count].obj->max)
		xs->i[xs->count++].t = t0;
	y = r.origin.y + r.dir.y * t1;
	if (xs->i[xs->count].obj->min < y && y < xs->i[xs->count].obj->max)
		xs->i[xs->count++].t = t1;
}

void	cylinder_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	double const	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	double			b;
	double			c;
	double			dis;

	if (d_equal(a, 0))
		return ;
	b = 2 * r.origin.x * r.dir.x + 2 * r.origin.z * r.dir.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	dis = b * b - 4 * a * c;
	if (dis < 0)
		return ;
	xs->i[xs->count].obj = o;
	xs->i[xs->count + 1].obj = o;
	trunc_intersec(r, dis, b, xs);
}
