/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:16:30 by nseon             #+#    #+#             */
/*   Updated: 2025/09/09 10:20:35 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "errors.h"
#include "minirt.h"
#include "neflibx.h"
#include "render.h"

int32_t	init_ss(t_ctx *ctx)
{
	ctx->gctx.color_px = malloc(sizeof (t_fcolor) * WIN_H * WIN_W);
	if (!ctx->gctx.color_px)
		return (FATAL);
	ft_bzero(ctx->gctx.color_px, sizeof (t_fcolor) * WIN_H * WIN_W);
	return (SUCCESS);
}

uint32_t	get_pixel_color(t_image *image, int x, int y)
{
	char *color;

	color = image->addr + y * image->len + x * (image->bpp / 8);
	return (*(uint32_t *)color);
}

