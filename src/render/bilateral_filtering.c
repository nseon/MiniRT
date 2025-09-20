/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilateral_filtering.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:57:36 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/20 16:57:36 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fcolors.h"
#include "world.h"
#include "minirt.h"

float	gaussian(float x, float o)
{
	return ((1 / (2 * M_PI) * o * o) * exp(-(x * x) / (2 * o * o)));
}

float	pix_dis(int32_t y, int32_t x, int32_t i, int32_t j)
{
	return (sqrt((y - i) * (y - i) + (x - j) * (x - j)));
}

float	col_dis(t_fcolor c1, t_fcolor c2)
{
	return (sqrt(pow(c1.r - c2.r, 2) + pow(c1.g - c2.g, 2)
		+ pow(c1.b - c2.b, 2)));
}

t_fcolor	filter_pixel(t_gctx *gctx, int32_t x, int32_t y)
{
	float		total_w;
	float		w;
	int32_t		i;
	int32_t		j;
	t_fcolor	col;

	col = fcolor(0, 0, 0);
	total_w = 0;
	i = -(gctx->bil_size - 1) / 2 - 1;
	while (++i < (gctx->bil_size - 1) / 2)
	{
		j = -(gctx->bil_size - 1) / 2 - 1;
		while (++j < (gctx->bil_size - 1) / 2)
		{
			if (y + i < 0 || x + j < 0 || y + i >= WIN_H || x + j >= WIN_W)
				continue ;
			w = gaussian(pix_dis(y, x, y + i, x + j), gctx->o_d);
			w *= gaussian(col_dis(gctx->frame[(y + i) * WIN_W + (x + j)],
				gctx->frame[(y) * WIN_W + (x)]), gctx->o_r);
			total_w += w;
			col = color_add(col, col_scalar2(gctx->frame[(y + i) * WIN_W +
				(x + j)], w));
		}
	}
	return (col_scalar(col, 1.0 / total_w));
}

void	bilateral_filter(t_gctx *gctx)
{
	int32_t		y;
	int32_t		x;
	t_fcolor	*buf;

	if (gctx->bil_passes >= gctx->bil_max)
		return ;
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			gctx->buf_frame[y * WIN_W + x] = filter_pixel(gctx, x, y);
		}
	}
	buf = gctx->frame;
	gctx->frame = gctx->buf_frame;
	gctx->buf_frame = buf;
	gctx->bil_passes++;
}