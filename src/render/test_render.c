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

#include "minirt.h"
#include "matrix.h"
#include "ray.h"

void	test_render(t_ctx * const ctx)
{
	t_obj			s = sphere();
	t_mtx4			buf;
	t_intersections	xs;
	t_ray			r;

	// set_transform(&s, mx_translation(0, 0, 20, scaling(11, 11, 11, buf)));
	set_transform(&s, mx_scaling(200, 200, 200, mx_rotation_z(M_PI_4, translation(0, 0, 2000, buf))));
	for (int y = 0; y < WIN_H; y++)
	{
		for (int x = 0; x < WIN_W; x++)
		{
			r = ray(point(0, 0, 0), tp_normalize(tp_sub(point(x - WIN_W / 2, y - WIN_H / 2, 800), point(0, 0, 0))));
			xs = intersect(r, &s);
			if (hit(&xs) != NULL)
				put_pixel_img(&ctx->img, point_s(x, y, 0xFF0000));
			else
				put_pixel_img(&ctx->img, point_s(x, y, 0x000000));
		}
	}
}
