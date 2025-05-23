/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:52:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/23 13:30:59 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "render.h"
#include "neflibx.h"

#include <math.h>
#include <stdint.h>
#include <limits.h>

t_vec3	win_to_vp(t_ctx const ctx, int16_t const x, int16_t const y)
{
	const float		vx = x * ctx.cam.vp.vw / ctx.win.x + ctx.cam.pos.x - ctx.cam.vp.vw / 2;
	const float		vy = y * ctx.cam.vp.vh / ctx.win.y + ctx.cam.pos.y - ctx.cam.vp.vh / 2;
	const t_vec3	vp_point = {vx,
		vy, ctx.cam.vp.d + ctx.cam.pos.z};

	return (get_vec3(ctx.cam.pos, vp_point));
}

t_point3	render_equation(t_camera const camera, t_vec3 d, float t)
{
	return (v3_add(camera.pos, v3_multiply(d, t)));
}

float		get_cercle_pt(t_camera const camera, t_sphere const sphere, t_vec3 d)
{
	const t_vec3	CO = get_vec3(sphere.pos, camera.pos);
	const float		b = 2 * v3_dotproduct(CO, d);
	const float 	a = v3_dotproduct(d, d);
	const float 	c = v3_dotproduct(CO, CO) - sphere.radius * sphere.radius;
	float 			dis[2] = {b * b - 4 * a * c};

	if (dis[0] < 0)
		return (0);
	dis[1] = sqrtf(dis[0]);
	if ((- b - dis[1]) / (2 * a) < 1)
		return ((- b + dis[1]) / (2 * a));
	return ((- b - dis[1]) / (2 * a));
}

int32_t	multi_color(int32_t color, float m)
{
	return (((int32_t)(((color >> 16) & 0xFF) * m) << 16) |
		((int32_t)(((color >> 8) & 0xFF) * m) << 8) |
		((int32_t)(((color) & 0xFF) * m)));
}

int32_t	get_closer_sphere_pt(t_ctx const ctx, t_vec3 d)
{
	float		t_min;
	float		t;
	t_point3	p;
	size_t		i;
	t_sphere	closest_sphere;

	i = -1;
	t_min = T_MAX;
	closest_sphere = (t_sphere){0};
	while (++i < vct_size(ctx.spheres))
	{
		t = get_cercle_pt(ctx.cam, ctx.spheres[i], d);
		if (t < t_min && t >= T_MIN)
		{
			t_min = t;
			closest_sphere = ctx.spheres[i];
		}
	}
	if (closest_sphere.radius == 0)
		return (BACKGROUND_COLOR);
	p = v3_add(ctx.cam.pos, v3_multiply(d, t_min));
	return (multi_color(closest_sphere.color,
		get_diffuse(ctx, p,
			v3_normalize(get_vec3(closest_sphere.pos, p)))));
}

void		render(t_ctx ctx)
{
	int16_t			x;
	int16_t			y;
	t_vec3			d;

	x = -1;
	while (++x < ctx.win.x)
	{
		y = -1;
		while (++y < ctx.win.y)
		{
			d = win_to_vp(ctx, x, y);
			put_pixel_img(&ctx.img, (t_point){x, y,
				get_closer_sphere_pt(ctx, d)});
		}
	}
}
