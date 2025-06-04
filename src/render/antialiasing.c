/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:16:30 by nseon             #+#    #+#             */
/*   Updated: 2025/06/04 11:53:57 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "neflibx.h"
#include "render.h"

uint32_t	get_pixel_color(t_image *image, int x, int y)
{
	char *color;

	color = image->addr + y * image->len + x * (image->bpp / 8);
	return (*(uint32_t *)color);
}

float frandom(uint8_t const random[2 * RAY_NBR])
{
	static int	i;
	float		nb;

	if (i >= 2 * RAY_NBR)
		i = 0;
	nb = (float)(random[i]) / 256;
	i += 3;
	return (nb);
}

uint32_t		color_mix(uint32_t actual_color, uint32_t mix_color, uint32_t nb_mix)
{
	t_color 	old;
	t_color		mix;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	old.argb = actual_color;
	mix.argb = mix_color;
	r = (nb_mix * old.r + mix.r) * ((float)1 / (nb_mix + 1));
	if (r > 255)
		r = 255;
	g = (nb_mix * old.g + mix.g) * ((float)1 / (nb_mix + 1));
	if (g > 255)
		g = 255;
	b = (nb_mix * old.b + mix.b) * ((float)1 / (nb_mix + 1));
	if (b > 255)
		b = 255;
	return (r * 0x10000 + g * 0x100 + b);
}

uint32_t	supersampling(float old_color, float mix_color, uint32_t i)
{
	return (color_mix(old_color, mix_color, i));
}
