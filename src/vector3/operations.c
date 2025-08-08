/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:26:09 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 10:00:47 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector3.h"
#include "render.h"

float	v3_magnitude(t_vec3 vec)
{
	return (sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3	get_vec3(t_point3 pt1, t_point3 pt2)
{
	return ((t_vec3){pt2.x - pt1.x, pt2.y - pt1.y, pt2.z - pt1.z});
}

t_vec3	v3_add(t_point3 pt1, t_point3 pt2)
{
	return ((t_vec3){pt1.x + pt2.x, pt1.y + pt2.y, pt1.z + pt2.z});
}

t_vec3	v3_sub(t_point3 pt1, t_point3 pt2)
{
	return ((t_vec3){pt1.x - pt2.x, pt1.y - pt2.y, pt1.z - pt2.z});
}

void	v3_invert(t_vec3 *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
}
