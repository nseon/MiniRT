/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:16:30 by nseon             #+#    #+#             */
/*   Updated: 2025/09/09 16:31:00 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "minirt.h"
#include "neflibx.h"
#include "render.h"

int32_t	init_ss(t_gctx *gctx, int32_t max_rays)
{
	t_ss	ss;

	ss.samples = malloc(sizeof (t_rgb96_t) * WIN_H * WIN_W);
	if (!ss.samples)
		return (FATAL);
	ft_bzero(ss.samples, sizeof (t_rgb96_t) * WIN_H * WIN_W);
	ss.sample_num = 0;
	ss.max_sample = max_rays;
	gctx->ss = ss;
	return (SUCCESS);
}

void	clear_ss(t_ss *ss)
{
	ft_bzero(ss->samples, sizeof (t_rgb96_t) * WIN_H * WIN_W);
	ss->sample_num = 0;
}

void	add_ss_frame(t_ss *ss, t_fcolor *frame)
{
	t_color	col;
	int32_t	x;
	int32_t	y;

	ss->sample_num += 1;
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			col.argb = fcolor_to_uint(frame[y * WIN_W + x]);
			ss->samples[y * WIN_W + x].r += col.r;
			ss->samples[y * WIN_W + x].g += col.g;
			ss->samples[y * WIN_W + x].b += col.b;
			frame[y * WIN_W + x] = get_ss_color(ss, x, y);
		}
	}
}

t_fcolor	get_ss_color(t_ss *ss, int32_t x, int32_t y)
{
	t_fcolor	color;
	t_rgb96_t	col96;

	col96 = ss->samples[y * WIN_W + x];
	color.r = col96.r / ss->sample_num;
	color.g = col96.g / ss->sample_num;
	color.b = col96.b / ss->sample_num;
	color.r /= 255;
	color.g /= 255;
	color.b /= 255;
	return (color);
}
