/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:15:27 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 19:15:27 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
// #include "/sgoinfre/pjarnac/public/unit_tests/Unity/src/unity.h"
#include "../../includes/tuple.h"
#include "../../includes/normals.h"
#include "../../includes/fcolors.h"
#include "../../includes/rt_maths.h"
#include "../../includes/matrix.h"
#include "../../includes/ray.h"
#include "../../includes/objects.h"
#include "../../includes/patterns.h"
#include "../../lib/neflibx/includes/neflibx.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../includes/errors.h"
#include "../../includes/fcolors.h"
#include "../../includes/lighting.h"
#include "../../includes/render.h"
#include "../../includes/world.h"


void	test_ray_creation()
{
	t_tuple	pt = point(2, 3, 4);
	t_tuple	vt = vector(1, 0, 0);

	t_ray	r = ray(pt, vt);
	TEST_ASSERT(tp_equal(pt, r.origin));
	TEST_ASSERT(tp_equal(vt, r.dir));
}

void	test_ray_position()
{
	t_ray	r = ray(point(2, 3, 4), vector(1, 0.5, 0));

	TEST_ASSERT(tp_equal(point(2, 3, 4), position(r, 0)));
	TEST_ASSERT(tp_equal(point(3, 3.5, 4), position(r, 1)));
	TEST_ASSERT(tp_equal(point(1, 2.5, 4), position(r, -1)));
	TEST_ASSERT(tp_equal(point(4.5, 4.25, 4), position(r, 2.5)));
}

void	test_sphere_intersection_two_point()
{
	t_ray		r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter.count = 0;
	inter.i = malloc(sizeof (t_intersection) * 2);
	obj_intersect(r, &s, &inter);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(4, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(6, inter.i[1].t);
	free(inter.i);

}

void	test_sphere_intersection_tangent()
{
	t_ray		r = ray(point(0, 1, -5), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter.count = 0;
	inter.i = malloc(sizeof (t_intersection) * 2);
	obj_intersect(r, &s, &inter);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(5, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(5, inter.i[1].t);
	free(inter.i);

}

void	test_sphere_intersection_nothing()
{
	t_ray		r = ray(point(0, 2, -5), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter.count = 0;
	inter.i = malloc(sizeof (t_intersection) * 2);
	obj_intersect(r, &s, &inter);
	TEST_ASSERT_EQUAL_INT32(0, inter.count);
	free(inter.i);

}

void	test_sphere_intersection_inside()
{
	t_ray		r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter.count = 0;
	inter.i = malloc(sizeof (t_intersection) * 2);
	obj_intersect(r, &s, &inter);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(-1, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(1, inter.i[1].t);
	free(inter.i);

}

void	test_sphere_intersection_after()
{
	t_ray		r = ray(point(0, 0, 2), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter.count = 0;
	inter.i = malloc(sizeof (t_intersection) * 2);
	obj_intersect(r, &s, &inter);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(-3, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(-1, inter.i[1].t);
	free(inter.i);
}

void	test_sphere_intersection_objects()
{
	t_ray		r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter.count = 0;
	inter.i = malloc(sizeof (t_intersection) * 2);
	obj_intersect(r, &s, &inter);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(4, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(6, inter.i[1].t);
	TEST_ASSERT_EQUAL_PTR(&s, inter.i[0].obj);
	TEST_ASSERT_EQUAL_PTR(&s, inter.i[1].obj);
	free(inter.i);

}

void	test_intersections_hit()
{
	t_obj		s = sphere();
	t_intersections	xs = {2};

	xs.i = malloc(sizeof (t_intersection) * 2);
	xs.i[0] = intersection(1, &s);
	xs.i[1] = intersection(2, &s);
	TEST_ASSERT_EQUAL_PTR(&xs.i[0], hit(&xs));
	free(xs.i);
}

void	test_intersections_hit_negative()
{
	t_obj		s = sphere();
	t_intersections	xs = {2};

	xs.i = malloc(sizeof (t_intersection) * 2);
	xs.i[0] = intersection(-1, &s);
	xs.i[1] = intersection(2, &s);
	TEST_ASSERT_EQUAL_PTR(&xs.i[1], hit(&xs));
	free(xs.i);
}

void	test_intersections_hit_none()
{
	t_obj		s = sphere();
	t_intersections	xs = {2};

	xs.i = malloc(sizeof (t_intersection) * 2);
	xs.i[0] = intersection(-1, &s);
	xs.i[1] = intersection(-2, &s);
	TEST_ASSERT_EQUAL_PTR(NULL, hit(&xs));
	free(xs.i);
}

void	test_ray_transform_translate()
{
	t_ray	r = ray(point(1, 2, 3), vector(0, 1, 0));
	t_mtx4	trans;
	t_ray	r2;

	translation(3, 4, 5, trans);
	r2 = ray_transform(r, trans);
	TEST_ASSERT(tp_equal(point(4, 6, 8), r2.origin));
	TEST_ASSERT(tp_equal(vector(0, 1, 0), r2.dir));
}

void	test_ray_transform_scaling()
{
	t_ray	r = ray(point(1, 2, 3), vector(0, 1, 0));
	t_mtx4	trans;
	t_ray	r2;

	scaling(2, 3, 4, trans);
	r2 = ray_transform(r, trans);
	TEST_ASSERT(tp_equal(point(2, 6, 12), r2.origin));
	TEST_ASSERT(tp_equal(vector(0, 3, 0), r2.dir));
}

void	test_obj_transform()
{
	t_obj	s1 = sphere();
	t_obj	s2 = sphere();
	t_mtx4	transf;

	TEST_ASSERT(mtx4_equal(g_identity_matrix, s1.transform));
	translation(1, 2, 3, transf);
	mul_transform(&s2, transf);
	TEST_ASSERT(mtx4_equal(transf, s2.transform));
}

void	test_scaled_sphere_intersection()
{
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj			s = sphere();
	t_intersections	xs;
	t_mtx4			transf;

	xs.count = 0;
	xs.i = malloc(sizeof (t_intersection) * 2);
	mul_transform(&s, scaling(2, 2, 2, transf));
	obj_intersect(r, &s, &xs);
	TEST_ASSERT_EQUAL_INT32(2, xs.count);
	TEST_ASSERT_EQUAL_FLOAT(3, xs.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(7, xs.i[1].t);
	free(xs.i);
}

void	test_translated_sphere_intersection()
{
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj			s = sphere();
	t_intersections	xs;
	t_mtx4			transf;

	xs.count = 0;
	xs.i = malloc(sizeof (t_intersection) * 2);
	mul_transform(&s, translation(5, 0, 0, transf));
	obj_intersect(r, &s, &xs);
	TEST_ASSERT_EQUAL_INT32(0, xs.count);
	free(xs.i);
}

void	test_sphere_normal()
{
	t_obj	s = sphere();

	TEST_ASSERT(tp_equal(vector(1, 0, 0), obj_normal(&s, point(1, 0, 0))));
	TEST_ASSERT(tp_equal(vector(0, 1, 0), obj_normal(&s, point(0, 1, 0))));
	TEST_ASSERT(tp_equal(vector(0, 0, 1), obj_normal(&s, point(0, 0, 1))));
	TEST_ASSERT(tp_equal(vector(sqrtf(3) / 3, sqrtf(3) / 3, sqrtf(3) / 3), obj_normal(&s, point(sqrtf(3) / 3,sqrtf(3) / 3, sqrtf(3) / 3))));
}

void	test_sphere_normal_is_normal()
{
	t_obj	s = sphere();
	t_tuple	n = obj_normal(&s, point(sqrtf(3) / 3,sqrtf(3) / 3, sqrtf(3) / 3));
	TEST_ASSERT(tp_equal(n, tp_normalize(n)));
}

void	test_translated_sphere_normal()
{
	t_obj	s = sphere();
	t_mtx4	buf;

	mul_transform(&s, translation(0, 1, 0, buf));
	TEST_ASSERT(tp_equal(vector(0, 0.70711, -0.70711), obj_normal(&s, point(0, 1.70711, -0.70711))));
	s = sphere();
	mul_transform(&s, mx_rotation_z(M_PI / 5, scaling(1, 0.5, 1, buf)));
	TEST_ASSERT(tp_equal(vector(0, 0.97014, -0.24254), obj_normal(&s, point(0, sqrtf(2) / 2, -sqrtf(2) / 2))));
}

void	test_vector_reflect_45()
{
	TEST_ASSERT(tp_equal(vector(1, 1, 0), reflect(vector(1, -1, 0), vector(0, 1, 0))));
}

void	test_vector_reflect_slanted()
{
	TEST_ASSERT(tp_equal(vector(1, 0, 0), reflect(vector(0, -1, 0), vector(sqrtf(2) / 2, sqrtf(2) / 2, 0))));
}

void	assert_fcolor(t_fcolor c1, t_fcolor c2)
{
	TEST_ASSERT_MESSAGE(f_equal(c1.r, c2.r), "red composant is not equal");
	TEST_ASSERT_MESSAGE(f_equal(c1.g, c2.g), "green composant is not equal");
	TEST_ASSERT_MESSAGE(f_equal(c1.b, c2.b), "blue composant is not equal");
}

void	test_direct_light_eye()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, -10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv, false, pos};
	t_fcolor		col;

	col = phong(g_default_mat, l, &c);
	assert_fcolor(fcolor(1.9 - 0.1, 1.9 - 0.1, 1.9 - 0.1), col);
}

void	test_direct_light_eye_45()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, sqrtf(2) / 2, -sqrtf(2) / 2);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, -10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv, false, pos};

	assert_fcolor(fcolor(1.0 - 0.1, 1.0 - 0.1, 1.0 - 0.1), phong(g_default_mat, l, &c));
}

void	test_direct_light_45_eye()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 10, -10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv, false, pos};

	assert_fcolor(fcolor(0.7364 - 0.1, 0.7364 - 0.1, 0.7364 - 0.1), phong(g_default_mat, l, &c));
}

void	test_direct_light_45_eye_45()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, -sqrtf(2) / 2, -sqrtf(2) / 2);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 10, -10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv, false, pos};

	assert_fcolor(fcolor(1.6364 - 0.1, 1.6364 - 0.1, 1.6364 - 0.1), phong(g_default_mat, l, &c));
}

void	test_direct_light_eye_behind()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, 10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv, false, pos};

	assert_fcolor(fcolor(0.1 - 0.1, 0.1 - 0.1, 0.1 - 0.1), phong(g_default_mat, l, &c));
}

void	test_world_intersection()
{
	t_world			w;
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_intersections	xs;

	default_world(&w);
	xs = world_intersec(&w, r);
	TEST_ASSERT_EQUAL_INT32(4, xs.count);
	TEST_ASSERT_EQUAL_FLOAT(4, xs.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(4.5, xs.i[1].t);
	TEST_ASSERT_EQUAL_FLOAT(5.5, xs.i[2].t);
	TEST_ASSERT_EQUAL_FLOAT(6, xs.i[3].t);
	w.xs.count -= xs.count;
	free_world(&w);
}

void	test_pre_compute_outside()
{
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj	o = sphere();
	t_intersection	i = intersection(4, &o);
	t_pre_compute	pc;

	pc = pre_compute(&i, r, 0);
	TEST_ASSERT(pc.inside == false);
}

void	test_pre_compute_inside()
{
	t_ray			r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_obj			o = sphere();
	t_intersection	i = intersection(1, &o);
	t_pre_compute	pc;

	pc = pre_compute(&i, r, 0);
	TEST_ASSERT(pc.inside == true);
	TEST_ASSERT(tp_equal(point(0, 0, 1), pc.pos));
	TEST_ASSERT(tp_equal(vector(0, 0, -1), pc.eyev));
	TEST_ASSERT(tp_equal(vector(0, 0, -1), pc.normalv));
}

void	test_light_hit()
{
	t_world	w;
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_intersection	i;
	t_pre_compute	pc;

	default_world(&w);
	i = intersection(4, w.objs);
	pc = pre_compute(&i, r, 0);
	assert_fcolor(fcolor(0.38066, 0.47583, 0.2855), light_hit(&w, &pc, 1));
	free_world(&w);
}

void	test_light_hit_inside()
{
	t_world	w;
	t_ray	r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_intersection	i;
	t_pre_compute	pc;

	default_world(&w);
	w.lights[0] = light(point(0, 0.25, 0), fcolor(1, 1, 1), POINT);
	i = intersection(0.5, w.objs + 1);
	pc = pre_compute(&i, r, 0);
	assert_fcolor(fcolor(0.90498, 0.90498, 0.90498), light_hit(&w, &pc, 1));
	free_world(&w);
}

void	test_color_ray_miss()
{
	t_world	w;
	t_ray	r = ray(point(0, 0, -5), vector(0, 1, 0));

	default_world(&w);
	assert_fcolor(fcolor(0, 0, 0), color_at(&w, r, 1));
	free_world(&w);
}

void	test_color_ray_hit()
{
	t_world	w;
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));

	default_world(&w);
	assert_fcolor(fcolor(0.38066, 0.47583, 0.2855), color_at(&w, r, 1));
	free_world(&w);
}

void	test_color_ray_hit_behind()
{
	t_world	w;
	t_ray	r = ray(point(0, 0, 0.75), vector(0, 0, -1));

	default_world(&w);
	w.amb.i = 1;
	w.amb.col = fcolor(1, 1, 1);
	assert_fcolor(w.objs[1].mat.col, color_at(&w, r, 1));
	free_world(&w);
}

void	test_mtx_view()
{
	t_mtx4	buf;

	mtx4_view(point(0, 0, 0), point(0, 0, -1), vector(0, 1, 0), buf);
	TEST_ASSERT(mtx4_equal(g_identity_matrix, buf));
}

void	test_mtx_view_back()
{
	t_mtx4	buf;
	t_mtx4	buf2;

	mtx4_view(point(0, 0, 0), point(0, 0, 1), vector(0, 1, 0), buf);
	scaling(-1, 1, -1, buf2);
	TEST_ASSERT(mtx4_equal(buf2, buf));
}

void	test_mtx_view_move()
{
	t_mtx4	buf;
	t_mtx4	buf2;

	mtx4_view(point(0, 0, 8), point(0, 0, 0), vector(0, 1, 0), buf);
	TEST_ASSERT(mtx4_equal(translation(0, 0, -8, buf2), buf));
}

void	test_mtx_view_arbitraty()
{
	t_mtx4	buf;
	t_mtx4	buf2 = {
		{-0.50709, 0.50709, 0.67612, -2.36643},
		{0.76772, 0.60609, 0.12122, -2.82843},
		{-0.35857, 0.59761, -0.71714, 0.00000},
		{0, 0, 0, 1}
	};

	mtx4_view(point(1, 3, 2), point(4, -2, 8), vector(1, 1, 0), buf);
	TEST_ASSERT(mtx4_equal(buf2, buf));
}

void	test_pixel_size_calculation_h()
{
	t_camera	cam = camera(200, 125, M_PI_2);

	TEST_ASSERT_EQUAL_FLOAT(0.01, cam.pixel_size);
}

void	test_pixel_size_calculation_v()
{
	t_camera	cam = camera(125, 200, M_PI_2);

	TEST_ASSERT_EQUAL_FLOAT(0.01, cam.pixel_size);
}

void	test_pixel_ray_center()
{
	t_camera cam = camera(201, 101, M_PI_2);
	t_ray	ray = ray_for_pixel(cam, 100, 50);

	TEST_ASSERT(tp_equal(point(0, 0, 0), ray.origin));
	TEST_ASSERT(tp_equal(vector(0, 0, -1), ray.dir));
}

void	test_pixel_ray_corner()
{
	t_camera cam = camera(201, 101, M_PI_2);
	t_ray	ray = ray_for_pixel(cam, 0, 0);

	TEST_ASSERT(tp_equal(point(0, 0, 0), ray.origin));
	TEST_ASSERT(tp_equal(vector(0.66519, 0.33259, -0.66851), ray.dir));
}

void	test_pixel_ray_cam_trans()
{
	t_camera cam = camera(201, 101, M_PI_2);
	t_ray	ray;
	t_mtx4	buf;

	set_cam_transform(&cam, mx_translation(0, -2, 5, rotation_y(M_PI_4, buf)));
	ray = ray_for_pixel(cam, 100, 50);
	TEST_ASSERT(tp_equal(point(0, 2, -5), ray.origin));
	TEST_ASSERT(tp_equal(vector(sqrtf(2) / 2, 0, -sqrtf(2) / 2), ray.dir));
}

void	test_render_at()
{
	t_image		img;
	t_window	win;
	t_world		w;
	t_camera	cam;
	t_mtx4		view;

	init_window(&win, 11, 11, "unit test");
	create_image(&img, 11, 11, &win);
	default_world(&w);
	cam = camera(11, 11, M_PI_2);
	mtx4_view(point(0, 0, -5), point(0, 0, 0), vector(0, 1, 0), view);
	set_cam_transform(&cam, view);
	render(&img, cam, &w);
	put_img(&img, 0, 0, false);
	assert_fcolor(fcolor(0.38066, 0.47583, 0.2855), color_at(&w, ray_for_pixel(cam, 5, 5), 1));
	destroy_image(&img);
	destroy_window(&win);
	free_world(&w);
}

void	test_point_not_shadow()
{
	t_world	w;

	default_world(&w);
	TEST_ASSERT(is_in_shadow(&w, point(0, 10, 0), &w.lights[0]) == false);
	free_world(&w);
}

void	test_point_shadow()
{
	t_world	w;

	default_world(&w);
	TEST_ASSERT(is_in_shadow(&w, point(10, -10, 10), &w.lights[0]) == false);
	free_world(&w);
}

void	test_point_not_shadow_behind()
{
	t_world	w;

	default_world(&w);
	TEST_ASSERT(is_in_shadow(&w, point(-20, 20, -20), &w.lights[0]) == false);
	free_world(&w);
}

void	test_point_not_shadow_mid()
{
	t_world	w;

	default_world(&w);
	TEST_ASSERT(is_in_shadow(&w, point(-2, 2, -2), &w.lights[0]) == false);
	free_world(&w);
}

void	test_offset_hit()
{
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj	s = sphere();
	t_intersection	i;
	t_pre_compute	pc;

	set_transform(&s, translation(0, 0, 1, s.transform));
	i = intersection(5, &s);
	pc = pre_compute(&i, r, 0);
	TEST_ASSERT_LESS_THAN_DOUBLE(-DEPSILON/2, pc.over_point.z);
	TEST_ASSERT_GREATER_THAN_DOUBLE(pc.over_point.z, pc.pos.z);
}

void	test_plane_normal()
{
	t_obj	p = plane();

	TEST_ASSERT(tp_equal(vector(0, 1, 0), obj_normal(&p, point(0, 0, 0))));
	TEST_ASSERT(tp_equal(vector(0, 1, 0), obj_normal(&p, point(10, 0, 0))));
	TEST_ASSERT(tp_equal(vector(0, 1, 0), obj_normal(&p, point(-500, 0, 1500))));
}

void	test_plane_inter_coplanar_miss()
{
	t_obj	p = plane();
	t_ray	r = ray(point(0, 10, 0), vector(0, 0, 1));
	t_intersections	xs;

	xs.count = 0;
	xs.i = malloc(sizeof (t_intersection));
	obj_intersect(r, &p, &xs);
	TEST_ASSERT_EQUAL_INT32(0, xs.count);
	free(xs.i);
}

void	test_plane_inter_coplanar_on()
{
	t_obj	p = plane();
	t_ray	r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_intersections	xs;

	xs.count = 0;
	xs.i = malloc(sizeof (t_intersection));
	obj_intersect(r, &p, &xs);
	TEST_ASSERT_EQUAL_INT32(0, xs.count);
	free(xs.i);
}

void	test_plane_inter_hit_above()
{
	t_obj	p = plane();
	t_ray	r = ray(point(0, 1, 0), vector(0, -1, 0));
	t_intersections	xs;

	xs.count = 0;
	xs.i = malloc(sizeof (t_intersection));
	obj_intersect(r, &p, &xs);
	TEST_ASSERT_EQUAL_INT32(1, xs.count);
	TEST_ASSERT_EQUAL_PTR(&p, xs.i[0].obj);
	free(xs.i);
}

void	test_plane_inter_hit_below()
{
	t_obj	p = plane();
	t_ray	r = ray(point(0, -1, 0), vector(0, 1, 0));
	t_intersections	xs;

	xs.count = 0;
	xs.i = malloc(sizeof (t_intersection));
	obj_intersect(r, &p, &xs);
	TEST_ASSERT_EQUAL_INT32(1, xs.count);
	TEST_ASSERT_EQUAL_PTR(&p, xs.i[0].obj);
	free(xs.i);
}

t_fcolor const	white = {1, 1, 1};
t_fcolor const	black = {0, 0, 0};

void	test_stripe_pattern_y()
{
	t_pattern	pat = pattern(white, black, STRIPE);

	assert_fcolor(white, stripe_at(pat, point(0, 0, 0)));
	assert_fcolor(white, stripe_at(pat, point(0, 1, 0)));
	assert_fcolor(white, stripe_at(pat, point(0, 2, 0)));
}

void	test_stripe_pattern_z()
{
	t_pattern	pat = pattern(white, black, STRIPE);

	assert_fcolor(white, stripe_at(pat, point(0, 0, 0)));
	assert_fcolor(white, stripe_at(pat, point(0, 0, 1)));
	assert_fcolor(white, stripe_at(pat, point(0, 0, 2)));
}

void	test_stripe_pattern_x()
{
	t_pattern	pat = pattern(white, black, STRIPE);

	assert_fcolor(white, stripe_at(pat, point(0, 0, 0)));
	assert_fcolor(white, stripe_at(pat, point(0.9, 0, 0)));
	assert_fcolor(black, stripe_at(pat, point(1, 0, 0)));
	assert_fcolor(black, stripe_at(pat, point(-0.1, 0, 0)));
	assert_fcolor(black, stripe_at(pat, point(-1, 0, 0)));
	assert_fcolor(white, stripe_at(pat, point(-1.1, 0, 0)));
}

void	test_pattern_obj_transform()
{
	t_obj		o = sphere();
	t_pattern	pat = pattern(white, black, STRIPE);

	set_transform(&o, scaling(2, 2, 2, o.transform));
	assert_fcolor(white, pattern_at_obj(pat, &o, point(1.5, 0, 0)));
}

void	test_pattern_pat_transform()
{
	t_obj		o = sphere();
	t_pattern	pat = pattern(white, black, STRIPE);

	set_pattern_transf(&pat, scaling(2, 2, 2, pat.transf));
	assert_fcolor(white, pattern_at_obj(pat, &o, point(1.5, 0, 0)));
}

void	test_pattern_obj_pat_transform()
{
	t_obj		o = sphere();
	t_pattern	pat = pattern(white, black, STRIPE);

	set_pattern_transf(&pat, translation(0.5, 0, 0, pat.transf));
	set_transform(&o, scaling(2, 2, 2, o.transform));
	assert_fcolor(black, pattern_at_obj(pat, &o, point(2.5, 0, 0)));
}

void	test_pattern_gradient()
{
	t_pattern	pat = pattern(white, black, GRADIENT);

	assert_fcolor(white, gradient_at(pat, point(0, 0, 0)));
	assert_fcolor(fcolor(0.75, 0.75, 0.75), gradient_at(pat, point(0.25, 0, 0)));
	assert_fcolor(fcolor(0.5, 0.5, 0.5), gradient_at(pat, point(0.5, 0, 0)));
	assert_fcolor(fcolor(0.25, 0.25, 0.25), gradient_at(pat, point(0.75, 0, 0)));
}

void	test_pattern_ring()
{
	t_pattern	pat = pattern(white, black, RING);

	assert_fcolor(white, ring_at(pat, point(0, 0, 0)));
	assert_fcolor(black, ring_at(pat, point(1, 0, 0)));
	assert_fcolor(black, ring_at(pat, point(0, 0, 1)));
	assert_fcolor(black, ring_at(pat, point(0.708, 0, 0.708)));
}

void	test_pattern_checker()
{
	t_pattern	pat = pattern(white, black, CHECKER);

	assert_fcolor(white, checker_at(pat, point(0, 0, 0)));
	assert_fcolor(white, checker_at(pat, point(0.99, 0, 0)));
	assert_fcolor(black, checker_at(pat, point(1.01, 0, 0)));

	assert_fcolor(white, checker_at(pat, point(0, 0, 0)));
	assert_fcolor(white, checker_at(pat, point(0, 0, 0.99)));
	assert_fcolor(black, checker_at(pat, point(0, 0, 1.01)));

	assert_fcolor(white, checker_at(pat, point(0, 0, 0)));
	assert_fcolor(white, checker_at(pat, point(0, 0.99, 0)));
	assert_fcolor(black, checker_at(pat, point(0, 1.01, 0)));

	assert_fcolor(black, checker_at(pat, point(2, 1, 0)));
}

void	test_reflectv_precomputation()
{
	t_obj	p = plane();
	t_ray	r = ray(point(0, 1, -1), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	t_intersection	i = intersection(sqrt(2), &p);
	t_pre_compute	pc = pre_compute(&i, r, 0);

	TEST_ASSERT(tp_equal(vector(0, sqrt(2) / 2, sqrt(2) / 2), pc.reflectv));
}

void	test_reflect_inside()
{
	t_world	w;
	default_world(&w);
	t_ray	r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_obj	*s = w.objs + 1;
	w.amb.col = fcolor(1, 1, 1);
	w.amb.i = 1;
	t_intersection	i = intersection(1, s);
	t_pre_compute	pc = pre_compute(&i, r, 0);

	assert_fcolor(fcolor(0, 0, 0), reflect_color(&w, &pc, 1));
	free_world(&w);
}

void	test_reflect()
{
	t_world	w;
	default_world(&w);
	t_ray	r = ray(point(0, 0, -3), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	w.amb.col = fcolor(1, 1, 1);
	w.amb.i = 0.1;
	t_obj	p = plane();
	p.mat.reflective = 0.5;
	set_transform(&p, translation(0, -1, 0, p.transform));
	add_world_obj(&w, p);
	t_intersection	i = intersection(sqrt(2), &w.objs[2]);
	t_pre_compute	pc = pre_compute(&i, r, 0);

	assert_fcolor(fcolor(0.19032, 0.2379, 0.14274), reflect_color(&w, &pc, 1));
	free_world(&w);
}

void	test_infinite_reflect()
{
	t_world	w;
	world(&w);
	t_ray	r = ray(point(0, 0, 0), vector(0, 1, 0));
	w.amb.col = fcolor(1, 1, 1);
	w.amb.i = 0.1;
	vct_add(&w.lights, &(t_light){POINT, point(0, 0, 0), fcolor(1, 1, 1)});
	t_obj	p = plane();
	p.mat.reflective = 1;
	set_transform(&p, translation(0, -1, 0, p.transform));
	add_world_obj(&w, p);
	p = plane();
	p.mat.reflective = 1;
	set_transform(&p, translation(0, 1, 0, p.transform));
	add_world_obj(&w, p);

	color_at(&w, r, 6);
	free_world(&w);
}

void	test_refractive_points_calculation()
{
	t_ray	r = ray(point(0, 0, -4), vector(0, 0, 1));
	t_obj	s1 = glass_sphere();
	t_obj	s2 = glass_sphere();
	t_obj	s3 = glass_sphere();
	t_intersections	xs;
	t_pre_compute	pc;

	set_transform(&s1, scaling(2, 2, 2, s1.transform));
	set_transform(&s2, translation(0, 0, -0.25, s1.transform));
	s2.mat.refractive = 2;
	set_transform(&s3, translation(0, 0, 0.25, s1.transform));
	s3.mat.refractive = 2.5;
	xs.count = 6;
	xs.i = malloc(sizeof (t_intersection) * 6 * 2);
	xs.i[0] = intersection(2, &s1);
	xs.i[1] = intersection(2.75, &s2);
	xs.i[2] = intersection(3.25, &s3);
	xs.i[3] = intersection(4.75, &s2);
	xs.i[4] = intersection(5.25, &s3);
	xs.i[5] = intersection(6, &s1);
	pc = pre_compute(xs.i + 0, r, &xs);
	TEST_ASSERT_EQUAL_DOUBLE(AIR_REFRACTIVE, pc.n1);
	TEST_ASSERT_EQUAL_DOUBLE(1.5, pc.n2);
	pc = pre_compute(xs.i + 1, r, &xs);
	TEST_ASSERT_EQUAL_DOUBLE(1.5, pc.n1);
	TEST_ASSERT_EQUAL_DOUBLE(2, pc.n2);
	pc = pre_compute(xs.i + 2, r, &xs);
	TEST_ASSERT_EQUAL_DOUBLE(2, pc.n1);
	TEST_ASSERT_EQUAL_DOUBLE(2.5, pc.n2);
	pc = pre_compute(xs.i + 3, r, &xs);
	TEST_ASSERT_EQUAL_DOUBLE(2.5, pc.n1);
	TEST_ASSERT_EQUAL_DOUBLE(2.5, pc.n2);
	pc = pre_compute(xs.i + 4, r, &xs);
	TEST_ASSERT_EQUAL_DOUBLE(2.5, pc.n1);
	TEST_ASSERT_EQUAL_DOUBLE(1.5, pc.n2);
	pc = pre_compute(xs.i + 5, r, &xs);
	TEST_ASSERT_EQUAL_DOUBLE(1.5, pc.n1);
	TEST_ASSERT_EQUAL_DOUBLE(AIR_REFRACTIVE, pc.n2);
	free(xs.i);
}

void	test_underpoint_compute()
{
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj	o = glass_sphere();
	set_transform(&o, translation(0, 0, 1, o.transform));
	t_intersection	i = intersection(5, &o);
	t_pre_compute	pc = pre_compute(&i, r, 0);
	TEST_ASSERT_GREATER_THAN_DOUBLE(DEPSILON / 2, pc.under_point.z);
	TEST_ASSERT_GREATER_THAN_DOUBLE(pc.pos.z, pc.under_point.z);
}

void	test_refract_opaque()
{
	t_world	w;
	default_world(&w);
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	w.amb.col = fcolor(1, 1, 1);
	w.amb.i = 0.1;
	t_obj	*o = w.objs;
	t_intersections	xs;
	xs.count = 2;
	xs.i = malloc(sizeof (t_intersection) * 2 * 2);
	xs.i[0].obj = o;
	xs.i[0].t = 4;
	xs.i[1].obj = o;
	xs.i[1].t = 6;
	t_pre_compute	pc = pre_compute(&xs.i[0], r, &xs);

	assert_fcolor(fcolor(0, 0, 0), refract_color(&w, &pc, 5));
	free(xs.i);
	free_world(&w);
}

void	test_refract_max_recur()
{
	t_world	w;
	default_world(&w);
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	w.amb.col = fcolor(1, 1, 1);
	w.amb.i = 0.1;
	t_obj	*o = w.objs;
	t_intersections	xs;
	xs.count = 2;
	xs.i = malloc(sizeof (t_intersection) * 2 * 2);
	xs.i[0].obj = o;
	xs.i[0].t = 4;
	xs.i[1].obj = o;
	xs.i[1].t = 6;
	t_pre_compute	pc = pre_compute(&xs.i[0], r, &xs);

	assert_fcolor(fcolor(0, 0, 0), refract_color(&w, &pc, 0));
	free(xs.i);
	free_world(&w);
}

void	test_refract_total_internal()
{
	t_world	w;
	default_world(&w);
	t_ray	r = ray(point(0, 0, sqrt(2) / 2), vector(0, 1, 0));
	w.amb.col = fcolor(1, 1, 1);
	w.amb.i = 0.1;
	t_obj	*o = w.objs;
	o->mat.transparency = 1;
	o->mat.refractive = 1.5;
	t_intersections	xs;
	xs.count = 2;
	xs.i = malloc(sizeof (t_intersection) * 2 * 2);
	xs.i[0].obj = o;
	xs.i[0].t = -sqrt(2) / 2;
	xs.i[1].obj = o;
	xs.i[1].t = sqrt(2) / 2;
	t_pre_compute	pc = pre_compute(&xs.i[1], r, &xs);

	assert_fcolor(fcolor(0, 0, 0), refract_color(&w, &pc, 5));
	free(xs.i);
	free_world(&w);
}

void	test_schlick_total_internal()
{
	t_obj	o = glass_sphere();
	t_ray	r = ray(point(0, 0, sqrt(2) / 2), vector(0, 1, 0));
	t_intersections	xs;
	xs.count = 2;
	xs.i = malloc(sizeof (t_intersection) * 2 * 2);
	xs.i[0].obj = &o;
	xs.i[0].t = -sqrt(2) / 2;
	xs.i[1].obj = &o;
	xs.i[1].t = sqrt(2) / 2;
	t_pre_compute	pc = pre_compute(xs.i + 1, r, &xs);
	TEST_ASSERT_EQUAL_DOUBLE(1.0, schlick(&pc));
	free(xs.i);
}

void	test_schlick_perpidencular()
{
	t_obj	o = glass_sphere();
	t_ray	r = ray(point(0, 0, 0), vector(0, 1, 0));
	t_intersections	xs;
	xs.count = 2;
	xs.i = malloc(sizeof (t_intersection) * 2 * 2);
	xs.i[0].obj = &o;
	xs.i[0].t = -1;
	xs.i[1].obj = &o;
	xs.i[1].t = 1;
	t_pre_compute	pc = pre_compute(xs.i + 1, r, &xs);
	TEST_ASSERT(d_equal(0.0399443458, schlick(&pc)));
	free(xs.i);
}

void	test_schlick_n2big_n1()
{
	t_obj	o = glass_sphere();
	t_ray	r = ray(point(0, 0.99, -2), vector(0, 0, 1));
	t_intersections	xs;
	xs.count = 1;
	xs.i = malloc(sizeof (t_intersection) * 1 * 2);
	xs.i[0].obj = &o;
	xs.i[0].t = 1.8589;
	t_pre_compute	pc = pre_compute(xs.i, r, &xs);
	TEST_ASSERT(d_equal(0.488701143, schlick(&pc)));
	free(xs.i);
}

int	test_rays()
{
	RUN_TEST(test_ray_creation);
	RUN_TEST(test_ray_position);
	RUN_TEST(test_sphere_intersection_two_point);
	RUN_TEST(test_sphere_intersection_tangent);
	RUN_TEST(test_sphere_intersection_nothing);
	RUN_TEST(test_sphere_intersection_inside);
	RUN_TEST(test_sphere_intersection_after);
	RUN_TEST(test_sphere_intersection_objects);
	RUN_TEST(test_intersections_hit);
	RUN_TEST(test_intersections_hit_negative);
	RUN_TEST(test_intersections_hit_none);
	RUN_TEST(test_ray_transform_translate);
	RUN_TEST(test_ray_transform_scaling);
	RUN_TEST(test_obj_transform);
	RUN_TEST(test_scaled_sphere_intersection);
	RUN_TEST(test_translated_sphere_intersection);
	RUN_TEST(test_sphere_normal);
	RUN_TEST(test_sphere_normal_is_normal);
	RUN_TEST(test_translated_sphere_normal);
	RUN_TEST(test_vector_reflect_45);
	RUN_TEST(test_vector_reflect_slanted);
	RUN_TEST(test_direct_light_eye);
	RUN_TEST(test_direct_light_eye_45);
	RUN_TEST(test_direct_light_45_eye);
	RUN_TEST(test_direct_light_45_eye_45);
	RUN_TEST(test_direct_light_eye_behind);
	RUN_TEST(test_world_intersection);
	RUN_TEST(test_pre_compute_inside);
	RUN_TEST(test_pre_compute_outside);
	RUN_TEST(test_light_hit);
	RUN_TEST(test_light_hit_inside);
	RUN_TEST(test_color_ray_hit);
	RUN_TEST(test_color_ray_hit_behind);
	RUN_TEST(test_color_ray_miss);
	RUN_TEST(test_mtx_view);
	RUN_TEST(test_mtx_view_back);
	RUN_TEST(test_mtx_view_move);
	RUN_TEST(test_mtx_view_arbitraty);
	RUN_TEST(test_pixel_size_calculation_h);
	RUN_TEST(test_pixel_size_calculation_v);
	RUN_TEST(test_pixel_ray_center);
	RUN_TEST(test_pixel_ray_corner);
	RUN_TEST(test_pixel_ray_cam_trans);
	RUN_TEST(test_render_at);
	RUN_TEST(test_point_not_shadow);
	RUN_TEST(test_point_shadow);
	RUN_TEST(test_point_not_shadow_behind);
	RUN_TEST(test_point_not_shadow_mid);
	RUN_TEST(test_offset_hit);
	RUN_TEST(test_plane_normal);
	RUN_TEST(test_plane_inter_coplanar_miss);
	RUN_TEST(test_plane_inter_coplanar_on);
	RUN_TEST(test_plane_inter_hit_above);
	RUN_TEST(test_plane_inter_hit_below);
	RUN_TEST(test_stripe_pattern_x);
	RUN_TEST(test_stripe_pattern_y);
	RUN_TEST(test_stripe_pattern_z);
	RUN_TEST(test_pattern_obj_pat_transform);
	RUN_TEST(test_pattern_pat_transform);
	RUN_TEST(test_pattern_obj_transform);
	RUN_TEST(test_pattern_gradient);
	RUN_TEST(test_pattern_ring);
	RUN_TEST(test_pattern_checker);
	RUN_TEST(test_reflectv_precomputation);
	RUN_TEST(test_reflect_inside);
	RUN_TEST(test_reflect);
	RUN_TEST(test_infinite_reflect);
	RUN_TEST(test_refractive_points_calculation);
	RUN_TEST(test_underpoint_compute);
	RUN_TEST(test_refract_max_recur);
	RUN_TEST(test_refract_total_internal);
	RUN_TEST(test_refract_opaque);
	RUN_TEST(test_schlick_total_internal);
	RUN_TEST(test_schlick_perpidencular);
	RUN_TEST(test_schlick_n2big_n1);
	return 0;
}
