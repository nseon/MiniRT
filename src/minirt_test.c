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
#include "../lib/libft/src/vector/vector.h"

void	setUp()
{

}

void	tearDown()
{

}

void	test_triangle()
{
	t_triangle	triangle;
	t_point3	pt = {.x = 0, .y = 1.003, .z = 0};

	triangle = new_triangle((t_point3){-0.03, 0, 0}, (t_point3){1, 0, 0}, (t_point3){0, 1.003, 0});
	TEST_ASSERT_EQUAL_FLOAT(1, triangle.vertices[1].x);
	TEST_ASSERT_EQUAL_FLOAT(-0.03, triangle.vertices[0].x);
	TEST_ASSERT_EQUAL_MEMORY(&pt, &triangle.vertices[2], sizeof (t_point3));
}

void	test_mesh()
{
	t_mesh	mesh;
	t_triangle	triangle = {0.5, -1, 1.5, 2, 2, 2, 3, 3, 3};
	TEST_ASSERT_EQUAL_INT8_MESSAGE(0, new_mesh(&mesh), "Mesh initialization error :'(");
	TEST_ASSERT_EQUAL_UINT32(0, mesh_tri_count(&mesh));
	TEST_ASSERT_EQUAL_INT8(0, add_triangle(&mesh, &triangle));
	TEST_ASSERT_EQUAL_UINT32(1, mesh_tri_count(&mesh));
	TEST_ASSERT_EQUAL_MEMORY(&triangle, get_triangle(&mesh, 0), sizeof (t_triangle));
	TEST_ASSERT_EQUAL_INT8(0, add_triangle(&mesh, &triangle));
	TEST_ASSERT_EQUAL_INT8(0, add_triangle(&mesh, &triangle));
	TEST_ASSERT_EQUAL_INT8(0, add_triangle(&mesh, &triangle));
	TEST_ASSERT_EQUAL_INT8(0, add_triangle(&mesh, &triangle));
	TEST_ASSERT_EQUAL_UINT32(5, mesh_tri_count(&mesh));
	TEST_ASSERT_EQUAL_MEMORY(&triangle, get_triangle(&mesh, 4), sizeof (t_triangle));
	get_triangle(&mesh, 3)->vertices[1].y = -0.007;
	TEST_ASSERT_EQUAL_FLOAT(-0.007, mesh.vertices[3 * 3 + 1].y);
	for (size_t i = 0; i < 1000000; i++)
	{
		TEST_ASSERT_EQUAL_INT8(0, add_triangle(&mesh, &triangle));
	}
	TEST_ASSERT_EQUAL_UINT32(1000005, mesh_tri_count(&mesh));
	printf("Vertices count: %llu\n", vct_size(mesh.vertices));
	TEST_ASSERT_EQUAL_INT8(0, delete_mesh(&mesh));
}

int	main()
{
	UNITY_BEGIN();
	RUN_TEST(test_triangle);
	RUN_TEST(test_mesh);
	return UNITY_END();
}
