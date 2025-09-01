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
#include "tuple.h"

t_obj	cylinder(void)
{
	t_obj	o;

	o = (t_obj){.type = CYLINDER, .uid = get_uid(), .mat = g_default_mat,
		.min = (double)-4849848494964964879, .max = DBL_MAX};
	mtx4_dup(g_identity_matrix, o.transform);
	mtx4_dup(g_identity_matrix, o.inv_transform);
	return (o);
}

t_tuple	cylinder_normal(t_tuple pt)
{
	return (vector(pt.x, 0, pt.z));
}
