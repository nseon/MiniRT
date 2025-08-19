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
	t_world		w;
	world(&w);
	t_obj		s;
	t_light		l;
	t_camera	cam;

	cam = camera(WIN_W, WIN_H, M_PI / 3);
	set_cam_transform(&cam, mtx4_view(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0), buf));
	l = light(point(-10, 10, -10), fcolor(1, 1, 1), POINT);
	vct_add(&w.lights, &l);
	s = sphere();
	set_transform(&s, scaling(10, 0.01, 10, buf));
	s.mat.col = fcolor(1, 0.9, 0.9);
	s.mat.specular = 0;
	add_world_obj(&w, s);
	s = sphere();
	set_transform(&s, mx_scaling(10, 0.01, 10, mx_rotation_z(M_PI_2, mx_rotation_y(-M_PI_4, translation(0, 0, 5, buf)))));
	s.mat.col = fcolor(1, 0.9, 0.9);
	s.mat.specular = 0;
	add_world_obj(&w, s);
	render(&ctx->img, cam, &w);
}
