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

static void	trunc_intersec(t_ray r, double dis, double b, t_intersections *xs)
{
	double const	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	double			y;
	double			t0;
	double			t1;

	t0 = (- b - sqrt(dis)) / (2 * a);
	t1 = (- b + sqrt(dis)) / (2 * a);
	if (t0 > t1)
		dswap(&t0, &t1);
	y = r.ori.y + r.dir.y * t0;
	if (xs->i[xs->count].obj->min < y && y < xs->i[xs->count].obj->max)
		xs->i[xs->count++].t = t0;
	y = r.ori.y + r.dir.y * t1;
	if (xs->i[xs->count].obj->min < y && y < xs->i[xs->count].obj->max)
		xs->i[xs->count++].t = t1;
}

static bool	check_cap(t_ray r, double t)
{
	double const	x = r.ori.x + r.dir.x * t;
	double const	z = r.ori.z + r.dir.z * t;

	if (x * x + z * z <= 1)
		return (true);
	return (false);
}

static void	cap_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	double	t;

	if (!o->closed || d_equal(0, r.dir.y))
		return ;
	t = (o->min - r.ori.y) / r.dir.y;
	if (check_cap(r, t))
		xs->i[xs->count++].t = t;
	t = (o->max - r.ori.y) / r.dir.y;
	if (check_cap(r, t))
		xs->i[xs->count++].t = t;
}

void	cylinder_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	double const	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	double			b;
	double			c;
	double			dis;

	xs->i[xs->count].obj = o;
	xs->i[xs->count + 1].obj = o;
	if (!d_equal(a, 0))
	{
		b = 2 * r.ori.x * r.dir.x + 2 * r.ori.z * r.dir.z;
		c = r.ori.x * r.ori.x + r.ori.z * r.ori.z - 1;
		dis = b * b - 4 * a * c;
		if (dis < 0)
			return ;
		trunc_intersec(r, dis, b, xs);
	}
	cap_intersect(r, o, xs);
}
