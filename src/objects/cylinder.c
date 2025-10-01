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
