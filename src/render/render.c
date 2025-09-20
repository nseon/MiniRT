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

#include <math.h>
#include <stdio.h>

#include "lighting.h"
#include "minirt.h"
#include "neflibx.h"
#include "random.h"
#include "ray.h"
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

t_fcolor	get_fcolor(t_fcolor *col, int32_t x, int32_t y)
{
	if (x < 0 || y < 0 || x == WIN_W || y == WIN_H)
		return (fcolor(0, 0, 0));
	return (col[y * WIN_W + x]);
}

float	gaussian(float x, float o)
{
	return ((1 / (2 * M_PI) * o * o) * exp(-(x * x) / (2 * o * o)));
}

float	pix_dis(int32_t y, int32_t x, int32_t i, int32_t j)
{
	return (sqrt((y - i) * (y - i) + (x - j) * (x - j)));
}

float	col_dis(t_fcolor c1, t_fcolor c2)
{
	return (sqrt(pow(c1.r - c2.r, 2) + pow(c1.g - c2.g, 2) + pow(c1.b - c2.b, 2)));
}

t_fcolor	filter_pixel(t_fcolor *frame, int32_t x, int32_t y, float or, float od, int n)
{
	float		total_w;
	float		w;
	int32_t		i;
	int32_t		j;
	t_fcolor	col;

	col = fcolor(0, 0, 0);
	total_w = 0;
	i = -(n - 1) / 2 - 1;
	while (++i < (n - 1) / 2)
	{
		j = -(n - 1) / 2 - 1;
		while (++j < (n - 1) / 2)
		{
			if (y + i < 0 || x + j < 0 || y + i >= WIN_H || x + j >= WIN_W)
				continue ;
			w = gaussian(pix_dis(y, x, y + i, x + j), od);
			w *= gaussian(col_dis(frame[(y + i) * WIN_W + (x + j)], frame[(y) * WIN_W + (x)]), or);
			total_w += w;
			col = color_add(col, col_scalar2(frame[(y + i) * WIN_W + (x + j)], w));
		}
	}
	return (col_scalar(col, 1.0 / total_w));
}

void	bilateral_filter(t_gctx *gctx, float or, float od)
{
	int32_t		y;
	int32_t		x;
	t_fcolor	*buf;

	if (gctx->w.gparam & MOVING)
		return ;
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			gctx->buf_frame[y * WIN_W + x] = filter_pixel(gctx->frame, x, y, or, od, 21);
		}
	}
	buf = gctx->frame;
	gctx->frame = gctx->buf_frame;
	gctx->buf_frame = buf;
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
	if (gctx->ss.sample_num == gctx->ss.max_sample)
		bilateral_filter(gctx, 0.2, 10);
	if (gctx->ss.sample_num == gctx->ss.max_sample)
		printf("Rendered!\n");
}
