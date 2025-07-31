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

typedef float				t_matrix_4x4[4][4];
typedef float				t_matrix_3x3[3][3];
typedef float				t_matrix_2x2[2][2];

extern const t_matrix_4x4	g_identity_matrix;

bool	matrix_equal(t_matrix_4x4 const m1, t_matrix_4x4 const m2);
void	matrix_mul(t_matrix_4x4 const m1, t_matrix_4x4 const m2,
	t_matrix_4x4 res);
t_tuple	matrix_tup_mul(t_tuple tp, t_matrix_4x4 const m);

#endif
