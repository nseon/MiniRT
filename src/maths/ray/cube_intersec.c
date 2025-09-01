/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:39:19 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/01 09:39:19 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>

#include "ray.h"
#include "rt_maths.h"

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
