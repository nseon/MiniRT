/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/21 16:41:22 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "neflibx.h"
#include "inputs.h"

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

int	main(int c, char **args)
{
	t_camera	camera = {.pos = {0, 0, 0}, .orient = {0, 0, 1},
		.vp = {1920, 1080, 800}};
	t_ctx		ctx;

	init_window(&ctx.win, 960, 540, "MiniRT");
	create_image(&ctx.img, 960, 540, &ctx.win);
	ctx.cam = camera;
	render(ctx);
	put_img(&ctx.img, 0, 0);
	register_destroy(ctx.win.events, end, &ctx.win);
	register_keypress(ctx.win.events, move_cam, &ctx);
	loop(&ctx.win);
	return (0);
}
