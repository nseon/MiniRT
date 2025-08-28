/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:00:50 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/28 17:00:50 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include <limits.h>

#include "normals.h"
#include "objects.h"
#include "ray.h"
#include "rt_maths.h"
#include "tuple.h"

t_obj	cube(void)
{
	t_obj	o;

	o = (t_obj){.type = CUBE, .uid = get_uid(), .mat = g_default_mat};
	mtx4_dup(g_identity_matrix, o.transform);
	mtx4_dup(g_identity_matrix, o.inv_transform);
	return (o);
}

double	cube_max(double x, double y, double z, int sign)
{
	if (sign)
	{
		if ((x > y) && (x > z))
			return (x);
		if ((y > x) && (y > z))
			return (y);
		return (z);
	}
	if ((x < y) && (x < z))
		return (x);
	if ((y < x) && (y < z))
		return (y);
	return (z);
}

t_tuple	cube_normal(t_tuple pt)
{
	double const	max = cube_max(dabs(pt.x), dabs(pt.y), dabs(pt.z), 1);

	if (max == dabs(pt.x))
		return (vector(pt.x, 0, 0));
	if (max == dabs(pt.y))
		return (vector(0, pt.y, 0));
	return (vector(0, 0, pt.z));
}

static void	check_axis(double ori, double dir, double res[2])
{
	double const	tmin_num = -1 - ori;
	double const	tmax_num = 1 - ori;
	double			tmin;
	double			tmax;
	int				inv;

	if (dabs(dir) >= EPSILON)
	{
		tmin = tmin_num / dir;
		tmax = tmax_num / dir;
	}
	else
	{
		if (tmin_num < 0)
			tmin = DBL_MIN;
		else
			tmin = DBL_MAX;
		if (tmax_num < 0)
			tmax = DBL_MIN;
		else
			tmax = DBL_MAX;
	}
	inv = tmin > tmax;
	res[0 + inv] = tmin;
	res[1 - inv] = tmax;
}

void	cube_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	double	xt[2];
	double	yt[2];
	double	zt[2];
	double	tmin;
	double	tmax;

	check_axis(r.origin.x, r.dir.x, xt);
	check_axis(r.origin.y, r.dir.y, yt);
	check_axis(r.origin.z, r.dir.z, zt);

	tmin = cube_max(xt[0], yt[0], zt[0], 1);
	tmax = cube_max(xt[1], yt[1], zt[1], 0);
	if (tmin > tmax)
		return ;
	xs->i[xs->count] = intersection(tmin, o);
	xs->i[xs->count + 1] = intersection(tmax, o);
	xs->count += 2;
}
