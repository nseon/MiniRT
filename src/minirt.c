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

#include "inputs.h"
#include "render.h"
#include "minirt.h"
#include "neflibx.h"
#include "errors.h"
#include "hooks.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "mlx.h"
#include "parsing.h"

static int8_t	init(t_ctx *const ctx)
{
	int32_t fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (FATAL);
	if (read(fd, ctx->random, RAY_NBR) == -1)
		return (FATAL);
	ctx->gctx.color_px = malloc(sizeof (t_rgb96_t) * WIN_H * WIN_W);
	if (!ctx->gctx.color_px)
		return (FATAL);
	ft_bzero(ctx->gctx.color_px, sizeof (t_rgb96_t) * WIN_H * WIN_W);
	if (init_window(&ctx->win, WIN_W, WIN_H, "MiniRT") != SUCCESS)
		return (FATAL);
	if (create_image(&ctx->img, WIN_W, WIN_H, &ctx->win) != SUCCESS)
	{
		destroy_window(&ctx->win);
		return (FATAL);
	}
	world(&ctx->gctx.w);
	return (SUCCESS);
}

int8_t	set_events(t_ctx *ctx)
{
	register_loop(ctx->win.events, main_loop, ctx);
	register_destroy(ctx->win.events, end_main_loop, &ctx->win);
	register_keypress(ctx->win.events, cam_translation, ctx);
	register_keypress(ctx->win.events, cam_height, ctx);
	register_keypress(ctx->win.events, authorize_cam_move, ctx);
	register_keypress(ctx->win.events, window_unfocus, ctx);
	register_pointer(ctx->win.events, rotate_cam, ctx);
	register_btnpress(ctx->win.events, window_focus, ctx);
	return (SUCCESS);
}

int	main(int c, char **args)
{
	t_ctx		ctx;

	ctx = (t_ctx){0};
	if (init(&ctx) != SUCCESS)
		return (EXIT_FAILURE);
	set_events(&ctx);
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
	free_world(&ctx.gctx.w);
	return (0);
}
