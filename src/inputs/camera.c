/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/05/23 17:26:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "inputs.h"
#include "image.h"
#include "render.h"
#include "minirt.h"
#include <X11/keysym.h>
#include <stdlib.h>



void	move_cam(int keycode, void *args)
{
	t_ctx	*ctx;
	static int	x;

	x++;
	ctx = (t_ctx *)args;
	ctx->render = true;
	if (keycode == XK_w)
		ctx->gctx.cam.pos.z += 20;
	else if (keycode == XK_d)
		ctx->gctx.cam.pos.x += 20;
	else if (keycode == XK_s)
		ctx->gctx.cam.pos.z -= 20;
	else if (keycode == XK_a)
		ctx->gctx.cam.pos.x -= 20;
	else if (keycode == XK_space)
		ctx->gctx.cam.pos.y -= 20;
	else if (keycode == XK_c)
		ctx->gctx.cam.pos.y += 20;
	// if (keycode == XK_Down)
	// 	ctx->lights[0].pos.y += 100;
	// else if (keycode == ARROW_RIGHT)
	// 	ctx->lights[0].pos.x += 100;
	// else if (keycode == ARROW_UP)
	// 	ctx->lights[0].pos.y -= 100;
	// else if (keycode == ARROW_LEFT)
	// 	ctx->lights[0].pos.x -= 100;
}

void	release(int keycode, void *args)
{
	(void)keycode;
	((t_ctx *)args)->render = false;
}

void	mouse_unclick(int keycode, int x, int y, void *args)
{
	t_mouse *mouse;

	mouse = (t_mouse *)args;
	(void)x;
	(void)y;
	if (keycode == 1)
		mouse->click = false;
}

void	move_wheel(int keycode, int x, int y, void *args)
{
	t_graphic_ctx	*ctx;

	(void)x;
	(void)y;
	ctx = (t_graphic_ctx *)args;
	if (keycode == 4)
		ctx->cam.pos.z += 100;
	else if (keycode == 5)
		ctx->cam.pos.z -= 100;
}
