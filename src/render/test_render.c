/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:10:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/01 16:35:39 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "lighting.h"
#include "matrix.h"
#include "minirt.h"
#include "neflibx.h"
#include "ray.h"

// void	test_render(t_ctx * const ctx)
// {
// 	t_mtx4		buf;
// 	t_world		w;
// 	world(&w);
// 	w.amb.i  = 0.25;
// 	w.amb.col = fcolor(1, 1, 1);
// 	t_obj		s;
// 	t_obj		p;
// 	t_light		l;
// 	t_camera	cam;
// 	int32_t		rays;

// 	cam = camera(WIN_W, WIN_H, M_PI / 1.9);
// 	set_cam_transform(&cam, mtx4_view(point(0, 1.5, -5), point(0, 1.5, 0), vector(0, 1, 0), buf));
// 	// mul_cam_transform(&cam, rotation_z(M_PI / 8, buf));
// 	l = light(point(0, 3.5, -5), fcolor(1, 1, 1), POINT);
// 	vct_add(&w.lights, &l);
// 	// l = light(point(-15, 5, -15), fcolor(1, 1, 1), POINT);
// 	// vct_add(&w.lights, &l);
// 	p = plane();
// 	set_transform(&p, mtx4_view(point(0, 0, 0), point(0, 0, -1), vector(0, 1, 0), buf));
// 	p.mat.col = fcolor(1, 0.9, 0.9);
// 	p.mat.reflective = 0.8;
// 	// p.mat.transparency = 0.9;
// 	// p.mat.refractive = 1.5;
// 	p.mat.pat.type = RING;
// 	p.mat.pat.a = fcolor(1, (float)170/255, 0);
// 	p.mat.pat.b = fcolor((float)173/255, (float)0, 1);
// 	set_pattern_transf(&p.mat.pat, mx_rotation_y(M_PI_4, mx_scaling(0.3, 0.3, 0.3, translation(0, 0, 0, s.mat.pat.transf))));
// 	p.mat.has_pat = true;
// 	p.mat.specular = 0;
// 	add_world_obj(&w, p);
// 	p = plane();
// 	set_transform(&p, translation(0, 4, 0, buf));
// 	p.mat.col = fcolor(1, 0.9, 0.9);
// 	p.mat.specular = 0;
// 	add_world_obj(&w, p);
// 	p = plane();
// 	set_transform(&p, mx_rotation_z(M_PI_2, mx_rotation_y(-M_PI_4, translation(0, 0, 5, buf))));
// 	p.mat.col = fcolor(1, 0.9, 0.9);
// 	p.mat.pat.type = GRADIENT;
// 	p.mat.pat.a = fcolor(1, (float)170/255, 0);
// 	p.mat.pat.b = fcolor((float)173/255, (float)0, 1);
// 	set_pattern_transf(&p.mat.pat, mx_scaling(5, 1, 1, translation(-1, 0, 0, s.mat.pat.transf)));
// 	p.mat.has_pat = true;
// 	p.mat.specular = 0;
// 	add_world_obj(&w, p);
// 	p = plane();
// 	set_transform(&p, mx_rotation_z(M_PI_2, mx_rotation_y(M_PI_4, translation(0, 0, 5, buf))));
// 	p.mat.col = fcolor(1, 0.9, 0.9);
// 	p.mat.pat.type = GRADIENT;
// 	p.mat.pat.a = fcolor(1, (float)170/255, 0);
// 	p.mat.pat.b = fcolor((float)173/255, (float)0, 1);
// 	set_pattern_transf(&p.mat.pat, mx_scaling(5, 1, 1, translation(-1, 0, 0, s.mat.pat.transf)));
// 	p.mat.has_pat = true;
// 	p.mat.specular = 0;
// 	add_world_obj(&w, p);
// 	s = sphere();
// 	set_transform(&s,translation(0, 1, -1.2, buf));
// 	s.mat.col = fcolor(0, 1, 0);
// 	s.mat.specular = 0.3;
// 	s.mat.pat.type = GRADIENT;
// 	s.mat.pat.a = fcolor((float)72/255, (float)0/255, (float)152/255);
// 	s.mat.pat.b = fcolor((float)217/255, (float)0/255, (float)14/255);
// 	set_pattern_transf(&s.mat.pat,mx_scaling(2, 2, 2, translation(-1, 0, 0, s.mat.pat.transf)));
// 	s.mat.has_pat = true;
// 	s.mat.diffuse = 0.7;
// 	add_world_obj(&w, s);
// 	s = sphere();
// 	set_transform(&s,mx_scaling(0.5, 0.5, 0.5, translation(1.5, 1, -0.5, buf)));
// 	s.mat.col = fcolor(0.5, 1, 0.1);
// 	s.mat.has_pat = false;
// 	s.mat.specular = 0.3;
// 	s.mat.diffuse = 0.7;
// 	add_world_obj(&w, s);
// 	s = sphere();
// 	set_transform(&s,mx_rotation_y(M_PI_4, mx_rotation_x(0, mx_scaling(0.5, 0.5, 0.5, translation(-1, 0.5, -1, buf)))));
// 	s.mat.col = fcolor(1, 0.8, 0.1);
// 	s.mat.specular = 0.3;
// 	s.mat.pat.type = CHECKER;
// 	s.mat.pat.a = fcolor((float)18/255, (float)255/255, (float)93/255);
// 	s.mat.pat.b = fcolor((float)108/255, (float)200/255, (float)231/255);
// 	set_pattern_transf(&s.mat.pat,mx_scaling(0.2, 0.2, 0.2, translation(0, 0, 0, s.mat.pat.transf)));
// 	s.mat.has_pat = true;
// 	s.mat.diffuse = 0.7;
// 	add_world_obj(&w, s);
// 	render(&ctx->img, cam, &w);
// 	free_world(&w);
// 	// end_loop(&ctx->win);
// }

void	test_render(t_ctx * const ctx)
{
	t_mtx4		buf;
	t_world		w;
	world(&w);
	w.amb.i  = 0.4;
	w.amb.col = fcolor(1, 1, 1);
	t_obj		s;
	t_obj		p;
	t_light		l;
	t_camera	cam;

	cam = camera(WIN_W, WIN_H, M_PI / 2);
	set_cam_transform(&cam, mtx4_view(point(0, 1.5, -6), point(0, 1.5, 0), vector(0, 1, 0), buf));
	// mul_cam_transform(&cam, rotation_z(M_PI / 8, buf));
	l = light(point(0, 3.5, -5), fcolor(0.5, 0.5, 0.5), POINT);
	vct_add(&w.lights, &l);
	// l = light(point(-15, 5, -15), fcolor(1, 1, 1), POINT);
	// vct_add(&w.lights, &l);
	p = plane();
	set_transform(&p, mx_rotation_z(0, mx_rotation_x(M_PI_2, translation(0, 0, 3, buf))));
	p.mat.col = fcolor(1, 0.9, 0.9);
	p.mat.reflective = 0;
	p.mat.pat.type = CHECKER;
	p.mat.pat.a = fcolor(1, 0.8, 0.8);
	p.mat.pat.b = fcolor(0.1, 0.1, 0.1);
	set_pattern_transf(&p.mat.pat, mx_scaling(1, 1, 1, translation(-1, 0, 0, s.mat.pat.transf)));
	p.mat.has_pat = false;
	p.mat.specular = 0;
	add_world_obj(&w, p);

	set_transform(&p, mx_rotation_z(M_PI_2, mx_rotation_y(M_PI, translation(-4, 0, 0, buf))));
	add_world_obj(&w, p);

	set_transform(&p, mx_rotation_z(M_PI_2, mx_rotation_y(M_PI, translation(4, 0, 0, buf))));
	add_world_obj(&w, p);

	set_transform(&p, mx_rotation_z(0, mx_rotation_y(0, translation(0, -4, 0, buf))));
	add_world_obj(&w, p);

	set_transform(&p, mx_rotation_z(0, mx_rotation_y(0, translation(0, 5, 0, buf))));
	add_world_obj(&w, p);

	p = plane();
	set_transform(&p, mx_rotation_z(M_PI_2, mx_rotation_y(M_PI_2, translation(0, 0, -10, buf))));
	p.mat.col = fcolor(1, 0.9, 0.9);
	p.mat.pat.type = CHECKER;
	p.mat.pat.a = fcolor(1, 0.8, 0.8);
	p.mat.pat.b = fcolor(0.1, 0.1, 0.1);
	set_pattern_transf(&p.mat.pat, mx_scaling(1, 1, 1, translation(-1, 0, 0, s.mat.pat.transf)));
	p.mat.has_pat = false;
	p.mat.specular = 0;
	add_world_obj(&w, p);

	s = sphere();
	set_transform(&s,mx_rotation_y(M_PI_4, mx_rotation_x(0, mx_scaling(1, 1, 1, translation(0, 1.5, -2, buf)))));
	s.mat.col = fcolor(0.1, 0.1, 0.1);
	s.mat.specular = 0.3;
	s.mat.pat.type = CHECKER;
	s.mat.pat.a = fcolor((float)18/255, (float)255/255, (float)93/255);
	s.mat.pat.b = fcolor((float)108/255, (float)200/255, (float)231/255);
	s.mat.transparency = 1;
	s.mat.reflective = 1;
	s.mat.refractive = 1.5;
	set_pattern_transf(&s.mat.pat,mx_scaling(0.2, 0.2, 0.2, translation(0, 0, 0, s.mat.pat.transf)));
	s.mat.has_pat = false;
	s.mat.diffuse = 0.1;
	add_world_obj(&w, s);
	s = sphere();
	set_transform(&s,mx_rotation_y(M_PI_4, mx_rotation_x(0, mx_scaling(0.3, 0.3, 0.3, translation(0, 1.5, -2, buf)))));
	s.mat.col = fcolor(1, 1, 1);
	s.mat.specular = 0.3;
	s.mat.pat.type = CHECKER;
	s.mat.pat.a = fcolor((float)18/255, (float)255/255, (float)93/255);
	s.mat.pat.b = fcolor((float)108/255, (float)200/255, (float)231/255);
	s.mat.transparency = 1;
	s.mat.reflective = 1;
	s.mat.refractive = AIR_REFRACTIVE;
	set_pattern_transf(&s.mat.pat,mx_scaling(0.2, 0.2, 0.2, translation(0, 0, 0, s.mat.pat.transf)));
	s.mat.has_pat = false;
	s.mat.diffuse = 0.0;
	// add_world_obj(&w, s);
	s = sphere();
	set_transform(&s,mx_rotation_y(M_PI_4, mx_rotation_x(0, mx_scaling(0.6, 0.6, 0.6, translation(2, 1.5, -2.5, buf)))));
	s.mat.col = fcolor(1, 0.8, 0.1);
	s.mat.specular = 0.6;
	s.mat.pat.type = CHECKER;
	s.mat.pat.a = fcolor((float)18/255, (float)255/255, (float)93/255);
	s.mat.pat.b = fcolor((float)108/255, (float)200/255, (float)231/255);
	set_pattern_transf(&s.mat.pat,mx_scaling(0.2, 0.2, 0.2, translation(0, 0, 0, s.mat.pat.transf)));
	s.mat.has_pat = true;
	add_world_obj(&w, s);
	s = cube();
	set_transform(&s,mx_rotation_y(M_PI_2, mx_rotation_x(M_PI / 6, mx_scaling(0.6, 0.6, 0.6, translation(-2, 1.5, -2.5, buf)))));
	s.mat.col = fcolor(1, 1, 1);
	s.mat.specular = 0.6;
	s.mat.pat.type = CHECKER;
	s.mat.transparency = 1;
	s.mat.reflective = 0;
	s.mat.refractive = 1.5;
	s.mat.diffuse = 0.7;
	s.mat.pat.a = fcolor((float)18/255, (float)255/255, (float)93/255);
	s.mat.pat.b = fcolor((float)108/255, (float)200/255, (float)231/255);
	set_pattern_transf(&s.mat.pat,mx_scaling(0.6, 0.6, 0.6, translation(-1, 0,
	0, s
	.mat.pat.transf)));
	s.mat.has_pat = true;
	add_world_obj(&w, s);
		int32_t rays;
	rays = 0;
	while (++rays < RAY_NBR)
	{
		render(ctx, cam, &w, rays);
		put_img(&ctx->img, 0, 0, true);
	}
	free_world(&w);
	// end_loop(&ctx->win);
}

// void	test_render(t_ctx * const ctx)
// {
// 	t_mtx4		buf;
// 	t_world		w;
// 	world(&w);
// 	w.amb.i  = 0.4;
// 	w.amb.col = fcolor(1, 1, 1);
// 	t_obj		s;
// 	t_obj		p;
// 	t_light		l;
// 	t_camera	cam;

// 	cam = camera(WIN_W, WIN_H, M_PI / 1.6);
// 	set_cam_transform(&cam, mtx4_view(point(0, 1.5, -20), point(0, -5, 0), vector(0, 1, 0), buf));
// 	// mul_cam_transform(&cam, rotation_z(M_PI / 8, buf));
// 	l = light(point(0, 3.5, -5), fcolor(0.5, 0.5, 0.5), POINT);
// 	vct_add(&w.lights, &l);
// 	// l = light(point(-15, 5, -15), fcolor(1, 1, 1), POINT);
// 	// vct_add(&w.lights, &l);
// 	p = plane();
// 	set_transform(&p, mx_rotation_z(M_PI_2, mx_rotation_y(M_PI_2, translation(0, 0, 80, buf))));
// 	p.mat.col = fcolor(1, 0.9, 0.9);
// 	p.mat.pat.type = CHECKER;
// 	p.mat.pat.a = fcolor(0.5, 0.5, 0.5);
// 	p.mat.pat.b = fcolor(0.1, 0.1, 0.1);
// 	set_pattern_transf(&p.mat.pat, mx_scaling(1, 1, 1, translation(-1, 0, 0, s.mat.pat.transf)));
// 	p.mat.has_pat = true;
// 	p.mat.specular = 0;
// 	add_world_obj(&w, p);

// 	p = plane();
// 	set_transform(&p, mx_rotation_z(0, mx_rotation_y(0, translation(0, -5, 0, buf))));
// 	p.mat.col = fcolor(1, 0.9, 0.9);
// 	p.mat.pat.type = CHECKER;

// 	p.mat.pat.a = fcolor(0.3, 0.8, 0.8);
// 	p.mat.pat.b = fcolor(0.1, 0.7, 0.1);
// 	set_pattern_transf(&p.mat.pat, mx_scaling(2, 2, 2, translation(-1, 0, 0, s.mat.pat.transf)));
// 	p.mat.has_pat = true;
// 	p.mat.specular = 0;
// 	add_world_obj(&w, p);

// 	p = plane();
// 	set_transform(&p, mx_rotation_z(0, mx_rotation_y(0, translation(0, -0.5, 0, buf))));
// 	p.mat.col = fcolor(0.1, 0.13, 0.2);
// 	p.mat.pat.type = CHECKER;
// 	p.mat.pat.a = fcolor(1, 0.8, 0.8);
// 	p.mat.pat.b = fcolor(0.1, 0.1, 0.1);
// 	set_pattern_transf(&p.mat.pat, mx_scaling(3, 3, 3, translation(-1, 0, 0, s.mat.pat.transf)));
// 	p.mat.has_pat = false;
// 	p.mat.specular = 0.4;
// 	p.mat.diffuse = 0.7;
// 	p.mat.transparency = 1;
// 	p.mat.reflective = 0.4;
// 	p.mat.refractive = 1.33;
// 	add_world_obj(&w, p);

// 		int32_t rays;
// 	rays = 0;
// 	while (++rays < RAY_NBR)
// 	{
// 		render(ctx, cam, &w, rays);
// 		put_img(&ctx->img, 0, 0, true);
// 	}
// 	free_world(&w);
// 	// end_loop(&ctx->win);
// }

// void	test_render(t_ctx * const ctx)
// {
// 	t_mtx4		buf;
// 	t_world		w;
// 	world(&w);
// 	w.amb.i  = 0.4;
// 	w.amb.col = fcolor(1, 1, 1);
// 	t_obj		s;
// 	t_obj		c;
// 	t_light		l;
// 	t_camera	cam;

// 	cam = camera(WIN_W, WIN_H, M_PI / 2);
// 	set_cam_transform(&cam, mtx4_view(point(4, 4.5, -6), point(0, 0, 0), vector(0, 1, 0), buf));
// 	// mul_cam_transform(&cam, rotation_z(M_PI / 8, buf));
// 	l = light(point(10, 10, 10), fcolor(0.5, 0.5, 0.5), POINT);
// 	vct_add(&w.lights, &l);
// 	// l = light(point(-15, 5, -15), fcolor(1, 1, 1), POINT);
// 	// vct_add(&w.lights, &l)3
// 	w.back_col = fcolor((float)115/255, (float)205/255, (float)255/255);
// 	c = cube();
// 	c.mat.diffuse = 1;
// 	set_transform(&c, mx_scaling(10, 0.0001, 10, c.transform));
// 	add_world_obj(&w, c);
// 	s = cube();
// 	s.mat.col = fcolor(0.1, 0.1, 0.1);
// 	s.mat.transparency = 1;
// 	s.mat.reflective = 0.8;
// 	s.mat.refractive = 1.5;
// 	s.mat.diffuse = 0.2;
// 	set_transform(&s, mx_scaling(2, 2, 2, translation(-0.5, 2.01, -2, s.transform)));
// 	add_world_obj(&w, s);
// 	s = sphere();
// 	s.mat.col = fcolor((float)197/255, (float)186/255, (float)255/255);
// 	s.mat.pat.a = fcolor((float)197/255, (float)186/255, (float)255/255);
// 	s.mat.pat.b = fcolor((float)196/255, (float)217/255, (float)255/255);
// 	s.mat.pat.type = CHECKER;
// 	s.mat.has_pat = true;
// 	set_pattern_transf(&s.mat.pat, mx_scaling(0.2, 0.2, 0.2, translation(1, 0,
// 	0, s
// 	.mat.pat.transf)));
// 	set_transform(&s, mx_scaling(1, 1, 1, translation(-0.5, 2.01, -2, s.transform)));
// 	add_world_obj(&w, s);
// 	// int32_t rays;
// 	// rays = 0;
// 	// while (++rays < RAY_NBR)
// 	// {
// 	// 	render(ctx, cam, &w, rays);
// 	// 	put_img(&ctx->img, 0, 0, true);
// 	// }
// 	free_world(&w);
// 	// end_loop(&ctx->win);
// }

// void	test_render(t_ctx * const ctx)
// {
// 	t_mtx4		buf;
// 	t_world		w;
// 	world(&w);
// 	w.amb.i  = 0.4;
// 	w.amb.col = fcolor(1, 1, 1);
// 	t_obj		s;
// 	t_obj		c;
// 	t_light		l;
// 	t_camera	cam;
// 	int32_t rays;

// 	cam = camera(WIN_W, WIN_H, M_PI / 2);
// 	set_cam_transform(&cam, mtx4_view(point(4, 4.5, -6), point(0, 0, 0), vector(0, 1, 0), buf));
// 	// mul_cam_transform(&cam, rotation_z(M_PI / 8, buf));
// 	l = light(point(10, 10, 10), fcolor(0.5, 0.5, 0.5), POINT);
// 	vct_add(&w.lights, &l);
// 	// l = light(point(-15, 5, -15), fcolor(1, 1, 1), POINT);
// 	// vct_add(&w.lights, &l)3
// 	w.back_col = fcolor((float)115/255, (float)205/255, (float)255/255);
// 	c = cube();
// 	c.mat.diffuse = 1;
// 	set_transform(&c, mx_scaling(10, 0.0001, 10, c.transform));
// 	add_world_obj(&w, c);
// 	s = cube();
// 	s.mat.col = fcolor(0.1, 0.1, 0.1);
// 	s.mat.transparency = 1;
// 	s.mat.reflective = 0.8;
// 	s.mat.refractive = 1.5;
// 	s.mat.diffuse = 0.2;
// 	set_transform(&s, mx_scaling(2, 2, 2, translation(-0.5, 2.01, -2, s.transform)));
// 	add_world_obj(&w, s);
// 	s = sphere();
// 	s.mat.col = fcolor((float)197/255, (float)186/255, (float)255/255);
// 	s.mat.pat.a = fcolor((float)197/255, (float)186/255, (float)255/255);
// 	s.mat.pat.b = fcolor((float)196/255, (float)217/255, (float)255/255);
// 	s.mat.pat.type = CHECKER;
// 	s.mat.has_pat = true;
// 	set_pattern_transf(&s.mat.pat, mx_scaling(0.2, 0.2, 0.2, translation(1, 0,
// 	0, s
// 	.mat.pat.transf)));
// 	set_transform(&s, mx_scaling(1, 1, 1, translation(-0.5, 2.01, -2, s.transform)));
// 	add_world_obj(&w, s);
// 	rays = 0;
// 	while (++rays < RAY_NBR)
// 	{
// 		render(ctx, cam, &w, rays);
// 		put_img(&ctx->img, 0, 0, true);
// 	}
// 	free_world(&w);
// 	// end_loop(&ctx->win);
// }

// void	test_render(t_ctx * const ctx)
// {
// 	t_mtx4		buf;
// 	t_world		w;
// 	world(&w);
// 	w.amb.i  = 0.4;
// 	w.amb.col = fcolor(1, 1, 1);
// 	t_obj		s;
// 	t_obj		p;
// 	t_light		l;
// 	t_camera	cam;

// 	cam = camera(WIN_W, WIN_H, M_PI / 1.6);
// 	set_cam_transform(&cam, mtx4_view(point(0, 1.5, -20), point(0, -5, 0), vector(0, 1, 0), buf));
// 	// mul_cam_transform(&cam, rotation_z(M_PI / 8, buf));
// 	l = light(point(0, 3.5, -5), fcolor(0.5, 0.5, 0.5), POINT);
// 	vct_add(&w.lights, &l);
// 	// l = light(point(-15, 5, -15), fcolor(1, 1, 1), POINT);
// 	// vct_add(&w.lights, &l);
// 	p = plane();
// 	set_transform(&p, mx_rotation_z(M_PI_2, mx_rotation_y(M_PI_2, translation(0, 0, 40, buf))));
// 	p.mat.col = fcolor(1, 0.9, 0.9);
// 	p.mat.pat.type = CHECKER;
// 	p.mat.pat.a = fcolor(0.5, 0.5, 0.5);
// 	p.mat.pat.b = fcolor(0.1, 0.1, 0.1);
// 	set_pattern_transf(&p.mat.pat, mx_scaling(1, 1, 1, translation(-1, 0, 0, s.mat.pat.transf)));
// 	p.mat.has_pat = true;
// 	p.mat.specular = 0;
// 	add_world_obj(&w, p);

// 	p = plane();
// 	set_transform(&p, mx_rotation_z(0, mx_rotation_y(0, translation(0, -5, 0, buf))));
// 	p.mat.col = fcolor(1, 0.9, 0.9);
// 	p.mat.pat.type = CHECKER;

// 	p.mat.pat.a = fcolor(0.3, 0.8, 0.8);
// 	p.mat.pat.b = fcolor(0.1, 0.7, 0.1);
// 	set_pattern_transf(&p.mat.pat, mx_scaling(2, 2, 2, translation(-1, 0, 0, s.mat.pat.transf)));
// 	p.mat.has_pat = true;
// 	p.mat.specular = 0;
// 	add_world_obj(&w, p);

// 	p = plane();
// 	set_transform(&p, mx_rotation_z(0, mx_rotation_y(0, translation(0, -0.5, 0, buf))));
// 	p.mat.col = fcolor(0.1, 0.13, 0.2);
// 	p.mat.pat.type = CHECKER;
// 	p.mat.pat.a = fcolor(1, 0.8, 0.8);
// 	p.mat.pat.b = fcolor(0.1, 0.1, 0.1);
// 	set_pattern_transf(&p.mat.pat, mx_scaling(3, 3, 3, translation(-1, 0, 0, s.mat.pat.transf)));
// 	p.mat.has_pat = false;
// 	p.mat.specular = 0.4;
// 	p.mat.diffuse = 0.7;
// 	p.mat.transparency = 1;
// 	p.mat.reflective = 0.4;
// 	p.mat.refractive = 1.33;
// 	add_world_obj(&w, p);
// 	int rays;
// 	rays = 0;
// 	while (++rays < RAY_NBR)
// 	{
// 		render(ctx, cam, &w, rays);
// 		put_img(&ctx->img, 0, 0, true);
// 	}
// 	free_world(&w);
// 	// end_loop(&ctx->win);
// }
