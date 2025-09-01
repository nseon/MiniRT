/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplications.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:20:07 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/27 16:54:35 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	tp_mul(t_tuple tp, double k)
{
	return ((t_tuple){tp.x * k, tp.y * k, tp.z * k, tp.w * k});
}

t_tuple	tp_normalize(t_tuple tp)
{
	return (tp_mul(tp, 1 / tp_magnitude(tp)));
}

double	tp_dot(t_tuple p1, t_tuple p2)
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z + p1.w * p2.w);
}

t_tuple	tp_cross(t_tuple tp1, t_tuple tp2)
{
	return ((t_tuple){tp1.y * tp2.z - tp1.z * tp2.y,
		tp1.z * tp2.x - tp1.x * tp2.z,
		tp1.x * tp2.y - tp1.y * tp2.x,
		0});
}

void	tp_invert(t_tuple *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
}
