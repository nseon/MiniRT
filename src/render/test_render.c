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

void	test_render(t_ctx * const ctx)
{
	t_obj			s = sphere();
	t_mtx4			buf;
	t_intersections	xs;
	t_ray			r;
	t_light const	l = light(point(-2000, -700, 1000), fcolor(1, 1, 1), POINT);
	t_pre_compute	pc;
	t_fcolor		color;

	// set_transform(&s, mx_translation(0, 0, 20, scaling(11, 11, 11, buf)));
	set_transform(&s, mx_scaling(500, 200, 500, mx_shearing(g_arr2_0, g_arr2_0, g_arr2_0 , mx_rotation_z(M_PI_4, translation(0, 0, 2000, buf)))));
	s.mat = g_default_mat;
	s.mat.col = fcolor(1, 1, 1);
	xs.i = malloc (sizeof (t_intersection) * 2);
	xs.count = 0;
	for (int y = 0; y < WIN_H; y++)
	{
		for (int x = 0; x < WIN_W; x++)
		{
			r = ray(point(0, 0, 0), tp_normalize(tp_sub(point(x - WIN_W / 2, y - WIN_H / 2, 800), point(0, 0, 0))));
			intersect(r, &s, &xs);
			if (hit(&xs) != NULL)
			{
				pc = pre_compute(*hit(&xs), r);
				color = phong(hit(&xs)->obj->mat, l, &pc);
				put_pixel_img(&ctx->img, point_s(x, y, fcolor_to_uint(color)));
			}
			else
				put_pixel_img(&ctx->img, point_s(x, y, 0x000000));
			xs.count = 0;
		}
	}
	free(xs.i);
}
