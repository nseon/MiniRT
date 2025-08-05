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

void	rotation_x(t_mtx_4 res, float r)
{
	mtx4_dup(g_identity_matrix, res);
	res[1][1] = cosf(r);
	res[1][2] = -sinf(r);
	res[2][1] = sinf(r);
	res[2][2] = cosf(r);
}

void	rotation_y(t_mtx_4 res, float r)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][0] = cosf(r);
	res[0][2] = sinf(r);
	res[2][0] = -sinf(r);
	res[2][2] = cosf(r);
}

void	rotation_z(t_mtx_4 res, float r)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][0] = cosf(r);
	res[0][1] = -sinf(r);
	res[1][0] = sinf(r);
	res[1][1] = cosf(r);
}
