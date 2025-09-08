/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:56 by nseon             #+#    #+#             */
/*   Updated: 2025/09/08 16:05:56 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include "mlx.h"
#include "rt_maths.h"

#include <X11/keysym.h>
#include <math.h>

void	rotate_cam(int x, int y, void *args)
{
    t_ctx * const	ctx = args;
    t_mtx4			buff;
    t_tuple			tmp;

    if (x == WIN_W / 2 && y == WIN_H / 2)
        return ;
    if (ctx->parsing)
    {
        if (ctx->mouse.focus == true)
        {
            mlx_mouse_move(ctx->win.mlx, ctx->win.win, WIN_W / 2, WIN_H / 2);
            if (ctx->render == false)
            {
                ctx->gctx.cam.y_rot += (x - WIN_W / 2) * 0.002;
				ctx->gctx.cam.x_rot -= (y - WIN_H / 2) * 0.002;
				
            }
        }
    }
}

void	cam_height(int keycode, void *args)
{
	t_ctx * const	ctx = args;
	t_mtx4			buff;
	double			y;

	if (ctx->render == false && ctx->parsing)
	{
		if (keycode == XK_c)
			ctx->gctx.cam.pos.y -= 0.1;
		if (keycode == XK_space)
			ctx->gctx.cam.pos.y += 0.1;
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
			ctx->gctx.cam.pos = tp_add(ctx->gctx.cam.pos, tp_mul(ctx->gctx.cam.orient, 0.1));
		if (keycode == XK_s)
			ctx->gctx.cam.pos = tp_sub(ctx->gctx.cam.pos, tp_mul(ctx->gctx.cam.orient, 0.1));
		if (keycode == XK_d)
			ctx->gctx.cam.pos = tp_sub(ctx->gctx.cam.pos, tp_mul(tp_cross(ctx->gctx.cam.orient, vector(0, 1, 0)), 0.1));
		if (keycode == XK_a)
			ctx->gctx.cam.pos = tp_add(ctx->gctx.cam.pos, tp_mul(tp_cross(ctx->gctx.cam.orient, vector(0, 1, 0)), 0.1));
		set_cam_transform(&ctx->gctx.cam, mtx_mul2(translation(x, 0, z, buff), ctx->gctx.cam.transform));
	}
}