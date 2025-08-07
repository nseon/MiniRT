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

typedef float			t_mtx4[4][4];
typedef float			(*t_mtx4_ret)[4];
typedef float			t_mtx3[3][3];
typedef float			(*t_mtx3_ret)[3];
typedef float			t_mtx2[2][2];
typedef float			(*t_mtx2_ret)[2];

extern const t_mtx4		g_identity_matrix;
extern const float		g_arr2_0[2];

bool		mtx4_equal(t_mtx4 const m1, t_mtx4 const m2);
bool		mtx3_equal(t_mtx3 const m1, t_mtx3 const m2);
bool		mtx2_equal(t_mtx2 const m1, t_mtx2 const m2);

t_mtx4_ret	mtx4_dup(t_mtx4 const m, t_mtx4 res);

t_mtx4_ret	mtx_mul(t_mtx4 const m1, t_mtx4 const m2,
				t_mtx4 res);
t_mtx4_ret	mtx_mul2(t_mtx4 m1, t_mtx4 const m2);

t_tuple		mtx_tup_mul(t_tuple tp, t_mtx4 const m);
t_tuple		*mtx_tup_mul2(t_tuple *tp, t_mtx4 const m);
void		mtx_transpose(t_mtx4 m);
float		mtx2_determinant(t_mtx2 const m);
float		mtx3_determinant(t_mtx3 const m);
float		mtx4_determinant(t_mtx4 const m);

t_mtx3_ret	mtx4_submatrix(t_mtx4 const m, int row, int col, t_mtx3 sub);
t_mtx2_ret	mtx3_submatrix(t_mtx3 const m, int row, int col, t_mtx2 sub);

float		mtx3_minor(t_mtx3 const m, int row, int col);
float		mtx3_cofactor(t_mtx3 const m, int row, int col);

float		mtx4_minor(t_mtx4 const m, int row, int col);
float		mtx4_cofactor(t_mtx4 const m, int row, int col);

bool		mtx4_invertible(t_mtx4 const m);
int32_t		mtx4_inverse(t_mtx4 const m, t_mtx4 res);
t_mtx4_ret	mtx4_inverse2(t_mtx4 const m, t_mtx4 res);
t_mtx4_ret	mtx4_inverse3(t_mtx4 m);

t_mtx4_ret	translation(float x, float y, float z, t_mtx4 res);
t_tuple		tp_translation(float x, float y, float z, t_tuple tp);
t_mtx4_ret	mx_translation(float x, float y, float z, t_mtx4 res);


t_mtx4_ret	scaling(float x, float y, float z, t_mtx4 res);
t_tuple		tp_scaling(float x, float y, float z, t_tuple tp);
t_mtx4_ret	mx_scaling(float x, float y, float z, t_mtx4 res);


t_mtx4_ret	rotation_x(float r, t_mtx4 res);
t_mtx4_ret	rotation_y(float r, t_mtx4 res);
t_mtx4_ret	rotation_z(float r, t_mtx4 res);

t_tuple		tp_rotation_x(float r, t_tuple tp);
t_tuple		tp_rotation_y(float r, t_tuple tp);
t_tuple		tp_rotation_z(float r, t_tuple tp);

t_mtx4_ret	mx_rotation_x(float r, t_mtx4 res);
t_mtx4_ret	mx_rotation_y(float r, t_mtx4 res);
t_mtx4_ret	mx_rotation_z(float r, t_mtx4 res);

t_mtx4_ret	shearing(float const x[2], float const y[2], float const z[2],
						t_mtx4 res);
t_tuple		tp_shearing(float const x[2], float const y[2], float const z[2],
							t_tuple tp);
t_mtx4_ret	mx_shearing(float const x[2], float const y[2], float const z[2],
							t_mtx4 res);

#endif
