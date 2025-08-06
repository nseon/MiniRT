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

const float g_arr2_0[2] = {0, 0};

float	*shearing(t_mtx_4 res, float const x[2], float const y[2], float const z[2])
{
    mtx4_dup(g_identity_matrix, res);
    res[0][1] = x[0];
    res[0][2] = x[1];
    res[1][0] = y[0];
    res[1][2] = y[1];
    res[2][0] = z[0];
    res[2][1] = z[1];
    return ((float *)res);
}
