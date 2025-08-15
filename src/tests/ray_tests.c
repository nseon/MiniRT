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

#include "/home/pjarnac/unity/unity.h"
#include "../../includes/tuple.h"
#include "../../includes/normals.h"
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
#include "../../includes/lighting.h"


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
	set_transform(&s2, transf);
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
	set_transform(&s, scaling(2, 2, 2, transf));
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
	set_transform(&s, translation(5, 0, 0, transf));
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

	set_transform(&s, translation(0, 1, 0, buf));
	TEST_ASSERT(tp_equal(vector(0, 0.70711, -0.70711), sphere_normal(&s, point(0, 1.70711, -0.70711))));
	s = sphere();
	set_transform(&s, mx_rotation_z(M_PI / 5, scaling(1, 0.5, 1, buf)));
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
	TEST_ASSERT_EQUAL_FLOAT_MESSAGE(c1.r, c2.r, "red composant is not equal");
	TEST_ASSERT_EQUAL_FLOAT_MESSAGE(c1.g, c2.g, "green composant is not equal");
	TEST_ASSERT_EQUAL_FLOAT_MESSAGE(c1.b, c2.b, "blue composant is not equal");
}

void	test_direct_light_eye()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, -10), fcolor(1, 1, 1), POINT);
	t_phong_comp	c = {pos, eyev, normalv, l};

	assert_fcolor(fcolor(1.9, 1.9, 1.9), phong(g_default_mat, c));
}

void	test_direct_light_eye_45()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, sqrtf(2) / 2, -sqrtf(2) / 2);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, -10), fcolor(1, 1, 1), POINT);
	t_phong_comp	c = {pos, eyev, normalv, l};

	assert_fcolor(fcolor(1.0, 1.0, 1.0), phong(g_default_mat, c));
}

void	test_direct_light_45_eye()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 10, -10), fcolor(1, 1, 1), POINT);
	t_phong_comp	c = {pos, eyev, normalv, l};

	assert_fcolor(fcolor(0.7364, 0.7364, 0.7364), phong(g_default_mat, c));
}

void	test_direct_light_45_eye_45()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, -sqrtf(2) / 2, -sqrtf(2) / 2);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 10, -10), fcolor(1, 1, 1), POINT);
	t_phong_comp	c = {pos, eyev, normalv, l};

	assert_fcolor(fcolor(1.6364, 1.6364, 1.6364), phong(g_default_mat, c));
}

void	test_direct_light_eye_behind()
{
	t_tuple	pos = point(0, 0, 0);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light	l = light(point(0, 0, 10), fcolor(1, 1, 1), POINT);
	t_phong_comp	c = {pos, eyev, normalv, l};

	assert_fcolor(fcolor(0.1, 0.1, 0.1), phong(g_default_mat, c));
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
	return 0;
}
