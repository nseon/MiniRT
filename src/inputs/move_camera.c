/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:56 by nseon             #+#    #+#             */
/*   Updated: 2025/09/08 11:01:17 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include "mlx.h"

#include <X11/keysym.h>
#include <math.h>

void	rotate_cam(int x, int y, void *args)
{
	t_ctx * const	ctx = args;
	t_mtx4			buff;

	if (x == WIN_W / 2 && y == WIN_H / 2)
		return ;
	if (ctx->parsing)
	{
		if (ctx->mouse.focus == true)
		{
			mlx_mouse_move(ctx->win.mlx, ctx->win.win, WIN_W / 2, WIN_H / 2);
			if (ctx->render == false)
			{
				set_cam_transform(&ctx->gctx.cam, mtx_mul2(mx_rotation_y((double)(-(x - WIN_W / 2)) * M_PI / 5000, rotation_x((double)(y - WIN_H / 2) * M_PI / 5000, buff)), ctx->gctx.cam.transform));
			}
		}
		ctx->mouse.axes.x = x;
		ctx->mouse.axes.x = y;
	}
}

void	cam_height(int keycode, void *args)
{
	t_ctx * const	ctx = args;
	t_mtx4			buff;
	double			y;

	if (ctx->render == false && ctx->parsing)
	{
		y = 0;
		if (keycode == XK_c)
			y += 0.1;
		if (keycode == XK_space)
			y -= 0.1;
		mul_cam_transform(&ctx->gctx.cam, translation(0, y, 0, buff));
	}
}

void	cam_translation(int keycode, void *args)
{
	t_ctx * const	ctx = args;
	t_mtx4			buff;
	double			x;
	double			z;

	
	if (ctx->render == false && ctx->parsing)
	{
		x = 0;
		z = 0;
		if (keycode == XK_w)
			z += 0.1;
		if (keycode == XK_s)
			z -= 0.1;
		if (keycode == XK_d)
			x += 0.1;
		if (keycode == XK_a)
			x -= 0.1;
		set_cam_transform(&ctx->gctx.cam, mtx_mul2(translation(x, 0, z, buff), ctx->gctx.cam.transform));
	}
}