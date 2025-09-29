/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/08 15:19:06 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"
#include "hooks.h"
#include "inputs.h"
#include "neflibx.h"
#include "parsing.h"
#include "random.h"
#include "render.h"

#include <stdlib.h>

static int32_t	free_on_fatal(t_ctx *const ctx, int32_t index_fatal)
{
	if (index_fatal >= 1)
		free(ctx->gctx.frame);
	if (index_fatal >= 2)
		free(ctx->gctx.buf_frame);
	if (index_fatal >= 4)
		free(ctx->gctx.ss.samples);
	if (index_fatal >= 5)
		destroy_window(&ctx->win);
	if (index_fatal >= 6)
		destroy_image(&ctx->img);
	return (FATAL);
}

static int8_t	init(t_ctx *const ctx)
{
	ctx->gctx.frac = 1;
	ctx->gctx.bil_size = 5;
	ctx->gctx.o_d = 8;
	ctx->gctx.o_r = 0.08;
	ctx->gctx.frame = malloc(sizeof (t_fcolor) * WIN_H * WIN_W);
	if (!ctx->gctx.frame)
		return (free_on_fatal(ctx, 0));
	ctx->gctx.buf_frame = malloc(sizeof (t_fcolor) * WIN_H * WIN_W);
	if (!ctx->gctx.buf_frame)
		return (free_on_fatal(ctx, 1));
	if (init_random() != SUCCESS)
		return (free_on_fatal(ctx, 2));
	if (init_ss(&ctx->gctx, 200) != SUCCESS)
		return (free_on_fatal(ctx, 3));
	if (init_window(&ctx->win, WIN_W, WIN_H, "MiniRT") != SUCCESS)
		return (free_on_fatal(ctx, 4));
	if (create_image(&ctx->img, WIN_W, WIN_H, &ctx->win) != SUCCESS)
		return (free_on_fatal(ctx, 5));
	if (world(&ctx->gctx.w) != SUCCESS)
		return (free_on_fatal(ctx, 6));
	return (SUCCESS);
}

int8_t	set_events(t_ctx *ctx)
{

	register_keypress(ctx->win.events, cam_translation, ctx);
	register_keypress(ctx->win.events, cam_height, ctx);
	register_keypress(ctx->win.events, gui_keys, ctx);
	register_keypress(ctx->win.events, authorize_cam_move, ctx);
	register_pointer(ctx->win.events, rotate_cam, ctx);
	return (SUCCESS);
}

int	main(int c, char **args)
{
	t_ctx		ctx;

	ctx = (t_ctx){0};
	if (init(&ctx) != SUCCESS)
		return (EXIT_FAILURE);
	register_loop(ctx.win.events, main_loop, &ctx);
	register_destroy(ctx.win.events, end_main_loop, &ctx.win);
	init_gui(&ctx);
	draw_background(&ctx.img, BACK_COLOR);
	if (c == 2)
	{
		put_img(&ctx.img, 0, 0, true);
		parse(args[1], &ctx);
	}
	loop(&ctx.win);
	destroy_image(&ctx.img);
	destroy_window(&ctx.win);
	free(ctx.gctx.ss.samples);
	free(ctx.gctx.frame);
	free(ctx.gctx.buf_frame);
	free_world(&ctx.gctx.w);
	return (0);
}
