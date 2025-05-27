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

void	btn1(void *p)
{
	t_graphic_ctx	*gctx;

	gctx = (t_graphic_ctx *)p;
	if (gctx->lights_off)
		gctx->lights_off = false;
	else
		gctx->lights_off = true;
}

void	init_btn(t_window *win, t_image *img, t_ctx *ctx)
{
	t_guielem	btn;

	create_button(img, &btn, btn1, &ctx->gctx);
	btn.x = 10;
	btn.y = 10;
	btn.w = 70;
	btn.h = 15;
	btn.label = "lights";
	btn.color = argb(0, 182, 190, 204).argb;
	add_gui_elem(win, &btn);
}

static int8_t	init(t_ctx *const ctx)
{
	if (init_window(&ctx->win, 960, 540, "MiniRT") != SUCCESS)
		return (FATAL);
	if (create_image(&ctx->img, 960, 540, &ctx->win) != SUCCESS)
	{
		destroy_window(&ctx->win);
		return (FATAL);
	}
	return (SUCCESS);
}

int8_t	set_events(t_ctx *ctx)
{
	register_loop(ctx->win.events, main_loop, &ctx);
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
	loop(&ctx.win);
	free_vct(ctx.gctx.lights);
	free_vct(ctx.gctx.objs);
	return (0);
}
