/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/28 13:37:37 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inputs.h"
#include "render.h"
#include "minirt.h"
#include "neflibx.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "mlx.h"

void	loop2(void *p)
{
	t_ctx		*ctx;
	static int	ray;

	ctx = (t_ctx *)p;
	// if (ctx->gctx.lights[0].pos.x > -400)
	// ctx->gctx.lights[0].pos.x -= 20;
	// usleep(1000);
	if (ray < RAY_NBR || ctx->render == true)
	{
		if (ctx->render)
		{
			ray = 0;
			ft_bzero(ctx->gctx.color_px, W_WIDTH * W_HEIGHT * sizeof(t_rgb96_t));
		}
		render(ctx->gctx, &ctx->img, ctx->random, ray);
		put_img(&ctx->img, 0, 0, true);
		ctx->render = false;
	}
	ray++;
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

void	init_btn(t_image *img, t_ctx *ctx)
{
	t_guielem	btn;

	create_button(img, &btn, btn1, &ctx->gctx);
	btn.x = 10;
	btn.y = 10;
	btn.w = 70;
	btn.h = 15;
	btn.label = "lights";
	btn.color = argb(0, 182, 190, 204).argb;
	add_gui_elem(&btn);
}

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

int	main(int c, char **args)
{
	t_camera	camera = {.pos = {0, 0, -500}, .orient = {0, 0, 1},
		.vp = {1920, 1080, 1200}};
	t_ctx		ctx;

	(void)c;
	(void)args;
	init_window(&ctx.win, W_WIDTH, W_HEIGHT, "MiniRT");
	create_image(&ctx.img, W_WIDTH, W_HEIGHT, &ctx.win);
	init_btn( &ctx.img, &ctx);
	ctx.fd = open("/dev/urandom", O_RDONLY);
	read(ctx.fd, &ctx.random, 2 * RAY_NBR);
	ctx.render = false;
	ctx.gctx.cam = camera;
	ctx.gctx.lights_off = false;
	ctx.gctx.color_px= malloc(W_WIDTH * W_HEIGHT * sizeof(t_rgb96_t));
	ft_bzero(ctx.gctx.color_px, W_WIDTH * W_HEIGHT * sizeof(t_rgb96_t));
	ctx.gctx.spheres = vct_create(sizeof (t_sphere), 0, 0);
	ctx.gctx.lights = vct_create(sizeof (t_light), 0, 0);
	ctx.gctx.amb_light = (t_amb_light){0.12};
	vct_add(&ctx.gctx.lights, &(t_light){POINT, {-500, -500, -2000}, 0.6});
	vct_add(&ctx.gctx.lights, &(t_light){DIR, {2000, 300, 0}, 0.6});
	// vct_add(&ctx.lights, &(t_light){DIR, {200, 100, 100}, 1});
	vct_add(&ctx.gctx.spheres, &(t_sphere){{0, 0, 2400}, 500, 255, 20, 0});
	vct_add(&ctx.gctx.spheres, &(t_sphere){{600, 400, 2600}, 500, 65380, 20, 0});
	vct_add(&ctx.gctx.spheres, &(t_sphere){{-600, -400, 2800}, 500, 16711680, 20, 0});
	vct_add(&ctx.gctx.spheres, &(t_sphere){{0, 11600, 2800}, 11000, 0xd9d77e, -1, 0});
	// vct_add(&ctx.gctx.spheres, &(t_sphere){{-2500, -1500, 3000}, 1500, 16711680, -1, 0});
	register_keypress(ctx.win.events, move_cam, &ctx);
	register_keyrelease(ctx.win.events, release, &ctx);
	register_destroy(ctx.win.events, end, &ctx.win);
	register_btnpress(ctx.win.events, move_wheel, &ctx.gctx);
	register_btnpress(ctx.win.events, mouse_click, &ctx);
	register_btnrelease(ctx.win.events, mouse_unclick, &ctx.mouse);
	register_loop(ctx.win.events, loop2, &ctx);
	loop(&ctx.win);
	close(ctx.fd);
	return (0);
}
