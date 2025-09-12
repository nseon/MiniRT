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

#include "image.h"
#include "minirt.h"
#include "parsing.h"

void	put_frame_to_img(t_image *img, t_fcolor *frame)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			put_pixel_img(img, point_s(x, y,
				fcolor_to_uint(frame[y * WIN_W + x])));
		}
	}
}

void	main_loop(void *p)
{
	t_ctx *const	ctx = p;
	static int32_t	rays;

	if (!ctx->parsing)
		draw_file_status(ctx);
	if (ctx->parsing)
	{
		render(&ctx->gctx, &ctx->gctx.w);
		put_frame_to_img(&ctx->img, ctx->gctx.frame);
	}
	put_img(&ctx->img, 0, 0, true);
}

void	end_main_loop(void *p)
{
	t_window *const	win = p;

	end_loop(win);
}
