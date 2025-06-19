/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:16:30 by nseon             #+#    #+#             */
/*   Updated: 2025/06/19 10:43:52 by nseon            ###   ########.fr       */
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

void	add_rgb96_t(t_rgb96_t *comps, uint32_t color)
{
	t_color col;

	col.argb = color;
	comps->r += col.r; 
	comps->g += col.g; 
	comps->b += col.b; 
}

int32_t	get_mixed_color(t_rgb96_t comps, int div)
{
	t_color	color;

	color.r = comps.r / div;
	color.g = comps.g / div;
	color.b = comps.b / div;
	return (color.argb);
}
