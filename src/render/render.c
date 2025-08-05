/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:52:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/05 08:51:29 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "render.h"
#include "neflibx.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "minirt.h"

static t_vec3	win_to_vp(t_graphic_ctx *gctx, float const x,
							float const y, t_image *        img)
{
	const float	vx = x * gctx->cam.vp.vw / img->w + gctx->cam.pos.x
		- gctx->cam.vp.vw / 2;
	const float	vy = y * gctx->cam.vp.vh / img->h + gctx->cam.pos.y
		- gctx->cam.vp.vh / 2;
	const t_vec3	vp_point = {vx, vy, gctx->cam.vp.d + gctx->cam.pos.z};

	return (get_vec3(gctx->cam.pos, vp_point));
}

void	render(t_graphic_ctx *gctx, t_image *img, uint8_t const random[2 * RAY_NBR], int nb_ray)
{
	int16_t			x;
	int16_t			y;
	t_ren_calc		ren;
	t_point3		vp;

	x = -1;
	while (++x < img->w)
	{
		y = -1;
		while (++y < img->h)
		{
			ren = (t_ren_calc){0};
			if (nb_ray <= 1)
				vp = win_to_vp(gctx, x, y, img);
			else
				vp = win_to_vp(gctx, x + frandom(random), y + frandom(random), img);
			// ren.d = v3_multiply(get_vec3(g0ctx.cam.pos, vp), v3_dotproduct(gctx.cam.orient, get_vec3(gctx.cam.pos, vp)));
			ren.d = get_vec3(gctx->cam.pos, vp);
			// printf("x:%f\ny:%f\nz:%f\n\n", vp.x, vp.y, vp	.z);
			// ren.d.y += nb_ray;
			ren.o = gctx->cam.pos;
			add_rgb96_t(&gctx->color_px[x * WIN_H + y], trace_ray(gctx, ren, 0));
			put_pixel_img(img, (t_point){x, y, get_mixed_color(gctx->color_px[x * WIN_H + y], nb_ray + 1)});
		}
	}
}
