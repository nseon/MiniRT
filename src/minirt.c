/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/22 17:36:22 by nseon            ###   ########.fr       */
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
	put_img(&ctx->img, 0, 0);
	mlx_do_sync(ctx->win.mlx);
}

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

int	main(int c, char **args)
{
	t_camera	camera = {.pos = {0, 0, 0}, .orient = {0, 0, 1},
		.vp = {1920, 1080, 2000}};
	t_ctx		ctx;

	(void)c;
	(void)args;
	ctx = (t_ctx){0};
	init_window(&ctx.win, 1920, 1080, "MiniRT");
	create_image(&ctx.img, 1920, 1080, &ctx.win);
	ctx.cam = camera;
	ctx.spheres = vct_create(sizeof(t_sphere), 0, 0);
	vct_add(&ctx.spheres, &(t_sphere){{0, 0, 2400}, 500, 255});
	vct_add(&ctx.spheres, &(t_sphere){{600, 400, 2600}, 500, 65280});
	vct_add(&ctx.spheres, &(t_sphere){{-600, -400, 2800}, 500, 16711680});
	render(ctx);
	put_img(&ctx.img, 0, 0);
	register_keypress(ctx.win.events, move_cam, &ctx);
	register_destroy(ctx.win.events, end, &ctx.win);
	register_btnpress(ctx.win.events, move_wheel, &ctx);
	register_btnpress(ctx.win.events, mouse_click, &ctx.mouse);
	register_btnrelease(ctx.win.events, mouse_unclick, &ctx.mouse);
	register_pointer(ctx.win.events, mouse_move,&ctx);
	register_loop(ctx.win.events, loop2, &ctx);
	loop(&ctx.win);
	return (0);
}
