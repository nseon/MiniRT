/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:36:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/19 15:54:17 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include "points.h"

#include <stdio.h>
#include <math.h>

float	sphere_intersect(struct s_obj sphere,
						t_point3 const origin, t_vec3 const d)
{
	const t_vec3	co = get_vec3(sphere.pos, origin);
	const float		b = 2 * v3_dotproduct(co, d);
	const float		a = v3_dotproduct(d, d);
	const float		c = v3_dotproduct(co, co) - sphere.w * sphere.w;
	float			dis[2];

	dis[0] = (float){b * b - 4 * a * c};
	if (dis[0] < 0)
		return (0);
	dis[1] = sqrtf(dis[0]);
	if ((0 - b - dis[1]) / (2 * a) < T_MIN)
		return ((0 - b + dis[1]) / (2 * a));
	return ((0 - b - dis[1]) / (2 * a));
}

static struct s_obj get_sphere(t_graphic_ctx *gctx,
								t_point3      origin, t_vec3 d, float *t_ptr)
{
	float        t_min;
	float        t;
	size_t       i;
	struct s_obj closest_sphere;

	i = -1;
	t_min = T_MAX;
	closest_sphere = (struct s_obj){0};
	while (++i < vct_size(gctx->objs))
	{
		if (gctx->objs[i].type != SPHERE)
			continue ;
		t = sphere_intersect(gctx->objs[i], origin, d);
		if (t < t_min && t >= T_MIN)
		{
			t_min = t;
			*t_ptr = t;
			closest_sphere = gctx->objs[i];
		}
	}
	return (closest_sphere);
}

t_vec3 random_bounce(uint8_t const random[RAY_NBR], t_vec3 ojb_norm)
{
	t_vec3 bounce;

	bounce = random_vec(random);
	// while (get_distance(bounce, (t_point3){0, 0, 0}) > 1)
	// 	bounce = random_vec(random);
	v3_normalize(bounce);
	if (v3_dotproduct(bounce, ojb_norm) <= 0)
		v3_invert(&bounce);
	return (bounce);
}

uint32_t	trace_ray(t_graphic_ctx *gctx,
					t_ren_calc	ren, uint8_t n, uint8_t const random[RAY_NBR])
{
	float				t_min;
	struct s_obj const	closest_sphere = get_sphere(gctx, ren.o, ren.d, &t_min);
	uint32_t			color_bounce;

	if (closest_sphere.w == 0)
		return (BACKGROUND_COLOR);
	ren.p = v3_add(ren.o, v3_multiply(ren.d, t_min));
	ren.n = v3_normalize(get_vec3(closest_sphere.pos, ren.p));
	ren.s = closest_sphere.specular;
	// if (n == RAY_NUM || closest_sphere.reflective <= 0)
	// 	return (colorx(closest_sphere.col.argb, get_light(gctx, ren)));
	// refl_dir = v3_sub(v3_multiply(v3_multiply(ren.n, 2),
	// 			v3_dotproduct(ren.n, v3_multiply(ren.d, -1))), v3_multiply(ren.d, -1));
	if (gctx->global_il || n == RAY_NUM)
		return (colorx(closest_sphere.col.argb, get_light(gctx, ren)));
	ren.o = ren.p;
	ren.d = random_bounce(random, ren.n);
	color_bounce = trace_ray(gctx, ren, n + 1, random);
	if (color_bounce == BACKGROUND_COLOR)
		return (colorx(closest_sphere.col.argb, get_light(gctx, ren)));
	return (colorp(colorx(colorx(closest_sphere.col.argb, get_light(gctx, ren)), 0.4)
		, colorx(color_bounce, 0.6)));
}
