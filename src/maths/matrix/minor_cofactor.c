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

double	mtx3_minor(t_mtx3 const m, int row, int col)
{
	t_mtx2	sub;

	mtx3_submatrix(m, row, col, sub);
	return (mtx2_determinant(sub));
}

double	mtx3_cofactor(t_mtx3 const m, int row, int col)
{
	double const	minor = mtx3_minor(m, row, col);

	if ((row + col) % 2 == 1)
		return (-minor);
	return (minor);
}

double	mtx4_minor(t_mtx4 const m, int row, int col)
{
	t_mtx3	sub;

	mtx4_submatrix(m, row, col, sub);
	return (mtx3_determinant(sub));
}

double	mtx4_cofactor(t_mtx4 const m, int row, int col)
{
	double const	minor = mtx4_minor(m, row, col);

	if ((row + col) % 2 == 1)
		return (-minor);
	return (minor);
}
