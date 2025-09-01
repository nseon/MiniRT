/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:25:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/28 08:43:17 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"
#include "ray.h"
#include "supersampling.h"
#include "render.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	return ((t_ray){origin, direction});
}

t_tuple	position(t_ray ray, double t)
{
	return (tp_add(ray.origin, tp_mul(ray.dir, t)));
}

t_ray	ray_transform(t_ray r, t_mtx4 m)
{
	return ((t_ray){mtx_tup_mul(r.origin, m), mtx_tup_mul(r.dir, m)});
}

t_ray	ray_for_pixel(t_camera cam, double x, double y)
{
	double const		wx = cam.half_width - (x + 0.5) * cam.pixel_size;
	double const		wy = cam.half_height - (y + 0.5) * cam.pixel_size;
	t_tuple const	pixel = mtx_tup_mul(point(wx, wy, -1), cam.inverse);
	t_tuple const	origin = mtx_tup_mul(point(0, 0, 0), cam.inverse);

	return ((t_ray){origin, tp_normalize(tp_sub(pixel, origin))});
}

t_tuple random_bounce(uint8_t const random[RAY_NBR], t_tuple ojb_norm)
{
	t_tuple bounce;

	bounce = random_vec(random);
	// while (get_distance(bounce, (t_point3){0, 0, 0}) > 1)
	// 	bounce = random_vec(random);
	tp_normalize(bounce);
	if (tp_dot(bounce, ojb_norm) <= 0)
		tp_invert(&bounce);
	return (bounce);
}
