/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:13:20 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/05 11:13:20 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mtx4_ret	scaling(float x, float y, float z, t_mtx4 res)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][0] = x;
	res[1][1] = y;
	res[2][2] = z;
	return (res);
}

t_tuple		tp_scaling(float x, float y, float z, t_tuple tp)
{
	t_mtx4	rot;

	return (mtx_tup_mul(tp, scaling(x, y, z, rot)));
}

t_mtx4_ret	mx_scaling(float x, float y, float z, t_mtx4 res)
{
	t_mtx4	buf;

	return (mtx_mul2(res, scaling(x, y, z, buf)));
}
