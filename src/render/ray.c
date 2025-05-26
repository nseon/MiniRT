/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:36:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/26 18:36:00 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include <math.h>

float	sphere_intersect(t_sphere const sphere,
	t_point3 const origin, t_vec3 const d)
{
	const t_vec3	co = get_vec3(sphere.pos, origin);
	const float		b = 2 * v3_dotproduct(co, d);
	const float		a = v3_dotproduct(d, d);
	const float		c = v3_dotproduct(co, co) - sphere.radius * sphere.radius;
	float			dis[2];

	dis[0] = (float){b * b - 4 * a * c};
	if (dis[0] < 0)
		return (0);
	dis[1] = sqrtf(dis[0]);
	if ((0 - b - dis[1]) / (2 * a) < T_MIN)
		return ((0 - b + dis[1]) / (2 * a));
	return ((0 - b - dis[1]) / (2 * a));
}

static t_sphere	get_sphere(t_graphic_ctx const gctx,
	t_point3 const origin, t_vec3 const d, float *const t_ptr)
{
	float		t_min;
	float		t;
	size_t		i;
	t_sphere	closest_sphere;

	i = -1;
	t_min = T_MAX;
	closest_sphere = (t_sphere){0};
	while (++i < vct_size(gctx.spheres))
	{
		t = sphere_intersect(gctx.spheres[i], origin, d);
		if (t < t_min && t >= T_MIN)
		{
			t_min = t;
			*t_ptr = t;
			closest_sphere = gctx.spheres[i];
		}
	}
	return (closest_sphere);
}

uint32_t	trace_ray(t_graphic_ctx const gctx,
	t_ren_calc ren, uint8_t n)
{
	float			t_min;
	t_sphere const	closest_sphere = get_sphere(gctx, ren.o, ren.d, &t_min);
	t_vec3			refl_dir;

	if (closest_sphere.radius == 0)
		return (BACKGROUND_COLOR);
	ren.p = v3_add(ren.o, v3_multiply(ren.d, t_min));
	ren.n = v3_normalize(get_vec3(closest_sphere.pos, ren.p));
	ren.s = closest_sphere.specular;
	if (n == RAY_NUM || closest_sphere.reflective <= 0)
		return (colorx(closest_sphere.color, get_light(gctx, ren)));
	refl_dir = v3_sub(v3_multiply(v3_multiply(ren.n, 2),
				v3_dotproduct(ren.n, v3_multiply(ren.d, -1))), v3_multiply(ren.d, -1));
	ren.o = ren.p;
	ren.d = refl_dir;
	return (colorp(colorx(colorx(closest_sphere.color, get_light(gctx, ren)), 1 - closest_sphere.reflective)
		, colorx(trace_ray(gctx, ren, n + 1), closest_sphere.reflective)));
}
