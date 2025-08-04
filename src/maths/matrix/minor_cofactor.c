/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_cofactor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:57:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/04 11:57:16 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

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

float	mtx4_minor(t_mtx_4 const m, int row, int col)
{
	t_mtx_3	sub;

	mtx4_submatrix(m, row, col, sub);
	return (mtx3_determinant(sub));
}

float	mtx4_cofactor(t_mtx_4 const m, int row, int col)
{
	float const	minor = mtx4_minor(m, row, col);

	if ((row + col) % 2 == 1)
		return (-minor);
	return (minor);
}
