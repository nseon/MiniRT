/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:59:02 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/08 09:02:37 by nseon            ###   ########.fr       */
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
t_mtx4_ret	mtx_transpose2(t_mtx4 const m, t_mtx4 res);
double		mtx2_determinant(t_mtx2 const m);
double		mtx3_determinant(t_mtx3 const m);
double		mtx4_determinant(t_mtx4 const m);

t_mtx3_ret	mtx4_submatrix(t_mtx4 const m, int row, int col, t_mtx3 sub);
t_mtx2_ret	mtx3_submatrix(t_mtx3 const m, int row, int col, t_mtx2 sub);

double		mtx3_minor(t_mtx3 const m, int row, int col);
double		mtx3_cofactor(t_mtx3 const m, int row, int col);

double		mtx4_minor(t_mtx4 const m, int row, int col);
double		mtx4_cofactor(t_mtx4 const m, int row, int col);

bool		mtx4_invertible(t_mtx4 const m);
int32_t		mtx4_inverse(t_mtx4 const m, t_mtx4 res);
t_mtx4_ret	mtx4_inverse2(t_mtx4 const m, t_mtx4 res);
t_mtx4_ret	mtx4_inverse3(t_mtx4 m);

t_mtx4_ret	translation(double x, double y, double z, t_mtx4 res);
t_tuple		tp_translation(double x, double y, double z, t_tuple tp);
t_mtx4_ret	mx_translation(double x, double y, double z, t_mtx4 res);

t_mtx4_ret	scaling(double x, double y, double z, t_mtx4 res);
t_tuple		tp_scaling(double x, double y, double z, t_tuple tp);
t_mtx4_ret	mx_scaling(double x, double y, double z, t_mtx4 res);

t_mtx4_ret	rotation_x(double r, t_mtx4 res);
t_mtx4_ret	rotation_y(double r, t_mtx4 res);
t_mtx4_ret	rotation_z(double r, t_mtx4 res);

t_tuple		tp_rotation_x(double r, t_tuple tp);
t_tuple		tp_rotation_y(double r, t_tuple tp);
t_tuple		tp_rotation_z(double r, t_tuple tp);

t_mtx4_ret	mx_rotation_x(double r, t_mtx4 res);
t_mtx4_ret	mx_rotation_y(double r, t_mtx4 res);
t_mtx4_ret	mx_rotation_z(double r, t_mtx4 res);

t_mtx4_ret	shearing(double const x[2], double const y[2], double const z[2],
				t_mtx4 res);
t_tuple		tp_shearing(double const x[2], double const y[2], double const z[2],
				t_tuple tp);
t_mtx4_ret	mx_shearing(double const x[2], double const y[2], double const z[2],
				t_mtx4 res);

t_mtx4_ret	mtx4_view(t_tuple from, t_tuple to, t_tuple up, t_mtx4 res);
t_mtx4_ret	mtx4_scale(t_mtx4 m1, float const m);

t_mtx4_ret	rotation_axis(double r, t_tuple u, t_mtx4 res);

#endif
