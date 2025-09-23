/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:35:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/06 19:35:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "matrix.h"

t_mtx4_ret	rotation_z(double r, t_mtx4 res)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][0] = cos(r);
	res[0][1] = -sin(r);
	res[1][0] = sin(r);
	res[1][1] = cos(r);
	return (res);
}

t_tuple	tp_rotation_z(double r, t_tuple tp)
{
	t_mtx4	rot;

	return (mtx_tup_mul(tp, rotation_z(r, rot)));
}

t_mtx4_ret	mx_rotation_z(double r, t_mtx4 res)
{
	t_mtx4	buf;

	return (mtx_mul2(res, rotation_z(r, buf)));
}
