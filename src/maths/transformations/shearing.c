/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:29:35 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/05 22:29:35 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mtx4_ret	shearing(double const x[2], double const y[2], double const z[2],
						t_mtx4 res)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][1] = x[0];
	res[0][2] = x[1];
	res[1][0] = y[0];
	res[1][2] = y[1];
	res[2][0] = z[0];
	res[2][1] = z[1];
	return (res);
}

t_tuple	tp_shearing(double const x[2], double const y[2], double const z[2],
					t_tuple tp)
{
	t_mtx4	rot;

	return (mtx_tup_mul(tp, shearing(x, y, z, rot)));
}

t_mtx4_ret	mx_shearing(double const x[2], double const y[2], double const z[2],
							t_mtx4 res)
{
	t_mtx4	buf;

	return (mtx_mul2(res, shearing(x, y, z, buf)));
}
