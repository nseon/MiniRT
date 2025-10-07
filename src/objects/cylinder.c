/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:41:04 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/01 09:41:04 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <tgmath.h>

#include "normals.h"
#include "objects.h"
#include "ray.h"
#include "rt_maths.h"
#include "tuple.h"

t_obj	cylinder(void)
{
	t_obj	o;

	o = (t_obj){.type = CYLINDER, .uid = get_uid(), .mat = g_default_mat,
		.min = (double)-DBL_MAX, .max = DBL_MAX, .closed = false,
		.pos = point(0, 0, 0), .x_size = 1, .y_size = 1, .z_size = 1,
		.x_rot = 0, .y_rot = 0, .z_rot = 0, .hide = false};
	mtx4_dup(g_identity_matrix, o.transform);
	mtx4_dup(g_identity_matrix, o.inv_transform);
	return (o);
}

t_tuple	cylinder_normal(t_obj *o, t_tuple pt)
{
	double const	dis = pt.x * pt.x + pt.z * pt.z;

	if (dis <= 1 && pt.y >= o->max - DEPSILON)
		return (vector(0, 1, 0));
	if (dis <= 1 && pt.y <= o->min + DEPSILON)
		return (vector(0, -1, 0));
	return (vector(pt.x, 0, pt.z));
}

t_tuple	cylinder_uv_point(t_tuple pt)
{
	pt = tp_negate(pt);
	if (pt.x * pt.x + pt.z * pt.z < 1 - EPSILON)
	{
		pt.x = 0.5 + pt.x * -1 / 2;
		pt.z = 0.5 + pt.z * -1 / 2;
	}
	else
	{
		pt.x = 0.5 + atan2(pt.z, pt.x) / (M_PI * 2);
		pt.z = 0.5 + -pt.y / 2;
	}
	pt.y = 0;
	pt.w = 1;
	return (pt);
}
