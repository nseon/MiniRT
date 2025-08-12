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

#include "normals.h"
#include "tuple.h"
#include "objects.h"

t_tuple	sphere_normal(t_obj *o, t_tuple pt)
{
	t_mtx4			buf;
	// t_tuple const	opt = mtx_tup_mul(pt, o->inv_transform);
	// t_tuple const	n = tp_sub(opt, o->pos);

	return (mtx_tup_mul(tp_sub(mtx_tup_mul(pt, o->inv_transform), o->pos), mtx_transpose2(o->inv_transform, buf)));
}
