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
	put_img(&ctx->img, 0, 0);
	// mlx_do_sync(ctx->win.mlx);
}

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

void create_spheres(t_sphere **spheres)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 38)
	{
		y = -1;
		while (++y < 21)
		{
			vct_add(spheres, &(t_sphere){{x * 100, y * 100, 1000}, 100});
		}
	}
}

int	main(int c, char **args)
{
	t_camera	camera = {.pos = {3840 / 2, 2160 / 2, 0}, .orient = {0, 0, 1},
		.vp = {3840, 2160, 800}};
	t_ctx		ctx;

	(void)c;
	(void)args;
	init_window(&ctx.win, 3840, 2160, "MiniRT");
	create_image(&ctx.img, 3840, 2160, &ctx.win);
	ctx.cam = camera;
	ctx.spheres = vct_create(sizeof(t_sphere), 0, 0);
	create_spheres(&ctx.spheres);
	render(ctx);
	put_img(&ctx.img, 0, 0);
	register_keypress(ctx.win.events, move_cam, &ctx);
	register_destroy(ctx.win.events, end, &ctx.win);
	register_loop(ctx.win.events, loop2, &ctx);
	loop(&ctx.win);
	return (0);
}
