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

#include "inputs.h"
#include "image.h"
#include "render.h"
#include "minirt.h"
#include <X11/keysym.h>
#include "neflibx.h"

void	authorize_cam_move(int keycode, void *args)
{
	t_ctx *const	ctx = args;

	if (keycode == XK_Return)
	{
		clear_ss(&ctx->gctx.ss);
		ctx->gctx.w.gparam |= RENDER;
		get_by_id(&ctx->win, "render_btn")->checked = true;
		ctx->gctx.w.gparam ^= MOVING;
		if (ctx->gctx.frac == WIN_W / 200)
			ctx->gctx.frac = 1;
		else
			ctx->gctx.frac = WIN_W / 200;
	}
}
