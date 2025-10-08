/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:22:09 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/18 11:22:09 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "draw.h"

void	draw_rectangle(t_image *img, t_point origin, int32_t w, int32_t h)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			put_pixel_img(img, point_s(origin.x + x, origin.y + y,
					origin.color));
			++x;
		}
		++y;
	}
}

void	draw_background(t_image *img, uint32_t color)
{
	draw_rectangle(img, (t_point){0, 0, color}, img->w, img->h);
}
