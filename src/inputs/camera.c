/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/05/21 14:47:15 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "inputs.h"
#include "image.h"
#include "render.h"
#include <unistd.h>
#include <X11/X.h>
#include <X11/Xlib.h>

#include "lib/minilibx/mlx_int.h"

void	move_cam(int keycode, void *args)
{
	t_ctx	*ctx;
	static int	x;

	x++;
	ctx = (t_ctx *)args;
	if (keycode == ARROW_DOWN)
		ctx->cam.pos.y += 10;
	else if (keycode == ARROW_RIGHT)
		ctx->cam.pos.x += 10;
	else if (keycode == ARROW_UP)
		ctx->cam.pos.y -= 10;
	else if (keycode == ARROW_LEFT)
		ctx->cam.pos.x -= 10;
	clear_image(&ctx->img);
	render(*ctx);
	put_img(&ctx->img, 0, 0);
}
