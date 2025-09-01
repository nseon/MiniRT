/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:22:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/27 16:54:44 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

t_tuple	vector(double x, double y, double z);
t_tuple	point(double x, double y, double z);
bool	tp_equal(t_tuple tp1, t_tuple tp2);

double	tp_magnitude(t_tuple tp);
t_tuple	tp_add(t_tuple tp1, t_tuple tp2);
t_tuple	tp_sub(t_tuple tp1, t_tuple tp2);
t_tuple	tp_negate(t_tuple tp);
t_tuple	tp_mul(t_tuple tp, double k);
t_tuple	tp_normalize(t_tuple tp);
double	tp_dot(t_tuple tp1, t_tuple tp2);
t_tuple	tp_cross(t_tuple tp1, t_tuple tp2);
t_tuple	reflect(t_tuple in, t_tuple normal);
void	tp_invert(t_tuple *vec);

#endif
