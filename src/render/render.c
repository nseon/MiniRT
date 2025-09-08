/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/04 15:19:23 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "render.h"
#include "supersampling.h"
#include "minirt.h"
#include "lighting.h"


t_image		*render(t_ctx *ctx, t_camera cam, t_world *world, int32_t nb_rays)
{
	int32_t		x;
	int32_t		y;
	t_fcolor	color;

	y = -1;
	while (++y < cam.vsize)
	{
		x = -1;
		while (++x < cam.hsize)
		{
			if (nb_rays == -1)
			{
				color = color_at(world, ray_for_pixel(cam, x, y), 1, NULL);
				put_pixel_img(&ctx->img, point_s(x, y, fcolor_to_uint(color)));
			}
			else
			{
				color = color_at(world, ray_for_pixel(cam, x + frandom(ctx->random, 0, 1), y + frandom(ctx->random, 0, 1)), MAX_RECURSIVE, ctx->random);
				add_rgb96_t(&ctx->gctx.color_px[x * WIN_H + y], fcolor_to_uint(color));
				put_pixel_img(&ctx->img, point_s(x, y, get_mixed_color(ctx->gctx.color_px[x * WIN_H + y], nb_rays)));
			}
		}
	}
	return (&ctx->img);
}
