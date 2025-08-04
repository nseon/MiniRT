/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:34:41 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/31 20:34:41 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	mtx2_determinant(t_mtx_2 const m)
{
	return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

float	mtx3_minor(t_mtx_3 const m, int row, int col)
{
	t_mtx_2	sub;

	mtx3_submatrix(m, row, col, sub);
	return (mtx2_determinant(sub));
}

float	mtx3_cofactor(t_mtx_3 const m, int row, int col)
{
	float const	minor = mtx3_minor(m, row, col);

	if ((row + col) % 2 == 1)
		return (-minor);
	return (minor);
}
