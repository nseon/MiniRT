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

void	move_cam(int keycode, void *args)
{
	t_graphic_ctx	*gctx;
	static int	x;

	x++;
	gctx = (t_graphic_ctx *)args;
	if (keycode == XK_Down)
		gctx->cam.pos.y += 10;
	else if (keycode == XK_Right)
		gctx->cam.pos.x += 10;
	else if (keycode == XK_Up)
		gctx->cam.pos.y -= 10;
	else if (keycode == XK_Left)
		gctx->cam.pos.x -= 10;
	// if (keycode == XK_Down)
	// 	ctx->lights[0].pos.y += 100;
	// else if (keycode == ARROW_RIGHT)
	// 	ctx->lights[0].pos.x += 100;
	// else if (keycode == ARROW_UP)
	// 	ctx->lights[0].pos.y -= 100;
	// else if (keycode == ARROW_LEFT)
	// 	ctx->lights[0].pos.x -= 100;
}

void	mouse_move(int x, int y, void *args)
{
	t_ctx *ctx;

	ctx = (t_ctx *)args;
	if (ctx->mouse.click == true)
	{
		if (x > ctx->mouse.x)
			ctx->gctx.cam.pos.x -= x - ctx->mouse.x;
		if (x < ctx->mouse.x)
			ctx->gctx.cam.pos.x += ctx->mouse.x - x;
		if (y > ctx->mouse.y)
			ctx->gctx.cam.pos.y -= y - ctx->mouse.y;
		if (y < ctx->mouse.y)
			ctx->gctx.cam.pos.y += ctx->mouse.y - y;
	}
}

void	mouse_click(int keycode, int x, int y, void *args)
{
	t_mouse *mouse;

	mouse = (t_mouse *)args;
	if (keycode == 1)
	{
		mouse->x = x;
		mouse->y = y;
		mouse->click = true;
	}
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
		ctx->lights[0].pos.z += 100;
	else if (keycode == 5)
		ctx->lights[0].pos.z -= 100;
}
