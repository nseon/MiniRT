/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/10 11:20:47 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include "ray.h"

#include <math.h>
#include <stdio.h>

#include "lighting.h"
#include "random.h"

void	compute_obj_matrice(t_obj *o)
{
	t_mtx4	tbuf;

	set_transform(o, mx_rotation_y(o->y_rot, mx_rotation_z(o->z_rot,
		mx_rotation_x(o->x_rot, mx_scaling(o->x_size / 2, o->y_size / 2,
		o->z_size / 2, translation(o->pos.x, o->pos.y, o->pos.z, tbuf))))));
}

void	compute_cam_matrice(t_camera *cam)
{
	t_mtx4	buf;

	set_cam_transform(cam, mx_rotation_y(cam->y_rot, rotation_x(cam->x_rot, buf)));
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

t_fcolor	compute_color(t_ctx *ctx, t_camera *cam, t_world *world, int32_t nb_rays)
{
	t_fcolor	color;


	return (color);
}

t_image		*render(t_ctx *ctx, t_camera *cam, t_world *world, int32_t nb_rays)
{
	int32_t		x;
	int32_t		y;
	int32_t		i;
	int32_t		j;
	t_fcolor	color;
	uint32_t	ucol;

	compute_matrices(cam, world->objs);
	y = 0;
	while (y < cam->vsize)
	{
		x = 0;
		while (x < cam->hsize)
		{
			if (nb_rays == -1)
			{
				color = color_at(world, ray_for_pixel(*cam, x, y), 1);
				ucol = fcolor_to_uint(color);
			}
			else
			{
				color = color_at(world, ray_for_pixel(*cam, x + frandom(0, 1), y + frandom(0, 1)), MAX_RECURSIVE);
				add_rgb96_t(&ctx->gctx.color_px[x * WIN_H + y], fcolor_to_uint(color));
				put_pixel_img(&ctx->img, point_s(x, y, get_mixed_color(ctx->gctx.color_px[x * WIN_H + y], nb_rays)));
			}
			i = -1;
			while (world->frac != 1 && ++i < world->frac)
			{
				j = -1;
				while (++j < world->frac)
					put_pixel_img(&ctx->img, point_s(x + j, y + i, ucol));
			}
			x += world->frac;
		}
		y += world->frac;
	}
	return (&ctx->img);
}
