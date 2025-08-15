/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/26 14:27:18 by nseon            ###   ########.fr       */
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

#include "mlx.h"
#include "parsing.h"

static int8_t	init(t_ctx *const ctx)
{
	if (init_window(&ctx->win, WIN_W, WIN_H, "MiniRT") != SUCCESS)
		return (FATAL);
	if (create_image(&ctx->img, WIN_W, WIN_H, &ctx->win) != SUCCESS)
	{
		destroy_window(&ctx->win);
		return (FATAL);
	}
	ctx->world.lights = vct_create(sizeof (t_light), 0, DESTROY_ON_FAIL);
	ctx->world.objs = vct_create(sizeof (t_obj), 0, DESTROY_ON_FAIL);
	return (SUCCESS);
}

int8_t	set_events(t_ctx *ctx)
{
	register_loop(ctx->win.events, main_loop, ctx);
	register_destroy(ctx->win.events, end_main_loop, &ctx->win);
	register_keypress(ctx->win.events, keyevent, ctx);
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
	free_vct(ctx.world.lights);
	free_vct(ctx.world.objs);
	return (0);
}
