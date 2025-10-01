/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:31:46 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/20 23:31:46 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "normals.h"
#include "tuple.h"
#include "objects.h"
#include "ray.h"
#include "rt_maths.h"

t_obj	plane(void)
{
	t_obj	o;

	o = (t_obj){.type = PLANE, .uid = get_uid(), .mat = g_default_mat,
		.pos = point(0, 0, 0), .x_size = 1, .y_size = 1, .z_size = 1,
		.x_rot = 0, .y_rot = 0, .z_rot = 0, .hide = false};
	mtx4_dup(g_identity_matrix, o.transform);
	mtx4_dup(g_identity_matrix, o.inv_transform);
	return (o);
}

t_tuple	plane_normal(t_tuple pt)
{
	(void)pt;
	return (vector(0, 1, 0));
}
