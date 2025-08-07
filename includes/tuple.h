/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:22:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/19 17:22:16 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

t_tuple	vector(float x, float y, float z);
t_tuple	point(float x, float y, float z);
bool	tp_equal(t_tuple tp1, t_tuple tp2);

float	tp_magnitude(t_tuple tp);
t_tuple	tp_add(t_tuple tp1, t_tuple tp2);
t_tuple	tp_sub(t_tuple tp1, t_tuple tp2);
t_tuple	tp_negate(t_tuple tp);
t_tuple	tp_mul(t_tuple tp, float k);
t_tuple	tp_normalize(t_tuple tp);
float	tp_dot(t_tuple tp1, t_tuple tp2);
t_tuple	tp_cross(t_tuple tp1, t_tuple tp2);

#endif
