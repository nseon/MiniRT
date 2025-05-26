/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/05/26 17:48:51 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "inputs.h"
#include "image.h"
#include "render.h"
#include "minirt.h"
#include <X11/keysym.h>
#include <stdlib.h>



void	move_cam(int keycode, void *args)
{
	t_graphic_ctx	*gctx;
	static int	x;

	x++;
	gctx = (t_graphic_ctx *)args;
	if (keycode == XK_w)
		gctx->cam.pos.z += 20;
	else if (keycode == XK_d)
		gctx->cam.pos.x += 20;
	else if (keycode == XK_s)
		gctx->cam.pos.z -= 20;
	else if (keycode == XK_a)
		gctx->cam.pos.x -= 20;
	else if (keycode == XK_space)
		gctx->cam.pos.y -= 20;
	else if (keycode == XK_c)
		gctx->cam.pos.y += 20;
	// if (keycode == XK_Down)
	// 	ctx->lights[0].pos.y += 100;
	// else if (keycode == ARROW_RIGHT)
	// 	ctx->lights[0].pos.x += 100;
	// else if (keycode == ARROW_UP)
	// 	ctx->lights[0].pos.y -= 100;
	// else if (keycode == ARROW_LEFT)
	// 	ctx->lights[0].pos.x -= 100;
}

static t_vec3	win_to_vp(t_graphic_ctx const gctx, int16_t const x,
	int16_t const y, t_image *img)
{
	const float		vx = x * gctx.cam.vp.vw / img->w + gctx.cam.pos.x
		- gctx.cam.vp.vw / 2;
	const float		vy = y * gctx.cam.vp.vh / img->h + gctx.cam.pos.y
		- gctx.cam.vp.vh / 2;
	const t_vec3	vp_point = {vx, vy, gctx.cam.vp.d + gctx.cam.pos.z};

	return (get_vec3(gctx.cam.pos, vp_point));
}

static t_vec3	get_vp(t_graphic_ctx const gctx, int16_t const x,
	int16_t const y, t_image *img)
{
	const float		vx = x * gctx.cam.vp.vw / img->w + gctx.cam.pos.x
		- gctx.cam.vp.vw / 2;
	const float		vy = y * gctx.cam.vp.vh / img->h + gctx.cam.pos.y
		- gctx.cam.vp.vh / 2;
	const t_vec3	vp_point = {vx, vy, gctx.cam.vp.d + gctx.cam.pos.z};

	return (vp_point);
}

void	mouse_click(int keycode, int x, int y, void *args)
{
	t_ctx	*ctx;
	t_color			color;
	t_vec3			pos;
	t_vec3			d;

	ctx = (t_ctx *)args;
	d = win_to_vp(ctx->gctx, x, y, &ctx->img);
	if (keycode == 1)
	{
		color.r = rand() % (255 - 0 + 1) + 0;
		color.g = rand() % (255 - 0 + 1) + 0;
		color.b = rand() % (255 - 0 + 1) + 0;
		color.a = 0;
		pos = get_vp(ctx->gctx, x, y, &ctx->img);
		pos = v3_add(pos, v3_multiply(d, 6));
		vct_add(&ctx->gctx.spheres, &(t_sphere){pos, 500, color.argb, 20, 0.3});

	}
}

void	mouse_unclick(int keycode, int x, int y, void *args)
{
	t_mouse *mouse;

	mouse = (t_mouse *)args;
	(void)x;
	(void)y;
	if (keycode == 1)
		mouse->click = false;
}

void	move_wheel(int keycode, int x, int y, void *args)
{
	t_graphic_ctx	*ctx;

	(void)x;
	(void)y;
	ctx = (t_graphic_ctx *)args;
	if (keycode == 4)
		ctx->cam.pos.z += 100;
	else if (keycode == 5)
		ctx->cam.pos.z -= 100;
}
