/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/23 16:04:26 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inputs.h"
#include "render.h"
#include "minirt.h"
#include "neflibx.h"

#include <unistd.h>

#include "mlx.h"

void	loop2(void *p)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)p;
	render(ctx->gctx, &ctx->img);
	put_img(&ctx->img, 0, 0, true);
}

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

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

int	main(int c, char **args)
{
	t_camera	camera = {.pos = {0, 0, -500}, .orient = {0, 0, 1},
		.vp = {1920, 1080, 2000}};
	t_ctx		ctx;

	(void)c;
	(void)args;
	init_window(&ctx.win, 960, 540, "MiniRT");
	create_image(&ctx.img, 960, 540, &ctx.win);
	init_btn(&ctx.win, &ctx.img, &ctx);
	ctx.gctx.cam = camera;
	ctx.gctx.lights_off = false;
	ctx.gctx.spheres = vct_create(sizeof (t_sphere), 0, 0);
	ctx.gctx.lights = vct_create(sizeof (t_light), 0, 0);
	ctx.gctx.amb_light = (t_amb_light){0.2};
	vct_add(&ctx.gctx.lights, &(t_light){POINT, {0, -2000, 200}, 0.7});
	vct_add(&ctx.gctx.lights, &(t_light){POINT, {-1200, 0, 2400}, 0.3});
	// vct_add(&ctx.lights, &(t_light){DIR, {200, 100, 100}, 1});
	vct_add(&ctx.gctx.spheres, &(t_sphere){{0, 0, 2400}, 500, 255, -1});
	vct_add(&ctx.gctx.spheres, &(t_sphere){{600, 400, 2600}, 500, 65380, -1});
	vct_add(&ctx.gctx.spheres, &(t_sphere){{-600, -400, 2800}, 500, 16711680, -1});
	vct_add(&ctx.gctx.spheres, &(t_sphere){{0, 11600, 2800}, 11000, 0xd9d77e, -1});
	render(ctx.gctx, &ctx.img);
	register_keypress(ctx.win.events, move_cam, &ctx.gctx);
	register_destroy(ctx.win.events, end, &ctx.win);
	register_btnpress(ctx.win.events, move_wheel, &ctx.gctx);
	register_btnpress(ctx.win.events, mouse_click, &ctx.mouse);
	register_btnrelease(ctx.win.events, mouse_unclick, &ctx.mouse);
	register_pointer(ctx.win.events, mouse_move,&ctx);
	register_loop(ctx.win.events, loop2, &ctx);
	loop(&ctx.win);
	return (0);
}
