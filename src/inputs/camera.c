/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/09/10 12:47:56 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <X11/keysym.h>
#include "inputs.h"
#include "minirt.h"
#include "mlx.h"
#include "neflibx.h"
#include "render.h"
#include "rt_gui.h"

void	authorize_cam_move(int keycode, void *args)
{
	t_ctx *const	ctx = args;

	if (keycode == XK_Return)
	{
		clear_ss(&ctx->gctx.ss);
		switch_gui_param(ctx, "render_btn", true);
		ctx->gctx.w.gparam ^= MOVING;
		if (ctx->gctx.w.gparam & MOVING)
		{
			mlx_mouse_move(ctx->win.mlx, ctx->win.win, WIN_W / 2, WIN_H / 2);
			mlx_mouse_hide(ctx->win.mlx, ctx->win.win);
		}
		else
			mlx_mouse_show(ctx->win.mlx, ctx->win.win);
		if (ctx->gctx.frac == WIN_W / 200)
			ctx->gctx.frac = 1;
		else
			ctx->gctx.frac = WIN_W / 200;
	}
}
