/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:49:33 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/14 16:49:33 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/sgoinfre/pjarnac/public/unit_tests/Unity/src/unity.h"
#include "../includes/mesh.h"
#include "../includes/vector2.h"
#include "../includes/vector3.h"
#include "../includes/objects.h"
#include "../lib/neflibx/includes/neflibx.h"

void	setUp()
{

}

void	tearDown()
{

}

void	test_triangle()
{
	// t_triangle	triangle;
	// t_point3	pt = {.x = 0, .y = 1.003, .z = 0};
	//
	// triangle = new_triangle((t_point3){-0.03, 0, 0}, (t_point3){1, 0, 0}, (t_point3){0, 1.003, 0});
	// TEST_ASSERT_EQUAL_FLOAT(1, triangle.vertices[1].x);
	// TEST_ASSERT_EQUAL_FLOAT(-0.03, triangle.vertices[0].x);
	// TEST_ASSERT_EQUAL_MEMORY(&pt, &triangle.vertices[2], sizeof (t_point3));
}

void	test_mesh()
{
	t_mesh	*mesh = new_cube((t_point3){.x = 0, .y = 0, .z = 0}, (t_point3){.x = 10, .y = 2, .z = 20});
	TEST_ASSERT_NOT_NULL(mesh);
	t_triangle triangle = get_triangle(mesh, 1);
	TEST_ASSERT_EQUAL_FLOAT(triangle.vertices[1]->x, 10);
	triangle.vertices[0]->y = 1.042;
	TEST_ASSERT_EQUAL_FLOAT(1.042, get_triangle(mesh, 0).vertices[0]->y);
	delete_mesh(mesh);
}

void	test_vec2()
{
	t_vec2	vec = {10, 10};
	t_vec2	vec2 = {0, 10};
	t_vec2	vec3 = {0, 0};

	TEST_ASSERT_EQUAL_FLOAT(14.1421356, v2_magnitude(vec));
	TEST_ASSERT_EQUAL_FLOAT(10, v2_magnitude(vec2));
	TEST_ASSERT_EQUAL_FLOAT(0, v2_magnitude(vec3));

	t_vec2	vec4 = get_vec2((t_point2){1, 1}, (t_point2){6, 1.5});
	t_vec2	vec4c = (t_vec2){5, 0.5};
	TEST_ASSERT_EQUAL_MEMORY(&vec4c, &vec4, sizeof (t_vec2));
}

void	test_vec3()
{
	t_vec3	vec = {10, 10, 0.7};
	t_vec3	vec2 = {0, 10, 0};
	t_vec3	vec3 = {0, 0,  0};

	TEST_ASSERT_EQUAL_FLOAT(14.1594491, v3_magnitude(vec));
	TEST_ASSERT_EQUAL_FLOAT(10, v3_magnitude(vec2));
	TEST_ASSERT_EQUAL_FLOAT(0, v3_magnitude(vec3));

	t_vec3	vec4 = get_vec3((t_point3){1, 1, 2}, (t_point3){6, 1.5, 1});
	t_vec3	vec4c = (t_vec3){5, 0.5, -1};
	TEST_ASSERT_EQUAL_MEMORY(&vec4c, &vec4, sizeof (t_vec3));
	vec = v3_normalize(vec);
	TEST_ASSERT_EQUAL_FLOAT(1, v3_magnitude(vec));
	vec2 = v3_multiply(vec2, 1.5);
	t_vec3 vec2c = {0, 15, 0};
	TEST_ASSERT_EQUAL_MEMORY(&vec2c, &vec2, sizeof (t_vec3));
}

int	main()
{
	UNITY_BEGIN();
	RUN_TEST(test_triangle);
	RUN_TEST(test_mesh);
	RUN_TEST(test_vec2);
	RUN_TEST(test_vec3);
	return UNITY_END();
}
