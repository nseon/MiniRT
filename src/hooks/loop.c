/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:15:25 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 12:15:25 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

void	main_loop(void *p)
{
	t_ctx *const	ctx = p;

	if (!ctx->parsing)
		draw_file_status(ctx);
	if (ctx->parsing)
	{
		render(&ctx->gctx, &ctx->img);
	}
	put_img(&ctx->img, 0, 0, true);
}

void	end_main_loop(void *p)
{
	t_window *const	win = p;

	end_loop(win);
}
