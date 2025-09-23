/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:42:09 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/05 09:42:09 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mtx4_ret	translation(double x, double y, double z, t_mtx4 res)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][3] = x;
	res[1][3] = y;
	res[2][3] = z;
	return (res);
}

t_tuple	tp_translation(double x, double y, double z, t_tuple tp)
{
	t_mtx4	rot;

	return (mtx_tup_mul(tp, translation(x, y, z, rot)));
}

t_mtx4_ret	mx_translation(double x, double y, double z, t_mtx4 res)
{
	t_mtx4	buf;

	return (mtx_mul2(res, translation(x, y, z, buf)));
}
