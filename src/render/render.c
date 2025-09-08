/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/19 12:51:14 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "render.h"

#include <math.h>

#include "lighting.h"

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

	set_cam_transform(cam, mx_rotation_y(cam->y_rot, mx_rotation_x(cam->x_rot,
		translation(cam->mpos.x, cam->mpos.y, cam->mpos.z, buf))));
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
t_image		*render(t_image *img, t_camera cam, t_world *world)
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
			color = color_at(world, ray_for_pixel(cam, x, y), MAX_RECURSIVE);
			put_pixel_img(img, point_s(x, y, fcolor_to_uint(color)));
		}
	}
	return (img);
}
