/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/05/21 12:32:36 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inputs.h"
#include "image.h"
#include "render.h"
#include <unistd.h>

void	move_cam(int keycode, void *args)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)args;
	if (keycode == ARROW_UP)
		ctx->cam.pos.y += 10;
	else if (keycode == ARROW_RIGHT)
		ctx->cam.pos.x += 10;
	else if (keycode == ARROW_DOWN)
		ctx->cam.pos.y -= 10;
	else if (keycode == ARROW_LEFT)
		ctx->cam.pos.x -= 10;
	clear_image(&ctx->img);
	render(ctx->cam, &ctx->img);
	put_img(&ctx->img, 0, 0);
}