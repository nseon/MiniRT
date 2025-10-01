/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:21:04 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/12 18:21:04 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "normals.h"
#include "objects.h"
#include "ray.h"
#include "rt_maths.h"
#include "tuple.h"

t_obj	sphere(void)
{
	t_obj	o;

	o = (t_obj){.type = SPHERE, .uid = get_uid(), .mat = g_default_mat,
		.pos = point(0, 0, 0), .x_size = 1, .y_size = 1, .z_size = 1,
		.x_rot = 0, .y_rot = 0, .z_rot = 0, .hide = false};
	mtx4_dup(g_identity_matrix, o.transform);
	mtx4_dup(g_identity_matrix, o.inv_transform);
	return (o);
}

t_obj	glass_sphere(void)
{
	t_obj	o;

	o = sphere();
	o.mat.transparency = 1;
	o.mat.refractive = 1.5;
	return (o);
}

t_tuple	sphere_normal(t_tuple pt)
{
	pt.w = 0;
	return (pt);
}

t_tuple	sphere_uv_point(t_tuple	pt)
{
	pt = tp_negate(pt);
	pt.x = 0.5 + atan2(pt.z, pt.x) / (M_PI * 2);
	pt.z = 0.5 + asin(pt.y) / M_PI;
	pt.x *= 2;
	pt.z *= 2;
	pt.y = 0;
	pt.w = 1;
	return (pt);
}
