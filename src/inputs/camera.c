/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/09/04 16:23:21 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "inputs.h"
#include "image.h"
#include "render.h"
#include "minirt.h"
#include <X11/keysym.h>
#include <stdlib.h>

void	authorize_cam_move(int keycode, void *args)
{
	t_ctx * const	ctx = args;

	if (keycode == XK_Return && ctx->parsing)
	{
		ft_bzero(ctx->gctx.color_px, sizeof (t_rgb96_t) * WIN_H * WIN_W);
		ctx->gctx.w.advanced ^= true;
		if (ctx->gctx.w.frac == 4)
			ctx->gctx.w.frac = 1;
		else
			ctx->gctx.w.frac = 4;
	}
}
