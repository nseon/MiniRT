/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:53:20 by nseon             #+#    #+#             */
/*   Updated: 2025/09/10 12:47:32 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render.h"
#include "minirt.h"

#include <X11/keysym.h>

void	window_focus(int keycode, int x, int y, void *args)
{
	t_ctx * const	ctx = args;

	if (keycode == 1 && ctx->parsing)
	{
		ctx->mouse.focus = true;
		mlx_mouse_hide(ctx->win.mlx, ctx->win.win);
		mlx_mouse_move(ctx->win.mlx, ctx->win.win, WIN_W / 2, WIN_H / 2);
	}
}
void	window_unfocus(int keycode, void *args)
{
	t_ctx * const	ctx = args;

	clear_ss(&ctx->gctx.ss);
	if (keycode == XK_1)
		ctx->gctx.w.gparam ^= SPECULAR;
	else if (keycode == XK_2)
		ctx->gctx.w.gparam ^= DIFFUSE;
	else if (keycode == XK_3)
		ctx->gctx.w.gparam ^= AMBIENT;
	else if (keycode == XK_4)
		ctx->gctx.w.gparam ^= SHADOWS;
	else if (keycode == XK_5)
		ctx->gctx.w.gparam ^= REFLECT;
	else if (keycode == XK_6)
		ctx->gctx.w.gparam ^= TRANSPARENCY;
	else if (keycode == XK_7)
		ctx->gctx.w.gparam ^= INDIRECT;
	else if (keycode == XK_9)
		ctx->gctx.w.gparam ^= SS;
	if (keycode == XK_Escape)
	{
		ctx->mouse.focus = false;
		mlx_mouse_show(ctx->win.mlx, ctx->win.win);
	}
}

void	focus_swicth(t_ctx	*ctx)
{
	if (ctx->mouse.focus)
		window_unfocus(XK_Escape, ctx);
	else
		window_focus(1, 0, 0, ctx);
}
