/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:50:20 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/24 16:50:20 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_maths.h"

static double	dabs(double n)
{
	if (n > 0)
		return (n);
	return (-n);
}

bool	d_equal(double a, double b)
{
	return (dabs(a - b) < DEPSILON);
}

bool	f_equal(float a, float b)
{
	return (fabs(a - b) < EPSILON);
}
