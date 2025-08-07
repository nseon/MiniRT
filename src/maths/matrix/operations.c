/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:11:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/31 13:11:21 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "matrix.h"
#include <stdint.h>

t_mtx4_ret	mtx_mul(t_mtx4 const m1, t_mtx4 const m2,
	t_mtx4 res)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			res[y][x] = m1[y][0] * m2[0][x]
				+ m1[y][1] * m2[1][x]
				+ m1[y][2] * m2[2][x]
				+ m1[y][3] * m2[3][x];
			++y;
		}
		++x;
	}
	return (res);
}

t_mtx4_ret	mtx_mul2(t_mtx4 m1, t_mtx4 const m2)
{
	int32_t	x;
	int32_t	y;
	t_mtx4	m1_dup;

	mtx4_dup(m1, m1_dup);
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			m1[y][x] = m1_dup[y][0] * m2[0][x]
				+ m1_dup[y][1] * m2[1][x]
				+ m1_dup[y][2] * m2[2][x]
				+ m1_dup[y][3] * m2[3][x];
			++y;
		}
		++x;
	}
	return (m1);
}

t_tuple	mtx_tup_mul(t_tuple tp, t_mtx4 const m)
{
	t_tuple	ntp;

	ntp.x = tp.x * m[0][0] + tp.y * m[0][1] + tp.z * m[0][2] + tp.w * m[0][3];
	ntp.y = tp.x * m[1][0] + tp.y * m[1][1] + tp.z * m[1][2] + tp.w * m[1][3];
	ntp.z = tp.x * m[2][0] + tp.y * m[2][1] + tp.z * m[2][2] + tp.w * m[2][3];
	ntp.w = tp.x * m[3][0] + tp.y * m[3][1] + tp.z * m[3][2] + tp.w * m[3][3];
	return (ntp);
}

t_tuple	*mtx_tup_mul2(t_tuple *tp, t_mtx4 const m)
{
	t_tuple	tp2;

	tp2.x = tp->x;
	tp2.y = tp->y;
	tp2.z = tp->z;
	tp2.w = tp->w;
	tp->x = tp2.x * m[0][0] + tp2.y * m[0][1]
		+ tp2.z * m[0][2] + tp2.w * m[0][3];
	tp->y = tp2.x * m[1][0] + tp2.y * m[1][1]
		+ tp2.z * m[1][2] + tp2.w * m[1][3];
	tp->z = tp2.x * m[2][0] + tp2.y * m[2][1]
		+ tp2.z * m[2][2] + tp2.w * m[2][3];
	tp->w = tp2.x * m[3][0] + tp2.y * m[3][1]
		+ tp2.z * m[3][2] + tp2.w * m[3][3];
	return (tp);
}
