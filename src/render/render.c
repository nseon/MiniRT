/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:52:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/26 12:55:11 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "render.h"
#include "neflibx.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include "minirt.h"

static t_vec3	win_to_vp(t_graphic_ctx *gctx, int16_t const x,
							int16_t const y, t_image *        img)
{
	const float	vx = x * gctx->cam.vp.vw / img->w + gctx->cam.pos.x
		- gctx->cam.vp.vw / 2;
	const float	vy = y * gctx->cam.vp.vh / img->h + gctx->cam.pos.y
		- gctx->cam.vp.vh / 2;
	const t_vec3	vp_point = {vx, vy, gctx->cam.vp.d + gctx->cam.pos.z};

	return (get_vec3(gctx->cam.pos, vp_point));
}

void	render(t_graphic_ctx *gctx, t_image *img)
{
	int16_t			x;
	int16_t			y;
	t_ren_calc		ren;

	x = -1;
	while (++x < img->w)
	{
		y = -1;
		while (++y < img->h)
		{
			ren = (t_ren_calc){0};
			ren.d = win_to_vp(gctx, x, y, img);
			ren.o = gctx->cam.pos;
			put_pixel_img(img, (t_point){x, y,
				trace_ray(gctx, ren, 0)});
		}
	}
}
