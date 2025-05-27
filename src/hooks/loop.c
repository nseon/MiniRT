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

#include <stdio.h>

#include "minirt.h"
#include "parsing.h"

void	main_loop(void *p)
{
	t_ctx *const	ctx = p;

	printf("Rendering\n");
	if (!ctx->parsing)
	{
		parse(ctx);
	}
	else if (ctx->render)
	{
		render(ctx->gctx, &ctx->img);
	}
	put_img(&ctx->img, 0, 0, true);
}

void	end_main_loop(void *p)
{
	t_window *const	win = p;

	end_loop(win);
}
