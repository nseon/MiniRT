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
	ctx->gctx.color_px = malloc(sizeof (t_rgb96_t) * WIN_H * WIN_W);
	if (!ctx->gctx.color_px)
		return (FATAL);
	ft_bzero(ctx->gctx.color_px, sizeof (t_rgb96_t) * WIN_H * WIN_W);
	return (SUCCESS);
}

uint32_t	get_pixel_color(t_image *image, int x, int y)
{
	char *color;

	color = image->addr + y * image->len + x * (image->bpp / 8);
	return (*(uint32_t *)color);
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
