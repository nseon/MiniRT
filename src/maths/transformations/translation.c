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

float	*translation(t_mtx_4 res, float x, float y, float z)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][3] = x;
	res[1][3] = y;
	res[2][3] = z;
	return ((float *)res);
}
