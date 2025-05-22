/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/05/22 17:38:06 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "inputs.h"
#include "image.h"
#include "render.h"
#include <unistd.h>
#include <X11/keysymdef.h>

#include "mlx.h"

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
}

void	mouse_move(int x, int y, void *args)
{
	t_ctx *ctx;

	ctx = (t_ctx *)args;
	if (ctx->mouse.click == true)
	{
		if (x > ctx->mouse.x)
			ctx->cam.pos.x -= x - ctx->mouse.x;
		if (x < ctx->mouse.x)
			ctx->cam.pos.x += ctx->mouse.x - x;
		if (y > ctx->mouse.y)
			ctx->cam.pos.y -= y - ctx->mouse.y;
		if (y < ctx->mouse.y)
			ctx->cam.pos.y += ctx->mouse.y - y;
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
		if (keycode == 1)
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
	t_ctx	*ctx;

	(void)x;
	(void)y;
	ctx = (t_ctx *)args;
	if (keycode == 4)
		ctx->cam.pos.z += 30;
	else if (keycode == 5)
		ctx->cam.pos.z -= 30;
}
