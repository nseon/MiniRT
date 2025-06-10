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

static int8_t	init(t_ctx *const ctx)
{
	if (init_window(&ctx->win, WIN_W, WIN_H, "MiniRT") != SUCCESS)
		return (FATAL);
	if (create_image(&ctx->img, WIN_W, WIN_H, &ctx->win) != SUCCESS)
	{
		destroy_window(&ctx->win);
		return (FATAL);
	}
	return (SUCCESS);
}

int8_t	set_events(t_ctx *ctx)
{
	register_loop(ctx->win.events, main_loop, ctx);
	register_destroy(ctx->win.events, end_main_loop, &ctx->win);
	return (SUCCESS);
}

int	main(int c, char **args)
{
	t_camera	camera = {.pos = {0, 0, -500}, .orient = {0, 0, 1},
		.vp = {1920, 1080, 1200}};
	t_ctx		ctx;

	(void)c;
	(void)args;
	ctx = (t_ctx){0};
	if (init(&ctx) != SUCCESS)
		return (EXIT_FAILURE);
	set_events(&ctx);
	init_gui(&ctx);
	loop(&ctx.win);
	destroy_image(&ctx.img);
	destroy_window(&ctx.win);
	return (0);
}
