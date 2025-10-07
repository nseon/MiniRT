/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:00:50 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/07 10:42:26 by nseon            ###   ########.fr       */
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

	o = (t_obj){.type = CUBE, .uid = get_uid(), .mat = g_default_mat,
		.pos = point(0, 0, 0), .x_size = 1, .y_size = 1, .z_size = 1,
		.x_rot = 0, .y_rot = 0, .z_rot = 0, .hide = false};
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

t_tuple	cube_uv_point(t_tuple pt)
{
	double const	max = cube_max(dabs(pt.x), dabs(pt.y), dabs(pt.z), 1);
	t_tuple			npt;

	if (max == dabs(pt.x))
		npt = point(pt.z, 0, pt.y);
	else if (max == dabs(pt.y))
		npt = point(pt.x, 0, pt.z);
	else
		npt = point(pt.x, 0, pt.y);
	npt.x = npt.x / 2 + 0.5;
	npt.z = npt.z / 2 + 0.5;
	return (npt);
}
