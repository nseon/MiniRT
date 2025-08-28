/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:58:12 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/20 22:58:12 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normals.h"
#include "tuple.h"
#include "objects.h"

t_tuple	obj_normal(t_obj *o, t_tuple pt)
{
	t_tuple const	local_pt = mtx_tup_mul(pt, o->inv_transform);
	t_tuple			n;
	t_mtx4			tbuf;

	if (o->type == SPHERE)
		n = sphere_normal(local_pt);
	else if (o->type == PLANE)
		n = plane_normal(local_pt);
	else if (o->type == CUBE)
		n = cube_normal(local_pt);
	mtx_tup_mul2(&n, mtx_transpose2(o->inv_transform, tbuf));
	n.w = 0;
	return (tp_normalize(n));
}
