/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplications.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:40:04 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/20 14:40:04 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

t_vec2	v2_multiply(t_vec2 vec, float k)
{
	return ((t_vec2){vec.x * k, vec.y * k});
}

t_vec2	v2_normalize(t_vec2 vec)
{
	return (v2_multiply(vec, 1 / v2_magnitude(vec)));
}

float	v2_dotproduct(t_vec2 v1, t_vec2 v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}
