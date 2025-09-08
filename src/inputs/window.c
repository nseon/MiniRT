/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:53:20 by nseon             #+#    #+#             */
/*   Updated: 2025/09/08 09:20:33 by nseon            ###   ########.fr       */
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

	if (keycode == XK_Escape)
	{
		ctx->mouse.focus = false;
		mlx_mouse_show(ctx->win.mlx, ctx->win.win);
	}
}
