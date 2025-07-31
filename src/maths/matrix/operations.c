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

#include "matrix.h"
#include "rt_maths.h"

#include <stdint.h>

bool	mtx_equal(t_mtx_4 const m1, t_mtx_4 const m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!f_equal(m1[i][j], m2[i][j]))
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

void	mtx_mul(t_mtx_4 const m1, t_mtx_4 const m2,
	t_mtx_4 res)
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
}

t_tuple	mtx_tup_mul(t_tuple tp, t_mtx_4 const m)
{
	t_tuple	ntp;

	ntp.x = tp.x * m[0][0] + tp.y * m[0][1] + tp.z * m[0][2] + tp.w * m[0][3];
	ntp.y = tp.x * m[1][0] + tp.y * m[1][1] + tp.z * m[1][2] + tp.w * m[1][3];
	ntp.z = tp.x * m[2][0] + tp.y * m[2][1] + tp.z * m[2][2] + tp.w * m[2][3];
	ntp.w = tp.x * m[3][0] + tp.y * m[3][1] + tp.z * m[3][2] + tp.w * m[3][3];
	return (ntp);
}
