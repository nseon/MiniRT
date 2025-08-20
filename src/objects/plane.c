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

	o = (t_obj){.type = PLANE, .uid = get_uid(), .mat = g_default_mat};
	mtx4_dup(g_identity_matrix, o.transform);
	mtx4_dup(g_identity_matrix, o.inv_transform);
	return (o);
}

t_tuple	plane_normal(t_tuple pt)
{
	(void)pt;
	return (vector(0, 1, 0));
}

void	plane_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	if (dabs(r.dir.y) < EPSILON)
		return ;
	xs->i[xs->count] = intersection(-r.origin.y / r.dir.y, o);
	xs->count++;
}
