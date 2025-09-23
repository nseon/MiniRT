/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:56 by nseon             #+#    #+#             */
/*   Updated: 2025/09/08 18:09:32 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include "mlx.h"
#include "rt_maths.h"

#include <X11/keysym.h>
#include <math.h>
#include <stdio.h>

void	rotate_cam(int x, int y, void *args)
{
    t_ctx * const		ctx = args;
	t_camera * const	cam = &ctx->gctx.w.cam;
	t_mtx4				tbuf;
	t_tuple				ori;

    if (x == WIN_W / 2 && y == WIN_H / 2)
    	return ;
	if (ctx->mouse.focus == true)
	{
		mlx_mouse_move(ctx->win.mlx, ctx->win.win, WIN_W / 2, WIN_H / 2);
		if (ctx->gctx.w.gparam & MOVING)
		{
			cam->y_rot -= (x - WIN_W / 2) * 0.001;
			cam->x_rot += (y - WIN_H / 2) * 0.001;
		}
	}
}

void	cam_height(int keycode, void *args)
{
	t_ctx * const	ctx = args;
	t_mtx4			buff;
	double			y;

	if (ctx->gctx.w.gparam & MOVING)
	{
		if (keycode == XK_c)
			ctx->gctx.w.cam.pos.y -= 0.1;
		if (keycode == XK_space)
			ctx->gctx.w.cam.pos.y += 0.1;
	}
}

void	cam_translation(int keycode, void *args)
{
	t_ctx * const		ctx = args;
	t_camera * const	cam = &ctx->gctx.w.cam;
	
	if (ctx->gctx.w.gparam & MOVING)
	{
		if (keycode == XK_w)
			cam->pos = tp_sub(cam->pos, tp_mul(mtx_tup_mul(vector(0, 0, 1), cam->inverse), 0.1));
		if (keycode == XK_s)
			cam->pos = tp_add(cam->pos, tp_mul(mtx_tup_mul(vector(0, 0, 1), cam->inverse), 0.1));
		if (keycode == XK_d)
			cam->pos = tp_sub(cam->pos, tp_mul(mtx_tup_mul(vector(1, 0, 0), cam->inverse), 0.1));
		if (keycode == XK_a)
			cam->pos = tp_add(cam->pos, tp_mul(mtx_tup_mul(vector(1, 0, 0), cam->inverse), 0.1));
	}
}
