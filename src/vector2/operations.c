/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:28:27 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/19 17:28:27 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector2.h"

float	v2_magnitude(t_vec2 vec)
{
	return (sqrtf(vec.x * vec.x + vec.y * vec.y));
}

t_vec2	get_vec2(t_point2 pt1, t_point2 pt2)
{
	return ((t_vec2){pt2.x - pt1.x, pt2.y - pt1.y});
}

t_vec2	v2_add(t_point2 pt1, t_point2 pt2)
{
	return ((t_vec2){pt1.x + pt2.x, pt1.y + pt2.y});
}
