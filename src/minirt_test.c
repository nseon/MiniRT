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

int	main()
{
	UNITY_BEGIN();
	RUN_TEST(test_triangle);
	RUN_TEST(test_mesh);
	return UNITY_END();
}
