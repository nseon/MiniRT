/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:54:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/04 11:54:26 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	mtx2_determinant(t_mtx2 const m)
{
	return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

float	mtx3_determinant(t_mtx3 const m)
{
	return (m[0][0] * mtx3_cofactor(m, 0, 0)
		+ m[0][1] * mtx3_cofactor(m, 0, 1)
		+ m[0][2] * mtx3_cofactor(m, 0, 2));
}

float	mtx4_determinant(t_mtx4 const m)
{
	return (m[0][0] * mtx4_cofactor(m, 0, 0)
		+ m[0][1] * mtx4_cofactor(m, 0, 1)
		+ m[0][2] * mtx4_cofactor(m, 0, 2)
		+ m[0][3] * mtx4_cofactor(m, 0, 3));
}
