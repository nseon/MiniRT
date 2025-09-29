/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:15:25 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/11 10:11:41 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "image.h"
#include "minirt.h"
#include "parsing.h"

void	put_frame_to_img(t_image *img, t_fcolor *frame, int32_t frac)
{
	int32_t	x;
	int32_t	y;
	int32_t	i;
	int32_t	j;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = -1;
			while (++i < frac)
			{
				j = -1;
				while (++j < frac)
					put_pixel_img(img, point_s(x + j, y + i,
							fcolor_to_uint(frame[y * WIN_W + x])));
			}
			x += frac;
		}
		y += frac;
	}
}

void	main_loop(void *p)
{
	t_ctx *const	ctx = p;

	if (!ctx->parsing)
		draw_file_status(ctx);
	if (ctx->parsing)
	{
		printf("Samples: %d\n", ctx->gctx.ss.sample_num);
		if (ctx->gctx.w.gparam & RENDER)
			render(&ctx->gctx, &ctx->gctx.w);
		if ((ctx->gctx.w.gparam & DENOISE))
		{
			bilateral_filter(&ctx->gctx);
			put_frame_to_img(&ctx->img, ctx->gctx.buf_frame, ctx->gctx.frac);
		}
		else
			put_frame_to_img(&ctx->img, ctx->gctx.frame, ctx->gctx.frac);
	}
	put_img(&ctx->img, 0, 0, true);
}

void	end_main_loop(void *p)
{
	t_window *const	win = p;

	end_loop(win);
}
