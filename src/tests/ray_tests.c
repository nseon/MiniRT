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
#include "../../includes/fcolors.h"
#include "../../includes/matrix.h"
#include "../../includes/ray.h"
#include "../../includes/objects.h"
#include "../../lib/neflibx/includes/neflibx.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../includes/errors.h"
#include "../../includes/fcolors.h"

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

	inter = intersect(r, &s);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(4, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(6, inter.i[1].t);
}

void	test_sphere_intersection_tangent()
{
	t_ray		r = ray(point(0, 1, -5), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter = intersect(r, &s);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(5, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(5, inter.i[1].t);
}

void	test_sphere_intersection_nothing()
{
	t_ray		r = ray(point(0, 2, -5), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter = intersect(r, &s);
	TEST_ASSERT_EQUAL_INT32(0, inter.count);
}

void	test_sphere_intersection_inside()
{
	t_ray		r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter = intersect(r, &s);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(-1, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(1, inter.i[1].t);
}

void	test_sphere_intersection_after()
{
	t_ray		r = ray(point(0, 0, 2), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter = intersect(r, &s);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(-3, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(-1, inter.i[1].t);
}

void	test_sphere_intersection_objects()
{
	t_ray		r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj		s = sphere();
	t_intersections	inter;

	inter = intersect(r, &s);
	TEST_ASSERT_EQUAL_INT32(2, inter.count);
	TEST_ASSERT_EQUAL_FLOAT(4, inter.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(6, inter.i[1].t);
	TEST_ASSERT_EQUAL_PTR(&s, inter.i[0].obj);
	TEST_ASSERT_EQUAL_PTR(&s, inter.i[1].obj);
}

void	test_intersections_hit()
{
	t_obj		s = sphere();
	t_intersections	xs = {2};

	xs.i[0] = intersection(1, &s);
	xs.i[1] = intersection(2, &s);
	TEST_ASSERT_EQUAL_PTR(&xs.i[0], hit(&xs));
}

void	test_intersections_hit_negative()
{
	t_obj		s = sphere();
	t_intersections	xs = {2};

	xs.i[0] = intersection(-1, &s);
	xs.i[1] = intersection(2, &s);
	TEST_ASSERT_EQUAL_PTR(&xs.i[1], hit(&xs));
}

void	test_intersections_hit_none()
{
	t_obj		s = sphere();
	t_intersections	xs = {2};

	xs.i[0] = intersection(-1, &s);
	xs.i[1] = intersection(-2, &s);
	TEST_ASSERT_EQUAL_PTR(NULL, hit(&xs));
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
	set_transform(&s2, transf);
	TEST_ASSERT(mtx4_equal(transf, s2.transform));
}

void	test_scaled_sphere_intersection()
{
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj			s = sphere();
	t_intersections	xs;
	t_mtx4			transf;

	set_transform(&s, scaling(2, 2, 2, transf));
	xs = intersect(r, &s);
	TEST_ASSERT_EQUAL_INT32(2, xs.count);
	TEST_ASSERT_EQUAL_FLOAT(3, xs.i[0].t);
	TEST_ASSERT_EQUAL_FLOAT(7, xs.i[1].t);
}

void	test_translated_sphere_intersection()
{
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj			s = sphere();
	t_intersections	xs;
	t_mtx4			transf;

	set_transform(&s, translation(5, 0, 0, transf));
	xs = intersect(r, &s);
	TEST_ASSERT_EQUAL_INT32(0, xs.count);
}

void	test_rays()
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
}
