/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/19 12:51:14 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "render.h"

#include "lighting.h"


t_image		*render(t_image *img, t_camera cam, t_world *world)
{
	int32_t		x;
	int32_t		y;
	t_fcolor	color;

	y = -1;
	while (++y < cam.vsize)
	{
		x = -1;
		while (++x < cam.hsize)
		{
			color = color_at(world, ray_for_pixel(cam, x, y), 4);
			put_pixel_img(img, point_s(x, y, fcolor_to_uint(color)));
		}
	}
	return (img);
}
