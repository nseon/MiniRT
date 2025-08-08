/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:42 by nseon             #+#    #+#             */
/*   Updated: 2025/08/06 11:02:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

#include <math.h>

/*!
 *
 * @return Distance between the points A & B.
 */
float	get_distance(t_point3 a, t_point3 b)
{
	return (sqrtf(((b.x - a.x) * (b.x - a.x))
			+ ((b.y - a.y) * (b.y - a.y))
			+ ((b.z - a.z) * (b.z - a.z))));
}
