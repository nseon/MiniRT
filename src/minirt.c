/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/07 10:26:39 by nseon            ###   ########.fr       */
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

#include "rt_gui.h"

static int32_t	free_init(t_ctx *const ctx, int32_t index_fatal)
{
	if (index_fatal >= 7)
		free_world(&ctx->gctx.w);
	if (index_fatal >= 6)
		destroy_image(&ctx->img);
	if (index_fatal >= 5)
		destroy_window(&ctx->win);
	if (index_fatal >= 4)
		free(ctx->gctx.ss.samples);
	if (index_fatal >= 2)
		free(ctx->gctx.buf_frame);
	if (index_fatal >= 1)
		free(ctx->gctx.frame);
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
		return (free_init(ctx, 0));
	ctx->gctx.buf_frame = malloc(sizeof (t_fcolor) * WIN_H * WIN_W);
	if (!ctx->gctx.buf_frame)
		return (free_init(ctx, 1));
	if (init_random() != SUCCESS)
		return (free_init(ctx, 2));
	if (init_ss(&ctx->gctx, 70) != SUCCESS)
		return (free_init(ctx, 3));
	if (init_window(&ctx->win, WIN_W, WIN_H, "MiniRT") != SUCCESS)
		return (free_init(ctx, 4));
	if (create_image(&ctx->img, WIN_W, WIN_H, &ctx->win) != SUCCESS)
		return (free_init(ctx, 5));
	if (world(&ctx->gctx.w) != SUCCESS)
		return (free_init(ctx, 6));
	return (SUCCESS);
}

int8_t	set_events(t_ctx *ctx)
{
	register_keypress(ctx->win.events, cam_translation, ctx);
	register_keypress(ctx->win.events, cam_height, ctx);
	register_keypress(ctx->win.events, gui_keys, ctx);
	register_keypress(ctx->win.events, authorize_cam_move, ctx);
	register_pointer(ctx->win.events, rotate_cam, ctx);
	register_btnpress(ctx->win.events, object_click, ctx);
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
	free_init(&ctx, 7);
	return (0);
}
