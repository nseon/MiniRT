/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 00:20:35 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/05 00:20:35 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"
#include "objects.h"

#include <math.h>

void	set_uv_transf(t_material *mat, t_mtx4 transf)
{
	mtx4_dup(transf, mat->uv_transf);
	mtx4_inverse2(mat->uv_transf, mat->uv_inv_transf);
}

void	mul_uv_transf(t_material *mat, t_mtx4 transf)
{
	mtx_mul2(mat->uv_transf, transf);
	mtx4_inverse2(mat->uv_transf, mat->uv_inv_transf);
}

t_uv	uv(double u, double v)
{
	return ((t_uv){u, v});
}

t_uv	obj_uv(t_obj *o, t_tuple pt)
{
	double	i;

	mtx_tup_mul2(&pt, o->inv_transform);
	if (o->type == SPHERE)
		pt = sphere_uv_point(pt);
	else if (o->type == CUBE)
		pt = cube_uv_point(pt);
	else if (o->type == CYLINDER)
		pt = cylinder_uv_point(pt);
	mtx_tup_mul2(&pt, o->mat.uv_inv_transf);
	pt.x = modf(pt.x, &i);
	pt.z = modf(pt.z, &i);
	if (pt.x < 0)
		pt.x += 1;
	if (pt.z < 0)
		pt.z += 1;
	return ((t_uv){pt.x, pt.z});
}
