/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/05/21 16:58:47 by nseon            ###   ########.fr       */
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
