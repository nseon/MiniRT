/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/11 10:11:18 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include "ray.h"

#include <math.h>
#include <stdio.h>

#include "lighting.h"
#include "random.h"
#include "rt_maths.h"

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
	if (dabs(tp_dot(vector(0, 1, 0), cam->orient)) > 0.95)
		mul_cam_transform(cam, mtx4_view(cam->pos, tp_add(cam->pos, cam->orient),
			vector(0, 0, 1), buf));
	else
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

void	render(t_gctx *gctx, t_world *w)
{
	int32_t		y;
	int32_t		x;
	t_fcolor	color;

	compute_matrices(&w->cam, w->objs);
	if (gctx->ss.sample_num >= gctx->ss.max_sample)
		return ;
	y = 0;
	while (y < w->cam.vsize)
	{
		x = 0;
		while (x < w->cam.hsize)
		{
			if (gctx->w.gparam & SS && !(gctx->w.gparam & MOVING))
				color = color_at(w, ray_for_pixel(w->cam, x + frandom(0, 1),
					y + frandom(0, 1)), MAX_RECUR);
			else
				color = color_at(w, ray_for_pixel(w->cam, x, y), MAX_RECUR);
			gctx->frame[y * WIN_W + x] = color;
			x += gctx->frac;
		}
		y += gctx->frac;
	}
	if (gctx->w.gparam & SS && !(gctx->w.gparam & MOVING))
		add_ss_frame(&gctx->ss, gctx->frame);
}
