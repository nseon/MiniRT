/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:15:25 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/08 21:43:47 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

void	main_loop(void *p)
{
	t_ctx *const	ctx = p;
	static int	ray;

	if (ctx->gctx.global_il)
	{
		ft_bzero(ctx->gctx.color_px, sizeof (t_rgb96_t) * WIN_H * WIN_W);
		ray = 0;
	}
	if (!ctx->parsing)
		draw_file_status(ctx);
	if (ctx->parsing)
	{
		if (ray < RAY_NBR || ctx->render == true)
		{
			if (ctx->render)
			{
				ray = 0;
				ft_bzero(ctx->gctx.color_px, WIN_W * WIN_H * sizeof(t_rgb96_t));
			}
			render(&ctx->gctx, &ctx->img, ctx->random, ray);
			ctx->render = false;
		}
		ray++;
	}
	put_img(&ctx->img, 0, 0, true);
}

void	end_main_loop(void *p)
{
	t_window *const	win = p;

	end_loop(win);
}
