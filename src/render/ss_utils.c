/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:16:30 by nseon             #+#    #+#             */
/*   Updated: 2025/08/07 10:36:24 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "neflibx.h"
#include "render.h"

uint32_t	get_pixel_color(t_image *image, int x, int y)
{
	char *color;

	color = image->addr + y * image->len + x * (image->bpp / 8);
	return (*(uint32_t *)color);
}
/*!
 *
 * @return A random float between min & max.
 */
float frandom(uint8_t const random[RAY_NBR], int min, int max)
{
	static int	i;
	float		nb;

	if (i >= RAY_NBR)
		i = 0;
	nb = (float)(random[i]) / ((float)256 / (max - min));
	nb += min;
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

t_vec3	random_vec(uint8_t const random[RAY_NBR])
{
	return((t_vec3){frandom(random, -1, 1), frandom(random, -1, 1), frandom(random, -1, 1)});
}
