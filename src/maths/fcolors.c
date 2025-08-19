/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:36:29 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/29 08:36:29 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcolors.h"

t_fcolor	fcolor(float r, float g, float b)
{
	return ((t_fcolor){r, g, b});
}

t_fcolor	color_add(t_fcolor c1, t_fcolor c2)
{
	return ((t_fcolor){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b});
}

t_fcolor	color_sub(t_fcolor c1, t_fcolor c2)
{
	return ((t_fcolor){c1.r - c2.r, c1.g - c2.g, c1.b - c2.b});
}

t_fcolor	color_scalar(t_fcolor c1, double k)
{
	return ((t_fcolor){c1.r * k, c1.g * k, c1.b * k});
}

t_fcolor	color_mul(t_fcolor c1, t_fcolor c2)
{
	return ((t_fcolor){c1.r * c2.r, c1.g * c2.g, c1.b * c2.b});
}

uint32_t	fcolor_to_uint(t_fcolor col)
{
	uint32_t	res;
	double		buf;

	res = 0;
	buf = col.r * 256 - 0.5;
	if (buf > 255)
		res += 0xFF0000;
	else
		res += (uint8_t)buf << 16;
	buf = col.g * 256 - 0.5;
	if (buf > 255)
		res += 0xFF00;
	else
		res += (uint8_t)buf << 8;
	buf = col.b * 256 - 0.5;
	if (buf > 255)
		res += 0xFF;
	else
		res += (uint8_t)buf;
	return (res);
}
