/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:20:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/05 11:20:26 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "matrix.h"

t_mtx4_ret	rotation_x(double r, t_mtx4 res)
{
	mtx4_dup(g_identity_matrix, res);
	res[1][1] = cos(r);
	res[1][2] = -sin(r);
	res[2][1] = sin(r);
	res[2][2] = cos(r);
	return (res);
}

t_tuple	tp_rotation_x(double r, t_tuple tp)
{
	t_mtx4	rot;

	return (mtx_tup_mul(tp, rotation_x(r, rot)));
}

t_mtx4_ret	mx_rotation_x(double r, t_mtx4 res)
{
	t_mtx4	buf;

	return (mtx_mul2(res, rotation_x(r, buf)));
}
