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

#include "errors.h"
#include "matrix.h"
#include "rt_maths.h"

bool mtx4_invertible(t_mtx_4 const m)
{
	return (!f_equal(mtx4_determinant(m), 0));
}

int32_t	mtx4_inverse(t_mtx_4 const m, t_mtx_4 res)
{
	float const	det = mtx4_determinant(m);

	if (!mtx4_invertible(m))
		return (FATAL);
	res[0][0] = mtx4_cofactor(m, 0, 0) / det;
	res[1][0] = mtx4_cofactor(m, 0, 1) / det;
	res[2][0] = mtx4_cofactor(m, 0, 2) / det;
	res[3][0] = mtx4_cofactor(m, 0, 3) / det;
	res[0][1] = mtx4_cofactor(m, 1, 0) / det;
	res[1][1] = mtx4_cofactor(m, 1, 1) / det;
	res[2][1] = mtx4_cofactor(m, 1, 2) / det;
	res[3][1] = mtx4_cofactor(m, 1, 3) / det;
	res[0][2] = mtx4_cofactor(m, 2, 0) / det;
	res[1][2] = mtx4_cofactor(m, 2, 1) / det;
	res[2][2] = mtx4_cofactor(m, 2, 2) / det;
	res[3][2] = mtx4_cofactor(m, 2, 3) / det;
	res[0][3] = mtx4_cofactor(m, 3, 0) / det;
	res[1][3] = mtx4_cofactor(m, 3, 1) / det;
	res[2][3] = mtx4_cofactor(m, 3, 2) / det;
	res[3][3] = mtx4_cofactor(m, 3, 3) / det;
	return (SUCCESS);
}
