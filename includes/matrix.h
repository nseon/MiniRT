/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:59:02 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/31 11:59:02 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>
# include "tuple.h"

typedef float			t_mtx_4[4][4];
typedef float			t_mtx_3[3][3];
typedef float			t_mtx_2[2][2];

extern const t_mtx_4	g_identity_matrix;

bool	mtx4_equal(t_mtx_4 const m1, t_mtx_4 const m2);
bool	mtx3_equal(t_mtx_3 const m1, t_mtx_3 const m2);
bool	mtx2_equal(t_mtx_2 const m1, t_mtx_2 const m2);

void	mtx_mul(t_mtx_4 const m1, t_mtx_4 const m2,
	t_mtx_4 res);
t_tuple	mtx_tup_mul(t_tuple tp, t_mtx_4 const m);
void	mtx_transpose(t_mtx_4 m);
float	mtx2_determinant(t_mtx_2 const m);
float	mtx3_determinant(t_mtx_3 const m);
float	mtx4_determinant(t_mtx_4 const m);

void	mtx4_submatrix(t_mtx_4 const m, int row, int col, t_mtx_3 sub);
void	mtx3_submatrix(t_mtx_3 const m, int row, int col, t_mtx_2 sub);

float	mtx3_minor(t_mtx_3 const m, int row, int col);
float	mtx3_cofactor(t_mtx_3 const m, int row, int col);

float	mtx4_minor(t_mtx_4 const m, int row, int col);
float	mtx4_cofactor(t_mtx_4 const m, int row, int col);

bool	mtx4_invertible(t_mtx_4 const m);
int32_t	mtx4_inverse(t_mtx_4 const m, t_mtx_4 res);

#endif
