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
