/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/22 11:58:01 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inputs.h"
#include "render.h"
#include "neflibx.h"
#include "inputs.h"

#include <unistd.h>

#include "mlx.h"

void	loop2(void *p)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)p;
	render(*ctx);
	put_img(&ctx->img, 0, 0, true);
}

void	btn1(void *p)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)p;
	if (ctx->lights_off)
		ctx->lights_off = false;
	else
		ctx->lights_off = true;
}

void	init_btn(t_window *win, t_image *img, t_ctx *ctx)
{
	t_guielem	btn;

	create_button(img, &btn, btn1, ctx);
	btn.x = 10;
	btn.y = 10;
	btn.w = 70;
	btn.h = 15;
	btn.label = "lights";
	btn.color = argb(0, 182, 190, 204);
	add_gui_elem(win, &btn);
}

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

int	main(int c, char **args)
{
	t_camera	camera = {.pos = {0, 0, 0}, .orient = {0, 0, 1},
		.vp = {960, 540, 700}};
	t_ctx		ctx;

	(void)c;
	(void)args;
	init_window(&ctx.win, 960, 540, "MiniRT");
	create_image(&ctx.img, 960, 540, &ctx.win);
	init_btn(&ctx.win, &ctx.img, &ctx);
	ctx.cam = camera;
	ctx.lights_off = false;
	ctx.spheres = vct_create(sizeof (t_sphere), 0, 0);
	ctx.lights = vct_create(sizeof (t_light), 0, 0);
	ctx.amb_light = (t_amb_light){0.05};
	// vct_add(&ctx.lights, &(t_light){POINT, {0, -2000, 200}, 0.7});
	// vct_add(&ctx.lights, &(t_light){POINT, {-1200, 0, 2400}, 1});
	vct_add(&ctx.lights, &(t_light){DIR, {-200, 100, 100}, 1});
	vct_add(&ctx.spheres, &(t_sphere){{0, 0, 2400}, 500, 255});
	vct_add(&ctx.spheres, &(t_sphere){{600, 400, 2600}, 500, 65280});
	vct_add(&ctx.spheres, &(t_sphere){{-1000, 400, 1700}, 500, 70280});
	vct_add(&ctx.spheres, &(t_sphere){{-600, -400, 2800}, 500, 16711680});
	render(ctx);
	register_keypress(ctx.win.events, move_cam, &ctx);
	register_destroy(ctx.win.events, end, &ctx.win);
	register_btnpress(ctx.win.events, move_wheel, &ctx);
	register_loop(ctx.win.events, loop2, &ctx);
	loop(&ctx.win);
	return (0);
}
