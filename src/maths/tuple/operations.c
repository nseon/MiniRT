/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:26:09 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/19 17:26:09 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "rt_maths.h"
#include "tuple.h"

double	tp_magnitude(t_tuple tp)
{
	return (sqrtf(tp.x * tp.x + tp.y * tp.y + tp.z * tp.z + tp.w * tp.w));
}

t_tuple	tp_negate(t_tuple tp)
{
	return ((t_tuple){tp.x * -1, tp.y * -1, tp.z * -1, tp.w * -1});
}

t_tuple	tp_add(t_tuple tp1, t_tuple tp2)
{
	return ((t_tuple){tp1.x + tp2.x, tp1.y + tp2.y,
		tp1.z + tp2.z, tp1.w + tp2.w});
}

t_tuple	tp_sub(t_tuple tp1, t_tuple tp2)
{
	return ((t_tuple){tp1.x - tp2.x, tp1.y - tp2.y,
		tp1.z - tp2.z, tp1.w - tp2.w});
}

bool	tp_equal(t_tuple tp1, t_tuple tp2)
{
	if (f_equal(tp1.x, tp2.x) && f_equal(tp1.y, tp2.y)
		&& f_equal(tp1.z, tp2.z) && tp1.w == tp2.w)
		return (true);
	return (false);
}
