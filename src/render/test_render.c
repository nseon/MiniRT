/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:10:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 15:10:21 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "minirt.h"
#include "matrix.h"

void	test_render(t_ctx * const ctx)
{
	t_tuple	pt = point(0, 100, 0);
	t_tuple	pt2;

	for (int i = 0; i < 48; i++)
	{
		pt2 = tp_translation(WIN_W / 2, WIN_H / 2, 0, tp_scaling(6, 1, 2, pt));
		put_pixel_img(&ctx->img, point_s(pt2.x, pt2.y, 0xFFFFFF));
		pt = tp_rotation_z(M_PI / 24, pt);
	}
}
