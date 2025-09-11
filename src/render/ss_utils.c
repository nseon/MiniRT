/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:16:30 by nseon             #+#    #+#             */
/*   Updated: 2025/09/09 16:31:00 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "errors.h"
#include "minirt.h"
#include "neflibx.h"
#include "render.h"

int32_t	init_ss(t_ctx *ctx)
{
	t_ss	ss;

	ss.color_px = malloc(sizeof (t_rgb96_t) * WIN_H * WIN_W);
	if (!ss.color_px)
		return (FATAL);
	ft_bzero(ss.color_px, sizeof (t_rgb96_t) * WIN_H * WIN_W);
	ss.rays = 0;
	ctx->gctx.ss = ss;
	return (SUCCESS);
}

uint32_t	get_pixel_color(t_image *image, int x, int y)
{
	char *color;

	color = image->addr + y * image->len + x * (image->bpp / 8);
	return (*(uint32_t *)color);
}

void	clear_ss(t_ss *ss)
{
	ft_bzero(ss->color_px, sizeof (t_rgb96_t) * WIN_H * WIN_W);
	ss->rays = 0;
}

void	add_rgb96_t(t_ss *ss, t_fcolor color, int32_t x, int32_t y)
{
	t_color col;

	col.argb = fcolor_to_uint(color);
	ss->color_px[x * WIN_H + y].r += col.r;
	ss->color_px[x * WIN_H + y].g += col.g;
	ss->color_px[x * WIN_H + y].b += col.b;
}

int32_t	get_mixed_color(t_ss *ss, int32_t x, int32_t y)
{
	t_color		color;
	t_rgb96_t	col96;

	col96 = ss->color_px[x * WIN_H + y];
	color.r = col96.r / ss->rays;
	color.g = col96.g / ss->rays;
	color.b = col96.b / ss->rays;
	return (color.argb);
}
