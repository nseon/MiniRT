/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:25:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 16:25:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"
#include "ray.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	return ((t_ray){origin, direction});
}

t_tuple	position(t_ray ray, float t)
{
	return (tp_add(ray.origin, tp_mul(ray.dir, t)));
}


