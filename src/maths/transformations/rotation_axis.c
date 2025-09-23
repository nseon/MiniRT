/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:16:06 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/11 16:16:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "matrix.h"

t_mtx4_ret	rotation_axis(double r, t_tuple u, t_mtx4 res)
{
	mtx4_dup(g_identity_matrix, res);
	res[0][0] = cos(r) + u.x * u.x * (1 - cos(r));
	res[0][1] = u.x * u.y * (1 - cos(r)) - u.z * sin(r);
	res[0][2] = u.x * u.z * (1 - cos(r)) - u.y * sin(r);
	res[1][0] = u.y * u.x * (1 - cos(r)) - u.z * sin(r);
	res[1][1] = cos(r) + u.y * u.y * (1 - cos(r));
	res[1][2] = u.y * u.z * (1 - cos(r)) - u.x * sin(r);
	res[2][0] = u.z * u.x * (1 - cos(r)) - u.y * sin(r);
	res[2][1] = u.z * u.y * (1 - cos(r)) - u.x * sin(r);
	res[2][2] = cos(r) + u.z * u.z * (1 - cos(r));
	return (res);
}
