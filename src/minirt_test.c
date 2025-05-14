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

#include "/home/pjarnac/unit_tests/Unity/src/unity.h"

void	setUp()
{

}

void	tearDown()
{

}

void	test_test()
{
	TEST_ASSERT_EQUAL(1, 1);
}

int	main()
{
	UNITY_BEGIN();
	RUN_TEST(test_test);
	return UNITY_END();
}
