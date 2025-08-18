/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:48:23 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/18 13:48:23 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mtx4_ret	mtx4_view(t_tuple from, t_tuple to, t_tuple up, t_mtx4 res)
{
	t_tuple const	forward = tp_normalize(tp_sub(to, from));
	t_tuple const	left = tp_cross(forward, tp_normalize(up));
	t_tuple const	true_up = tp_cross(left, forward);
	t_mtx4			buf;

	res[0][0] = left.x;
	res[0][1] = left.y;
	res[0][2] = left.z;
	res[0][3] = 0;
	res[1][0] = true_up.x;
	res[1][1] = true_up.y;
	res[1][2] = true_up.z;
	res[1][3] = 0;
	res[2][0] = -forward.x;
	res[2][1] = -forward.y;
	res[2][2] = -forward.z;
	res[2][3] = 0;
	res[3][0] = 0;
	res[3][1] = 0;
	res[3][2] = 0;
	res[3][3] = 1;
	return (mtx_mul2(res, translation(-from.x, -from.y, -from.z, buf)));
}
