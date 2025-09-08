/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:15:25 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/08 15:13:30 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "minirt.h"
#include "parsing.h"

void	main_loop(void *p)
{
	t_ctx *const	ctx = p;
	static int32_t	rays;
	bool			test;

	
	test = 0;
	if (!ctx->parsing)
		draw_file_status(ctx);
	if (!ctx->render && ctx->parsing)
	{
		ft_bzero(ctx->gctx.color_px, sizeof (t_rgb96_t) * WIN_H * WIN_W);
		render(ctx, ctx->gctx.cam, &ctx->gctx.w, -1);
		rays = 0;
	}
	else if (ctx->parsing && ++rays < RAY_NBR)
	{
		render(ctx, ctx->gctx.cam, &ctx->gctx.w, rays);
	}
	put_img(&ctx->img, 0, 0, true);
}

void	end_main_loop(void *p)
{
	t_window *const	win = p;

	end_loop(win);
}
