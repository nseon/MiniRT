/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/08 16:02:29 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "render.h"
#include "supersampling.h"
#include "minirt.h"

#include <math.h>

#include "lighting.h"

void	compute_obj_matrice(t_obj *o)
{
	t_mtx4	tbuf;

	set_transform(o, translation(o->pos.x, o->pos.y, o->pos.z, tbuf));
	mul_transform(o, scaling(o->x_size / 2, o->y_size / 2, o->z_size / 2,
		tbuf));
	mul_transform(o, rotation_x(o->x_rot, tbuf));
	mul_transform(o, rotation_y(o->y_rot, tbuf));
	mul_transform(o, rotation_z(o->z_rot, tbuf));
}

void	compute_cam_matrice(t_camera *cam)
{
	t_mtx4	buf;

	set_cam_transform(cam, rotation_x(cam->x_rot, buf));
	mul_cam_transform(cam, rotation_y(cam->y_rot, buf));
	mul_cam_transform(cam, mtx4_view(cam->pos, tp_add(cam->pos, cam->orient),
		vector(0, 1, 0), buf));
}

void	compute_matrices(t_camera *cam, t_obj *objs)
{
	size_t	i;

	compute_cam_matrice(cam);
	i = -1;
	while (++i < vct_size(objs))
		compute_obj_matrice(objs + i);
}
t_image		*render(t_ctx *ctx, t_camera cam, t_world *world, int32_t nb_rays)
{
	int32_t		x;
	int32_t		y;
	t_fcolor	color;

	compute_matrices(&cam, world->objs);
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
