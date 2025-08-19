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
#include "../includes/ray.h"
#include "../includes/objects.h"
#include "../lib/neflibx/includes/neflibx.h"
#include <math.h>
#include <unistd.h>

#include "../includes/errors.h"
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
	TEST_ASSERT_EQUAL_FLOAT(tp_dot(vector(1, 2, 3), vector(2, 3, 4)),
		20);
}

void	test_tuple_crossproduct()
{
	TEST_ASSERT(tp_equal(tp_cross(vector(1, 2, 3), vector(2, 3, 4)), vector(-1, 2, -1)));
	TEST_ASSERT(tp_equal(tp_cross(vector(2, 3, 4), vector(1, 2, 3)), vector(1, -2, 1)));
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
	t_mtx4	matrix = {{1, 2, 3, 4},
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
	t_mtx3	m = {{7, 6, -1},
						{1.1, 0.12, 7},
						{0, -7, 9}};

	TEST_ASSERT_EQUAL_FLOAT(7, m[0][0]);
	TEST_ASSERT_EQUAL_FLOAT(0.12, m[1][1]);
	TEST_ASSERT_EQUAL_FLOAT(9, m[2][2]);
}

void	test_matrix22_creation()
{
	t_mtx2	m = {{7, 6},
						{1.1, 0.12}};

	TEST_ASSERT_EQUAL_FLOAT(7, m[0][0]);
	TEST_ASSERT_EQUAL_FLOAT(0.12, m[1][1]);
}

void	test_matrix44_equality()
{
	t_mtx4	m1 = {{1, 2, 3, 4},
							{5.5, 6.5, 7.5, 8.5},
							{9, 10, 11, 12},
							{13.5, 14.5, 15.5, 16.5}};
	t_mtx4	m2  = {{1, 2, 3, 4},
							{5.5, 6.5, 7.50001, 8.5},
							{9, 10, 11, 12},
							{13.5, 14.5, 15.5, 16.5}};
	t_mtx4	m3  = {{1, 2, 5, 4},
							{5.5, 6.5, 7.5, 8.5},
							{9, 10, 11, 12},
							{13.4, 14.5, 15.5, 16.5}};

	TEST_ASSERT(mtx4_equal(m1, m2));
	TEST_ASSERT(!mtx4_equal(m1, m3));
}

void	test_matrix44_multiplication()
{
	t_mtx4	m1 = {{1, 2, 3, 4},
						{5, 6, 7, 8},
						{9, 8, 7, 6},
						{5, 4, 3, 2}};
	t_mtx4	m2  = {{-2, 1, 2, 3},
							{3, 2, 1, -1},
							{4, 3, 6, 5},
							{1, 2, 7, 8}};
	t_mtx4	m3  = {{20, 22, 50, 48},
							{44, 54, 114, 108},
							{40, 58, 110, 102},
							{16, 26, 46, 42}};
	t_mtx4	res;


	mtx_mul(m1, m2, res);
	TEST_ASSERT(mtx4_equal(res, m3));
}

void	test_matrix44_multiplication2()
{
	t_mtx4	m1 = {{1, 2, 3, 4},
						{5, 6, 7, 8},
						{9, 8, 7, 6},
						{5, 4, 3, 2}};
	t_mtx4	m2  = {{-2, 1, 2, 3},
							{3, 2, 1, -1},
							{4, 3, 6, 5},
							{1, 2, 7, 8}};
	t_mtx4	m3  = {{20, 22, 50, 48},
							{44, 54, 114, 108},
							{40, 58, 110, 102},
							{16, 26, 46, 42}};


	TEST_ASSERT(mtx4_equal(mtx_mul2(m1, m2), m3));
}

void	test_matrix_tup_mul()
{
	t_mtx4	m1 = {{1, 2, 3, 4},
						{2, 4, 4, 2},
						{8, 6, 4, 1},
						{0, 0, 0, 1}};

	TEST_ASSERT(tp_equal(point(18, 24, 33), mtx_tup_mul(point(1, 2, 3), m1)));
}

void	test_matrix_tup_mul2()
{
	t_mtx4	m1 = {{1, 2, 3, 4},
						{2, 4, 4, 2},
						{8, 6, 4, 1},
						{0, 0, 0, 1}};
	t_tuple	pt = point(1, 2, 3);

	TEST_ASSERT(tp_equal(point(18, 24, 33), *mtx_tup_mul2(&pt, m1)));
	TEST_ASSERT_EQUAL_PTR(&pt, mtx_tup_mul2(&pt, m1));
}

void	test_matrix44_identity()
{
	t_mtx4	m1 = {{1, 2, 3, 4},
						{2, 4, 4, 2},
						{8, 6, 4, 1},
						{0, 0, 0, 1}};
	t_mtx4	res;

	mtx_mul(m1, g_identity_matrix, res);
	TEST_ASSERT(mtx4_equal(m1, res));
}

void	test_matrix_tup_identity()
{
	TEST_ASSERT(tp_equal(point(1, 2.78, 3),
		mtx_tup_mul(point(1, 2.78, 3), g_identity_matrix)));
}

void	test_matrix_transpose()
{
	t_mtx4	m1 = {{0, 9, 3, 0},
				{9, 8, 0, 8},
				{1, 8, 5, 3},
				{0, 0, 5, 8}};
	t_mtx4	m2 = {{0, 9, 1, 0},
				{9, 8, 8, 0},
				{3, 0, 5, 5},
				{0, 8, 3, 8}};
	mtx_transpose(m1);
	TEST_ASSERT(mtx4_equal(m1, m2));
}

void	test_matrix_transpose2()
{
	t_mtx4	m1 = {{0, 9, 3, 0},
				{9, 8, 0, 8},
				{1, 8, 5, 3},
				{0, 0, 5, 8}};
	t_mtx4	m2 = {{0, 9, 1, 0},
				{9, 8, 8, 0},
				{3, 0, 5, 5},
				{0, 8, 3, 8}};
	t_mtx4	buf;

	mtx_transpose2(m1, buf);
	TEST_ASSERT(mtx4_equal(buf, m2));
	TEST_ASSERT_EQUAL_FLOAT_ARRAY(m2, buf, 16);
}

void	test_identity_transpose()
{
	t_mtx4	m1 = {{1, 0, 0, 0},
				{0, 1, 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1}};
	mtx_transpose(m1);
	TEST_ASSERT(mtx4_equal(m1, g_identity_matrix));
}

void	test_matrix2_determinant()
{
	t_mtx2	m1 = {{1, 5},
				{-3, 2}};

	TEST_ASSERT_EQUAL_FLOAT(17, mtx2_determinant(m1));
}

void	test_matrix4_submatrix()
{
	t_mtx4	m1  = {{-6, 1, 1, 6},
					{-8, 5, 8, 6},
					{-1, 0, 8, 2},
					{-7, 1, -1, 1}};
	t_mtx3	m2 = {{-6, 1, 6},
				{-8, 8, 6},
				{-7, -1, 1}};
	t_mtx3	res;

	mtx4_submatrix(m1, 2, 1, res);
	TEST_ASSERT(mtx3_equal(m2, res));
}

void	test_matrix3_submatrix()
{
	t_mtx3	m1 = {{1, 5, 0},
				{-3, 2, 7},
				{0, 6, -3}};
	t_mtx2	m2 = {{-3, 2},
				{0, 6}};
	t_mtx2 res;

	mtx3_submatrix(m1, 0, 2, res);
	TEST_ASSERT(mtx2_equal(m2, res));
}

void	test_matrix3_minor()
{
	t_mtx3	m1 = {{3, 5, 0},
				{2, -1, -7},
				{6, -1, 5}};
	t_mtx2 sub_m1;

	mtx3_submatrix(m1, 1, 0, sub_m1);
	TEST_ASSERT_EQUAL_FLOAT(25, mtx2_determinant(sub_m1));
	TEST_ASSERT_EQUAL_FLOAT(25, mtx3_minor(m1, 1, 0));
}

void	test_matrix3_cofactor()
{
	t_mtx3	m1 = {{3, 5, 0},
				{2, -1, -7},
				{6, -1, 5}};

	TEST_ASSERT_EQUAL_FLOAT(-12, mtx3_minor(m1, 0, 0));
	TEST_ASSERT_EQUAL_FLOAT(-12, mtx3_cofactor(m1, 0, 0));
	TEST_ASSERT_EQUAL_FLOAT(25, mtx3_minor(m1, 1, 0));
	TEST_ASSERT_EQUAL_FLOAT(-25, mtx3_cofactor(m1, 1, 0));
}

void	test_matrix3_determinant()
{
	t_mtx3	m1 = {{1, 2, 6},
				{-5, 8, -4},
				{2, 6, 4}};

	TEST_ASSERT_EQUAL_FLOAT(56, mtx3_cofactor(m1, 0, 0));
	TEST_ASSERT_EQUAL_FLOAT(12, mtx3_cofactor(m1, 0, 1));
	TEST_ASSERT_EQUAL_FLOAT(-46, mtx3_cofactor(m1, 0, 2));
	TEST_ASSERT_EQUAL_FLOAT(-196, mtx3_determinant(m1));
}

void	test_matrix4_determinant()
{
	t_mtx4	m1  = {{-2, -8, 3, 5},
					{-3, 1, 7, 3},
					{1, 2, -9, 6},
					{-6, 7, 7, -9}};

	TEST_ASSERT_EQUAL_FLOAT(690, mtx4_cofactor(m1, 0, 0));
	TEST_ASSERT_EQUAL_FLOAT(447, mtx4_cofactor(m1, 0, 1));
	TEST_ASSERT_EQUAL_FLOAT(210, mtx4_cofactor(m1, 0, 2));
	TEST_ASSERT_EQUAL_FLOAT(51, mtx4_cofactor(m1, 0, 3));
	TEST_ASSERT_EQUAL_FLOAT(-4071, mtx4_determinant(m1));
}

void	test_matrix4_is_invertible()
{
	t_mtx4	m1  = {{6, 4, 4, 4},
					{5, 5, 7, 6},
					{4, -9, 3, -7},
					{9, 1, 7, -6}};
	t_mtx4	m2  = {{-4, 2, -2, -3},
					{9, 6, 2, 6},
					{0, -5, 1, -5},
					{0, 0, 0, 0}};

	TEST_ASSERT_EQUAL_FLOAT(-2120, mtx4_determinant(m1));
	TEST_ASSERT(mtx4_invertible(m1));

	TEST_ASSERT_EQUAL_FLOAT(0, mtx4_determinant(m2));
	TEST_ASSERT(!mtx4_invertible(m2));
}

void	test_matrix4_inversion()
{
	t_mtx4	m1  = {{8, -5, 9, 2},
					{7, 5, 6, 1},
					{-6, 0, 9, 6},
					{-3, 0, -9, -4}};
	t_mtx4	m2  = {{-0.15385, -0.15385, -0.28205, -0.53846},
					{-0.07692, 0.12308, 0.02564, 0.03077},
					{0.35897, 0.35897, 0.43590, 0.92308},
					{-0.69231, -0.69231, -0.76923, -1.92308}};
	t_mtx4	res;

	TEST_ASSERT_EQUAL_INT32(SUCCESS, mtx4_inverse(m1, res));
	TEST_ASSERT(mtx4_equal(m2, res));
}

void	test_matrix4_inversion2()
{
	t_mtx4	m1  = {{8, -5, 9, 2},
					{7, 5, 6, 1},
					{-6, 0, 9, 6},
					{-3, 0, -9, -4}};
	t_mtx4	m2  = {{-0.15385, -0.15385, -0.28205, -0.53846},
					{-0.07692, 0.12308, 0.02564, 0.03077},
					{0.35897, 0.35897, 0.43590, 0.92308},
					{-0.69231, -0.69231, -0.76923, -1.92308}};
	t_mtx4	res;

	TEST_ASSERT(mtx4_equal(m2, mtx4_inverse2(m1, res)));
}

void	test_matrix4_inversion3()
{
	t_mtx4	m1  = {{8, -5, 9, 2},
					{7, 5, 6, 1},
					{-6, 0, 9, 6},
					{-3, 0, -9, -4}};
	t_mtx4	m2  = {{-0.15385, -0.15385, -0.28205, -0.53846},
					{-0.07692, 0.12308, 0.02564, 0.03077},
					{0.35897, 0.35897, 0.43590, 0.92308},
					{-0.69231, -0.69231, -0.76923, -1.92308}};

	TEST_ASSERT(mtx4_equal(m2, mtx4_inverse3(m1)));
}

void	test_matrix4_mult_inverse()
{
	t_mtx4	m1  = {{8, -5, 9, 2},
					{7, 5, 6, 1},
					{-6, 0, 9, 6},
					{-3, 0, -9, -4}};
	t_mtx4	m2  = {{6, 4, 4, 4},
					{5, 5, 7, 6},
					{4, -9, 3, -7},
					{9, 1, 7, -6}};
	t_mtx4	res;
	t_mtx4	res2;
	t_mtx4	res3;

	mtx_mul(m1, m2, res);
	TEST_ASSERT_EQUAL_INT32(SUCCESS, mtx4_inverse(m2, res2));
	mtx_mul(res, res2, res3);
	TEST_ASSERT(mtx4_equal(res3, m1));
}

void	test_matrix4_duplication()
{
	t_mtx4	m1  = {{8, -5, 9, 2},
					{7, 5, 6, 1},
					{-6, 0, 9, 6},
					{-3, 0, -9, -4}};
	t_mtx4	res;

	mtx4_dup(m1, res);
	TEST_ASSERT(mtx4_equal(m1, res));
}

void	test_translation()
{
	t_mtx4	trans;
	t_tuple	pt = point(-3, 4, 5);

	translation(5, -3, 2, trans);
	pt = mtx_tup_mul(pt, trans);
	TEST_ASSERT_EQUAL_FLOAT(2, pt.x);
	TEST_ASSERT_EQUAL_FLOAT(1, pt.y);
	TEST_ASSERT_EQUAL_FLOAT(7, pt.z);
	TEST_ASSERT(tp_equal(point(2, 1, 7), pt));
}

void	test_inverse_translation()
{
	t_mtx4	trans;
	t_mtx4	res;
	t_tuple	pt = point(-3, 4, 5);

	translation(5, -3, 2, trans);
	mtx4_inverse(trans, res);
	pt = mtx_tup_mul(pt, res);
	TEST_ASSERT(tp_equal(point(-8, 7, 3), pt));
}

void	test_vector_translation()
{
	t_mtx4	trans;
	t_tuple	vct = vector(-3, 4, 5);

	translation(5, -3, 2, trans);
	vct = mtx_tup_mul(vct, trans);
	TEST_ASSERT(tp_equal(vector(-3, 4, 5), vct));
}

void	test_scaling()
{
	t_mtx4	transf;
	t_tuple	pt = point(-3, 4, 5);

	scaling(2, 4, 6, transf);
	pt = mtx_tup_mul(pt, transf);
	TEST_ASSERT(tp_equal(point(-6, 16, 30), pt));
}

void	test_vector_scaling()
{
	t_mtx4	transf;
	t_tuple	pt = vector(-3, 4, 5);

	scaling(2, 4, 6, transf);
	pt = mtx_tup_mul(pt, transf);
	TEST_ASSERT(tp_equal(vector(-6, 16, 30), pt));
}

void	test_inverse_scaling()
{
	t_mtx4	transf;
	t_mtx4	inv;
	t_tuple	pt = point(-4, 4, 24);

	scaling(2, 4, 6, transf);
	mtx4_inverse(transf, inv);
	pt = mtx_tup_mul(pt, inv);
	TEST_ASSERT(tp_equal(point(-2, 1, 4), pt));
}

void	test_rotation_x()
{
	t_mtx4	transf;
	t_tuple	pt = point(0, 1, 0);

	rotation_x(M_PI_4, transf);
	TEST_ASSERT(tp_equal(point(0, sqrtf(2)/2, sqrtf(2)/2), mtx_tup_mul(pt, transf)));
	rotation_x(M_PI_2, transf);
	TEST_ASSERT(tp_equal(point(0, 0, 1), mtx_tup_mul(pt, transf)));
}

void	test_inverse_rotation_x()
{
	t_mtx4	transf;
	t_mtx4	inv;
	t_tuple	pt = point(0, 1, 0);

	rotation_x(M_PI_4, transf);
	mtx4_inverse(transf, inv);
	TEST_ASSERT(tp_equal(point(0, sqrtf(2)/2, -sqrtf(2)/2), mtx_tup_mul(pt, inv)));
	rotation_x(M_PI_2, transf);
	mtx4_inverse(transf, inv);
	TEST_ASSERT(tp_equal(point(0, 0, -1), mtx_tup_mul(pt, inv)));
}
void	test_rotation_y()
{
	t_mtx4	transf;
	t_tuple	pt = point(0, 0, 1);

	rotation_y(M_PI_4, transf);
	TEST_ASSERT(tp_equal(point(sqrtf(2)/2, 0, sqrtf(2)/2), mtx_tup_mul(pt, transf)));
	rotation_y(M_PI_2, transf);
	TEST_ASSERT(tp_equal(point(1, 0, 0), mtx_tup_mul(pt, transf)));
}

void	test_inverse_rotation_y()
{
	t_mtx4	transf;
	t_mtx4	inv;
	t_tuple	pt = point(0, 0, 1);

	rotation_y(M_PI_4, transf);
	mtx4_inverse(transf, inv);
	TEST_ASSERT(tp_equal(point(-sqrtf(2)/2, 0, sqrtf(2)/2), mtx_tup_mul(pt, inv)));
	rotation_y(M_PI_2, transf);
	mtx4_inverse(transf, inv);
	TEST_ASSERT(tp_equal(point(-1, 0, 0), mtx_tup_mul(pt, inv)));
}

void	test_rotation_z()
{
	t_mtx4	transf;
	t_tuple	pt = point(0, 1, 0);

	rotation_z(M_PI_4, transf);
	TEST_ASSERT(tp_equal(point(-sqrtf(2)/2, sqrtf(2)/2, 0), mtx_tup_mul(pt, transf)));
	rotation_z(M_PI_2, transf);
	TEST_ASSERT(tp_equal(point(-1, 0, 0), mtx_tup_mul(pt, transf)));
}

void	test_inverse_rotation_z()
{
	t_mtx4	transf;
	t_mtx4	inv;
	t_tuple	pt = point(0, 1, 0);

	rotation_z(M_PI_4, transf);
	mtx4_inverse(transf, inv);
	TEST_ASSERT(tp_equal(point(sqrtf(2)/2, sqrtf(2)/2, 0), mtx_tup_mul(pt, inv)));
	rotation_z(M_PI_2, transf);
	mtx4_inverse(transf, inv);
	TEST_ASSERT(tp_equal(point(1, 0, 0), mtx_tup_mul(pt, inv)));
}

void	test_shearing()
{
	t_mtx4	transf;
	t_tuple pt = point(2, 3, 4);

	shearing((double[2]){1, 0}, g_arr2_0, g_arr2_0, transf);
	TEST_ASSERT(tp_equal(point(5, 3, 4), mtx_tup_mul(pt, transf)));
	shearing((double[2]){0, 1}, g_arr2_0, g_arr2_0, transf);
	TEST_ASSERT(tp_equal(point(6, 3, 4), mtx_tup_mul(pt, transf)));
	shearing(g_arr2_0, (double[2]){1, 0}, g_arr2_0, transf);
	TEST_ASSERT(tp_equal(point(2, 5, 4), mtx_tup_mul(pt, transf)));
	shearing(g_arr2_0, (double[2]){0, 1}, g_arr2_0, transf);
	TEST_ASSERT(tp_equal(point(2, 7, 4), mtx_tup_mul(pt, transf)));
	shearing(g_arr2_0, g_arr2_0, (double[2]){1, 0}, transf);
	TEST_ASSERT(tp_equal(point(2, 3, 6), mtx_tup_mul(pt, transf)));
	shearing(g_arr2_0, g_arr2_0, (double[2]){0, 1}, transf);
	TEST_ASSERT(tp_equal(point(2, 3, 7), mtx_tup_mul(pt, transf)));
}

void	test_chain_transformations()
{
	t_mtx4	rot;
	t_mtx4	scale;
	t_mtx4	transl;
	t_tuple	pt = point(1, 2, 3);

	translation(1, 1, 1, transl);
	rotation_x(M_PI, rot);
	scaling(2, 2, 2, scale);
	pt = mtx_tup_mul(pt, rot);
	pt = mtx_tup_mul(pt, scale);
	pt = mtx_tup_mul(pt, transl);
	TEST_ASSERT(tp_equal(point(3, -3, -5), pt));
}

void	test_chain_transformations2()
{
	t_tuple	pt = point(1, 0, 1);

	pt = tp_translation(10, 5, 7, tp_scaling(5, 5, 5, tp_rotation_x(M_PI_2, pt)));
	TEST_ASSERT(tp_equal(point(15, 0, 7), pt));
}

void	test_chain_transformations3()
{
	t_tuple	pt = point(1, 0, 1);
	t_mtx4	transf;

	mx_rotation_x(M_PI_2, mx_scaling(5, 5, 5,
		mx_translation(10, 5, 7, mtx4_dup(g_identity_matrix, transf))));
	mtx_tup_mul2(&pt, transf);
	TEST_ASSERT(tp_equal(point(15, 0, 7), pt));
}

void	test_mtx_return()
{
	t_mtx4	res;
	t_mtx4	res2;
	t_mtx4	res3;

	TEST_ASSERT_EQUAL_PTR(res, rotation_x(M_PI, res));
	TEST_ASSERT_EQUAL_PTR(res, rotation_y(M_PI, res));
	TEST_ASSERT_EQUAL_PTR(res, rotation_z(M_PI, res));
	TEST_ASSERT_EQUAL_PTR(res2, mtx4_dup(res, res2));
	TEST_ASSERT_EQUAL_PTR(res3, mtx_mul(res, res2, res3));
}

void	test_rays();

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
	RUN_TEST(test_matrix44_multiplication2);
	RUN_TEST(test_matrix_tup_mul);
	RUN_TEST(test_matrix_tup_mul2);
	RUN_TEST(test_matrix44_identity);
	RUN_TEST(test_matrix_tup_identity);
	RUN_TEST(test_matrix_transpose);
	RUN_TEST(test_matrix_transpose2);
	RUN_TEST(test_identity_transpose);
	RUN_TEST(test_matrix2_determinant);
	RUN_TEST(test_matrix4_submatrix);
	RUN_TEST(test_matrix3_submatrix);
	RUN_TEST(test_matrix3_minor);
	RUN_TEST(test_matrix3_determinant);
	RUN_TEST(test_matrix4_determinant);
	RUN_TEST(test_matrix4_is_invertible);
	RUN_TEST(test_matrix4_inversion);
	RUN_TEST(test_matrix4_inversion2);
	RUN_TEST(test_matrix4_inversion3);
	RUN_TEST(test_matrix4_mult_inverse);
	RUN_TEST(test_matrix4_duplication);
	RUN_TEST(test_translation);
	RUN_TEST(test_inverse_translation);
	RUN_TEST(test_vector_translation);
	RUN_TEST(test_scaling);
	RUN_TEST(test_vector_scaling);
	RUN_TEST(test_inverse_scaling);
	RUN_TEST(test_rotation_x);
	RUN_TEST(test_inverse_rotation_x);
	RUN_TEST(test_rotation_y);
	RUN_TEST(test_inverse_rotation_y);
	RUN_TEST(test_rotation_z);
	RUN_TEST(test_inverse_rotation_z);
	RUN_TEST(test_shearing);
	RUN_TEST(test_chain_transformations);
	RUN_TEST(test_chain_transformations2);
	RUN_TEST(test_chain_transformations3);
	RUN_TEST(test_mtx_return);
	test_rays();
	return UNITY_END();;
}
