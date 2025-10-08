/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:46 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/18 15:23:15 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <neflibx.h>
#include <math.h>

t_color	argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return ((t_color){.b = b, .g = g, .r = r, .a = a});
}

uint32_t	colorx(int32_t color, float m)
{
	t_color		ncolor;
	uint32_t	rgb;

	ncolor.argb = color;
	rgb = ncolor.r * m;
	if (rgb > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb;
	rgb = ncolor.g * m;
	if (rgb > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb;
	rgb = ncolor.b * m;
	if (rgb > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb;
	return (ncolor.argb);
}

uint32_t	colorx64(int64_t color, float m)
{
	t_color		ncolor;
	t_color64	ncolor64;
	uint32_t	rgb;

	ncolor64.argb = color;
	rgb = ncolor64.r * m;
	if (rgb > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb;
	rgb = ncolor64.g * m;
	if (rgb > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb;
	rgb = ncolor64.b * m;
	if (rgb > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb;
	return (ncolor.argb);
}

uint32_t	colorp(uint32_t color, uint32_t color2)
{
	t_color		ncolor;
	t_color		ncolor2;
	uint32_t	rgb;

	ncolor.argb = color;
	ncolor2.argb = color2;
	rgb = ncolor.r + ncolor2.r;
	if (rgb > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb;
	rgb = ncolor.g + ncolor2.g;
	if (rgb > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb;
	rgb = ncolor.b + ncolor2.b;
	if (rgb > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb;
	return (ncolor.argb);
}

uint32_t	color_mix(uint32_t color, uint32_t mix_color, uint32_t nb_mix)
{
	t_color			old;
	t_color const	mix = (t_color)mix_color;
	uint32_t		rgb;
	float const		mix_mul = (float)1 / (nb_mix + 1);

	old.argb = color;
	rgb = (nb_mix * old.r + mix.r) * mix_mul;
	if (rgb > 255)
		old.r = 255;
	else
		old.r = rgb;
	rgb = (nb_mix * old.g + mix.g) * mix_mul;
	if (rgb > 255)
		old.g = 255;
	else
		old.g = rgb;
	rgb = (nb_mix * old.b + mix.b) * mix_mul;
	if (rgb > 255)
		old.b = 255;
	else
		old.b = rgb;
	return (old.argb);
}
