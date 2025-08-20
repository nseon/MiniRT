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
	t_mtx4		buf;
	t_world		w;
	world(&w);
	w.ambient.i  = 0.25;
	w.ambient.col = fcolor(1, 1, 1);
	t_obj		s;
	t_obj		p;
	t_light		l;
	t_camera	cam;

	cam = camera(WIN_W, WIN_H, M_PI / 1.9);
	set_cam_transform(&cam, mtx4_view(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0), buf));
	// mul_cam_transform(&cam, rotation_z(M_PI / 8, buf));
	l = light(point(0, 4, -5), fcolor(0.7, 0.7, 0.7), POINT);
	vct_add(&w.lights, &l);
	// l = light(point(-15, 5, -15), fcolor(1, 1, 1), POINT);
	// vct_add(&w.lights, &l);
	p = plane();
	p.mat.col = fcolor(1, 0.9, 0.9);
	p.mat.specular = 0;
	add_world_obj(&w, p);
	p = plane();
	set_transform(&p, translation(0, 4, 0, buf));
	p.mat.col = fcolor(1, 0.9, 0.9);
	p.mat.specular = 0;
	add_world_obj(&w, p);
	p = plane();
	set_transform(&p, mx_rotation_z(M_PI_2, mx_rotation_y(-M_PI_4, translation(0, 0, 5, buf))));
	s.mat.col = fcolor(1, 0.9, 0.9);
	s.mat.specular = 0;
	add_world_obj(&w, p);
	p = plane();
	set_transform(&p, mx_scaling(10, 0.01, 10, mx_rotation_z(M_PI_2, mx_rotation_y(M_PI_4, translation(0, 0, 5, buf)))));
	p.mat.col = fcolor(1, 0.9, 0.9);
	p.mat.specular = 0;
	add_world_obj(&w, p);
	s = sphere();
	set_transform(&s,translation(-0.5, 1, 0.5, buf));
	s.mat.col = fcolor(0, 1, 0);
	s.mat.specular = 0.3;
	s.mat.diffuse = 0.7;
	add_world_obj(&w, s);
	s = sphere();
	set_transform(&s,mx_scaling(0.5, 0.5, 0.5, translation(1.5, 1, -0.5, buf)));
	s.mat.col = fcolor(0.5, 1, 0.1);
	s.mat.specular = 0.3;
	s.mat.diffuse = 0.7;
	add_world_obj(&w, s);
	s = sphere();
	set_transform(&s,mx_scaling(0.33, 0.33, 0.33, translation(-1.5, 0.33, -0.75, buf)));
	s.mat.col = fcolor(1, 0.8, 0.1);
	s.mat.specular = 0.3;
	s.mat.diffuse = 0.7;
	add_world_obj(&w, s);
	render(&ctx->img, cam, &w);
	free_world(&w);
	// end_loop(&ctx->win);
}
