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
#include "../includes/tuple.h"
#include "../includes/fcolors.h"
#include "../includes/matrix.h"
#include "../lib/neflibx/includes/neflibx.h"
#include <math.h>
#include <unistd.h>

#include "../includes/fcolors.h"

void	setUp()
{

}

void	tearDown()
{

}

void	test_tuple_equality()
{
	t_tuple const	tp1 = {5.2, -4.7, 0.01, 0};
	t_tuple const	tp1_e = {5.2, -4.7, 0.01, 0};
	t_tuple const	tp2 = {5.2, -4.7, 0.01, 1};
	t_tuple const	tp3 = {5.1, -4.7, 0.01, 1};
	t_tuple const	tp4_e = {5.20001, -4.7, 0.01, 0};
	t_tuple const	tp5 = {5.2001, -4.7, 0.01, 0};

	TEST_ASSERT(tp_equal(tp1, tp1_e));
	TEST_ASSERT(!tp_equal(tp1, tp2));
	TEST_ASSERT(!tp_equal(tp1, tp3));
	TEST_ASSERT(tp_equal(tp1, tp4_e));
	TEST_ASSERT(!tp_equal(tp1, tp5));
}

void	test_tuple_creation()
{
	t_tuple const	tp1 = {5.2, -4.7, 0.01, 0};
	t_tuple const	tp2 = {5.2, -4.7, 0.01, 1};

	TEST_ASSERT(tp_equal(vector(5.2, -4.7, 0.01), tp1));
	TEST_ASSERT(tp_equal(point(5.2, -4.7, 0.01), tp2));
}

void	test_tuple_add()
{
	TEST_ASSERT(tp_equal(tp_add(point(3, 2, 1), vector(5, 6, 7)),
		point(8, 8, 8)));
	TEST_ASSERT(tp_equal(tp_add(vector(3, 2, 1), vector(5, 6, 7)),
		vector(8, 8, 8)));
}
void	test_tuple_sub()
{
	TEST_ASSERT(tp_equal(tp_sub(point(3, 2, 1), point(5, 6, 7)),
		vector(-2, -4, -6)));
	TEST_ASSERT(tp_equal(tp_sub(point(3, 2, 1), vector(5, 6, 7)),
		point(-2, -4, -6)));
	TEST_ASSERT(tp_equal(tp_sub(vector(3, 2, 1), vector(5, 6, 7)),
		vector(-2, -4, -6)));
}

void	test_tuple_mul()
{
	TEST_ASSERT(tp_equal(tp_mul(vector(1, -2, 3), 3.5),
		vector(3.5, -7, 10.5)));
	TEST_ASSERT(tp_equal(tp_mul(vector(1, -2, 3), 0.5),
		vector(0.5, -1, 1.5)));
}

void	test_tuple_negate()
{
	TEST_ASSERT(tp_equal(tp_negate(vector(3, -2, 1.7)),
		vector(-3, 2, -1.7)));
}

void	test_tuple_magnitude()
{
	TEST_ASSERT_EQUAL_FLOAT(tp_magnitude(vector(1, 0, 0)), 1);
	TEST_ASSERT_EQUAL_FLOAT(tp_magnitude(vector(0, 1, 0)), 1);
	TEST_ASSERT_EQUAL_FLOAT(tp_magnitude(vector(0, 0, 1)), 1);
	TEST_ASSERT_EQUAL_FLOAT(tp_magnitude(vector(1, 2, 3)), sqrtf(14));
	TEST_ASSERT_EQUAL_FLOAT(tp_magnitude(vector(-1, -2, -3)), sqrtf(14));
}

void	test_tuple_normalization()
{
	TEST_ASSERT(tp_equal(tp_normalize(vector(4, 0, 0)), vector(1, 0, 0)));
	TEST_ASSERT(tp_equal(tp_normalize(vector(1, 2, 3)),
		vector(1 / sqrtf(14), 2 / sqrtf(14), 3 / sqrtf(14))));
	TEST_ASSERT_EQUAL_FLOAT(tp_magnitude(tp_normalize(vector(1, 2, 3))), 1);
}

void	test_tuple_dotproduct()
{
	TEST_ASSERT_EQUAL_FLOAT(tp_dotproduct(vector(1, 2, 3), vector(2, 3, 4)),
		20);
}

void	test_tuple_crossproduct()
{
	TEST_ASSERT(tp_equal(tp_crossproduct(vector(1, 2, 3), vector(2, 3, 4)), vector(-1, 2, -1)));
	TEST_ASSERT(tp_equal(tp_crossproduct(vector(2, 3, 4), vector(1, 2, 3)), vector(1, -2, 1)));
}

void	test_color_add()
{
	t_fcolor	col = fcolor(0.1, 0.2, -0.5);
	t_fcolor	col2 = fcolor(0.0, 0.8, 0.1);

	col = color_add(col, col2);
	TEST_ASSERT_EQUAL_FLOAT(0.1, col.r);
	TEST_ASSERT_EQUAL_FLOAT(1, col.g);
	TEST_ASSERT_EQUAL_FLOAT(-0.4, col.b);
}

void	test_color_sub()
{
	t_fcolor	col = fcolor(0.1, 0.2, -0.5);
	t_fcolor	col2 = fcolor(0.0, 0.8, 0.1);

	col = color_sub(col, col2);
	TEST_ASSERT_EQUAL_FLOAT(0.1, col.r);
	TEST_ASSERT_EQUAL_FLOAT(-0.6, col.g);
	TEST_ASSERT_EQUAL_FLOAT(-0.6, col.b);
}

void	test_color_scalar()
{
	t_fcolor	col = fcolor(0.1, 0.2, -0.5);

	col = color_scalar(col, 3);
	TEST_ASSERT_EQUAL_FLOAT(0.3, col.r);
	TEST_ASSERT_EQUAL_FLOAT(0.6, col.g);
	TEST_ASSERT_EQUAL_FLOAT(-1.5, col.b);
}

void	test_color_mul()
{
	t_fcolor	col = fcolor(0.1, 0.2, -0.5);
	t_fcolor	col2 = fcolor(0.0, 0.8, 0.1);

	col = color_sub(col, col2);
	TEST_ASSERT_EQUAL_FLOAT(0.1, col.r);
	TEST_ASSERT_EQUAL_FLOAT(-0.6, col.g);
	TEST_ASSERT_EQUAL_FLOAT(-0.6, col.b);
}

void	test_image_creation()
{
	t_image	img;
	t_window win;
	int32_t	*data;

	TEST_ASSERT_EQUAL_INT(init_window(&win, 150, 150, "tests"), 0);
	TEST_ASSERT_EQUAL_INT(create_image(&img, 150, 150, &win), 0);
	data = (int32_t *)img.addr;
	for (int i = 0; i < img.w * img.h; i++)
	{
		TEST_ASSERT_EQUAL_INT32(0, data[i]);
	}
	destroy_image(&img);
	destroy_window(&win);
}


void	test_image_pixel_write()
{
	t_image	img;
	t_window win;
	int32_t	*data;

	TEST_ASSERT_EQUAL_INT(init_window(&win, 150, 150, "tests"), 0);
	TEST_ASSERT_EQUAL_INT(create_image(&img, 150, 150, &win), 0);
	data = (int32_t *)img.addr;
	put_pixel_img(&img, point_s(15, 28, 578943));
	TEST_ASSERT_EQUAL_INT32(578943, data[28 * 150 + 15]);
	destroy_image(&img);
	destroy_window(&win);
}

void	test_image_pixel_write_all()
{
	t_image	img;
	t_window win;
	int32_t	*data;

	TEST_ASSERT_EQUAL_INT(init_window(&win, 150, 150, "tests"), 0);
	TEST_ASSERT_EQUAL_INT(create_image(&img, 150, 150, &win), 0);
	data = (int32_t *)img.addr;
	for (int y = 0; y < img.h; y++)
	{
		for (int x = 0; x < img.w; x++)
		{
			put_pixel_img(&img, point_s(x, y, 0xFF));
			TEST_ASSERT_EQUAL_INT32(0xFF, data[y * img.w + x]);
		}
	}
	put_img(&img, 0, 0, false);
	usleep(100000);
	for (int y = 0; y < img.h; y++)
	{
		for (int x = 0; x < img.w; x++)
		{
			put_pixel_img(&img, point_s(x, y, 0xFF00));
			TEST_ASSERT_EQUAL_INT32(0XFF00, data[y * img.w + x]);
		}
	}
	put_img(&img, 0, 0, false);
	usleep(100000);
	for (int y = 0; y < img.h; y++)
	{
		for (int x = 0; x < img.w; x++)
		{
			put_pixel_img(&img, point_s(x, y, 0xFF0000));
			TEST_ASSERT_EQUAL_INT32(0xFF0000, data[y * img.w + x]);
		}
	}
	put_img(&img, 0, 0, false);
	usleep(100000);
	destroy_image(&img);
	destroy_window(&win);
}

void	test_matrix44_creation()
{
	t_matrix_4x4	matrix = {{1, 2, 3, 4},
								{5.5, 6.5, 7.5, 8.5},
								{9, 10, 11, 12},
								{13.5, 14.5, 15.5, 16.5}};

	TEST_ASSERT_EQUAL_FLOAT(1, matrix[0][0]);
	TEST_ASSERT_EQUAL_FLOAT(4, matrix[0][3]);
	TEST_ASSERT_EQUAL_FLOAT(5.5, matrix[1][0]);
	TEST_ASSERT_EQUAL_FLOAT(7.5, matrix[1][2]);
	TEST_ASSERT_EQUAL_FLOAT(11, matrix[2][2]);
	TEST_ASSERT_EQUAL_FLOAT(13.5, matrix[3][0]);
	TEST_ASSERT_EQUAL_FLOAT(15.5, matrix[3][2]);
}

void	test_matrix33_creation()
{
	t_matrix_3x3	m = {{7, 6, -1},
						{1.1, 0.12, 7},
						{0, -7, 9}};

	TEST_ASSERT_EQUAL_FLOAT(7, m[0][0]);
	TEST_ASSERT_EQUAL_FLOAT(0.12, m[1][1]);
	TEST_ASSERT_EQUAL_FLOAT(9, m[2][2]);
}

void	test_matrix22_creation()
{
	t_matrix_2x2	m = {{7, 6},
						{1.1, 0.12}};

	TEST_ASSERT_EQUAL_FLOAT(7, m[0][0]);
	TEST_ASSERT_EQUAL_FLOAT(0.12, m[1][1]);
}

void	test_matrix44_equality()
{
	t_matrix_4x4	m1 = {{1, 2, 3, 4},
							{5.5, 6.5, 7.5, 8.5},
							{9, 10, 11, 12},
							{13.5, 14.5, 15.5, 16.5}};
	t_matrix_4x4	m2  = {{1, 2, 3, 4},
							{5.5, 6.5, 7.50001, 8.5},
							{9, 10, 11, 12},
							{13.5, 14.5, 15.5, 16.5}};
	t_matrix_4x4	m3  = {{1, 2, 5, 4},
							{5.5, 6.5, 7.5, 8.5},
							{9, 10, 11, 12},
							{13.4, 14.5, 15.5, 16.5}};

	TEST_ASSERT(matrix_equal(m1, m2));
	TEST_ASSERT(!matrix_equal(m1, m3));
}

void	test_matrix44_multiplication()
{
	t_matrix_4x4	m1 = {{1, 2, 3, 4},
						{5, 6, 7, 8},
						{9, 8, 7, 6},
						{5, 4, 3, 2}};
	t_matrix_4x4	m2  = {{-2, 1, 2, 3},
							{3, 2, 1, -1},
							{4, 3, 6, 5},
							{1, 2, 7, 8}};
	t_matrix_4x4	m3  = {{20, 22, 50, 48},
							{44, 54, 114, 108},
							{40, 58, 110, 102},
							{16, 26, 46, 42}};
	t_matrix_4x4	res;


	matrix_mul(m1, m2, res);
	TEST_ASSERT(matrix_equal(res, m3));
}

void	test_matrix_tup_mul()
{
	t_matrix_4x4	m1 = {{1, 2, 3, 4},
						{2, 4, 4, 2},
						{8, 6, 4, 1},
						{0, 0, 0, 1}};

	TEST_ASSERT(tp_equal(point(18, 24, 33), matrix_tup_mul(point(1, 2, 3), m1)));
}

void	test_matrix44_identity()
{
	t_matrix_4x4	m1 = {{1, 2, 3, 4},
						{2, 4, 4, 2},
						{8, 6, 4, 1},
						{0, 0, 0, 1}};
	t_matrix_4x4	res;

	matrix_mul(m1, g_identity_matrix, res);
	TEST_ASSERT(matrix_equal(m1, res));
}

void	test_matrix_tup_identity()
{
	TEST_ASSERT(tp_equal(point(1, 2.78, 3),
		matrix_tup_mul(point(1, 2.78, 3), g_identity_matrix)));
}

int	main()
{
	UNITY_BEGIN();
	RUN_TEST(test_tuple_equality);
	RUN_TEST(test_tuple_creation);
	RUN_TEST(test_tuple_add);
	RUN_TEST(test_tuple_sub);
	RUN_TEST(test_tuple_negate);
	RUN_TEST(test_tuple_mul);
	RUN_TEST(test_tuple_magnitude);
	RUN_TEST(test_tuple_normalization);
	RUN_TEST(test_tuple_dotproduct);
	RUN_TEST(test_tuple_crossproduct);

	RUN_TEST(test_color_add);
	RUN_TEST(test_color_sub);
	RUN_TEST(test_color_scalar);
	RUN_TEST(test_color_mul);

	RUN_TEST(test_image_creation);
	RUN_TEST(test_image_pixel_write);
	RUN_TEST(test_image_pixel_write_all);

	RUN_TEST(test_matrix44_creation);
	RUN_TEST(test_matrix33_creation);
	RUN_TEST(test_matrix22_creation);
	RUN_TEST(test_matrix44_equality);
	RUN_TEST(test_matrix44_multiplication);
	RUN_TEST(test_matrix_tup_mul);
	RUN_TEST(test_matrix44_identity);
	RUN_TEST(test_matrix_tup_identity);
	return UNITY_END();
}
