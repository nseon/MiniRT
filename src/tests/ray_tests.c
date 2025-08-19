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

#include "/sgoinfre/pjarnac/public/unit_tests/Unity/src/unity.h"
#include "../../includes/tuple.h"
#include "../../includes/normals.h"
#include "../../includes/fcolors.h"
#include "../../includes/rt_maths.h"
#include "../../includes/matrix.h"
#include "../../includes/ray.h"
#include "../../includes/objects.h"
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
	intersect(r, &s, &inter);
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
	intersect(r, &s, &inter);
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
	intersect(r, &s, &inter);
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
	intersect(r, &s, &inter);
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
	intersect(r, &s, &inter);
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
	intersect(r, &s, &inter);
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
	intersect(r, &s, &xs);
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
	intersect(r, &s, &xs);
	TEST_ASSERT_EQUAL_INT32(0, xs.count);
	free(xs.i);
}

void	test_sphere_normal()
{
	t_obj	s = sphere();

	TEST_ASSERT(tp_equal(vector(1, 0, 0), sphere_normal(&s, point(1, 0, 0))));
	TEST_ASSERT(tp_equal(vector(0, 1, 0), sphere_normal(&s, point(0, 1, 0))));
	TEST_ASSERT(tp_equal(vector(0, 0, 1), sphere_normal(&s, point(0, 0, 1))));
	TEST_ASSERT(tp_equal(vector(sqrtf(3) / 3, sqrtf(3) / 3, sqrtf(3) / 3), sphere_normal(&s, point(sqrtf(3) / 3,sqrtf(3) / 3, sqrtf(3) / 3))));
}

void	test_sphere_normal_is_normal()
{
	t_obj	s = sphere();
	t_tuple	n = sphere_normal(&s, point(sqrtf(3) / 3,sqrtf(3) / 3, sqrtf(3) / 3));
	TEST_ASSERT(tp_equal(n, tp_normalize(n)));
}

void	test_translated_sphere_normal()
{
	t_obj	s = sphere();
	t_mtx4	buf;

	mul_transform(&s, translation(0, 1, 0, buf));
	TEST_ASSERT(tp_equal(vector(0, 0.70711, -0.70711), sphere_normal(&s, point(0, 1.70711, -0.70711))));
	s = sphere();
	mul_transform(&s, mx_rotation_z(M_PI / 5, scaling(1, 0.5, 1, buf)));
	TEST_ASSERT(tp_equal(vector(0, 0.97014, -0.24254), sphere_normal(&s, point(0, sqrtf(2) / 2, -sqrtf(2) / 2))));
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
	TEST_ASSERT_MESSAGE(d_equal(c1.r, c2.r), "red composant is not equal");
	TEST_ASSERT_MESSAGE(d_equal(c1.g, c2.g), "green composant is not equal");
	TEST_ASSERT_MESSAGE(d_equal(c1.b, c2.b), "blue composant is not equal");
}

void	test_direct_light_eye()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, -10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv};

	assert_fcolor(fcolor(1.9 - 0.1, 1.9 - 0.1, 1.9 - 0.1), phong(g_default_mat, l, &c));
}

void	test_direct_light_eye_45()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, sqrtf(2) / 2, -sqrtf(2) / 2);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, -10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv};

	assert_fcolor(fcolor(1.0 - 0.1, 1.0 - 0.1, 1.0 - 0.1), phong(g_default_mat, l, &c));
}

void	test_direct_light_45_eye()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 10, -10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv};

	assert_fcolor(fcolor(0.7364 - 0.1, 0.7364 - 0.1, 0.7364 - 0.1), phong(g_default_mat, l, &c));
}

void	test_direct_light_45_eye_45()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, -sqrtf(2) / 2, -sqrtf(2) / 2);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 10, -10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv};

	assert_fcolor(fcolor(1.6364 - 0.1, 1.6364 - 0.1, 1.6364 - 0.1), phong(g_default_mat, l, &c));
}

void	test_direct_light_eye_behind()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, 10), fcolor(1, 1, 1), POINT);
	t_pre_compute	c = {0, 0, pos, eyev, normalv};

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

	pc = pre_compute(&i, r);
	TEST_ASSERT(pc.inside == false);
}

void	test_pre_compute_inside()
{
	t_ray			r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_obj			o = sphere();
	t_intersection	i = intersection(1, &o);
	t_pre_compute	pc;

	pc = pre_compute(&i, r);
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
	pc = pre_compute(&i, r);
	assert_fcolor(fcolor(0.38066, 0.47583, 0.2855), light_hit(&w, &pc));
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
	pc = pre_compute(&i, r);
	assert_fcolor(fcolor(0.90498, 0.90498, 0.90498), light_hit(&w, &pc));
	free_world(&w);
}

void	test_color_ray_miss()
{
	t_world	w;
	t_ray	r = ray(point(0, 0, -5), vector(0, 1, 0));

	default_world(&w);
	assert_fcolor(fcolor(0, 0, 0), color_at(&w, r));
	free_world(&w);
}

void	test_color_ray_hit()
{
	t_world	w;
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));

	default_world(&w);
	assert_fcolor(fcolor(0.38066, 0.47583, 0.2855), color_at(&w, r));
	free_world(&w);
}

void	test_color_ray_hit_behind()
{
	t_world	w;
	t_ray	r = ray(point(0, 0, 0.75), vector(0, 0, -1));

	default_world(&w);
	w.ambient.i = 1;
	w.ambient.col = fcolor(1, 1, 1);
	assert_fcolor(w.objs[1].mat.col, color_at(&w, r));
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
	assert_fcolor(fcolor(0.38066, 0.47583, 0.2855), color_at(&w, ray_for_pixel(cam, 5, 5)));
	destroy_image(&img);
	destroy_window(&win);
	free_world(&w);
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
	return 0;
}
