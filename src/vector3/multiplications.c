/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplications.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:20:07 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/19 18:20:07 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vec3	v3_multiply(t_vec3 vec, float k)
{
	return ((t_vec3){vec.x * k, vec.y * k, vec.z * k});
}

t_vec3	v3_normalize(t_vec3 vec)
{
	return (v3_multiply(vec, 1 / v3_magnitude(vec)));
}

float	v3_dotproduct(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3	v3_crossproduct(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.y * v2.z - v1.z * v2.y,
		v1.x * v2.z - v1.z * v2.x,
		v1.x * v2.y - v1.y * v2.x});
}
