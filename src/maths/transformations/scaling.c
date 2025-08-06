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

float	*scaling(t_mtx_4 res, float x, float y, float z)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][0] = x;
	res[1][1] = y;
	res[2][2] = z;
	return ((float *)res);
}
