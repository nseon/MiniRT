/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:53:39 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/31 20:53:39 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mtx3_ret	mtx4_submatrix(t_mtx4 const m, int row, int col, t_mtx3 sub)
{
	int32_t	wx;
	int32_t	x;
	int32_t	wy;
	int32_t	y;

	wy = 0;
	y = -1;
	while (++y < 4)
	{
		if (y == row)
			continue ;
		x = -1;
		wx = 0;
		while (++x < 4)
		{
			if (x == col)
				continue ;
			sub[wy][wx] = m[y][x];
			++wx;
		}
		++wy;
	}
	return (sub);
}

t_mtx2_ret	mtx3_submatrix(t_mtx3 const m, int row, int col, t_mtx2 sub)
{
	int32_t	wx;
	int32_t	x;
	int32_t	wy;
	int32_t	y;

	wy = 0;
	y = -1;
	while (++y < 3)
	{
		if (y == row)
			continue ;
		x = -1;
		wx = 0;
		while (++x < 3)
		{
			if (x == col)
				continue ;
			sub[wy][wx] = m[y][x];
			++wx;
		}
		++wy;
	}
	return (sub);
}
