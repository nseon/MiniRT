/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:10:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 15:10:21 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "lighting.h"
#include "minirt.h"
#include "matrix.h"
#include "ray.h"
#include "colors.h"
#include "neflibx.h"

void	keyevent(int keycode, void *p)
{
	t_ctx	*const ctx = p;

	ctx->z += 5;
}

void	test_render(t_ctx * const ctx)
{
	t_mtx4		buf;
	t_ray		r;
	t_light		l = light(point(-2000, -700, 1000), fcolor(1, 1, 1), POINT);
	t_fcolor	color;
	t_world		w;
	t_obj		s = sphere();

	world(&w);
	vct_add(&w.lights, &l);
	// set_transform(&s, mx_translation(0, 0, 20, scaling(11, 11, 11, buf)));
	set_transform(&s, mx_scaling(500, 200, 500, mx_shearing(g_arr2_0, g_arr2_0, g_arr2_0 , mx_rotation_z(M_PI_4, translation(0, 0, 2000, buf)))));
	add_world_obj(&w, s);
	s = sphere();
	set_transform(&s, mx_scaling(500, 500, 500, mx_shearing(g_arr2_0, g_arr2_0, g_arr2_0 , mx_rotation_z(M_PI_4, translation(0, 400, 1100, buf)))));
	add_world_obj(&w, s);
	w.objs[1].mat.col = fcolor(1, 0.1, 1);

	s.mat = g_default_mat;
	s.mat.col = fcolor(1, 1, 1);
	for (int y = 0; y < WIN_H; y++)
	{
		for (int x = 0; x < WIN_W; x++)
		{
			r = ray(point(0, 0, 0), tp_normalize(tp_sub(point(x - WIN_W / 2, - y + WIN_H / 2, 800), point(0, 0, 0))));
			color = color_at(&w, r);
			put_pixel_img(&ctx->img, point_s(x, y, fcolor_to_uint(color)));
		}
	}
	free_world(&w);
	// end_loop(&ctx->win);
}
