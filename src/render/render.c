/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:52:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/22 11:45:50 by nseon            ###   ########.fr       */
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
	const float	b = 2 * v3_dotproduct(CO, d);
	const float a = v3_dotproduct(d, d);
	const float c = v3_dotproduct(CO, CO) - sphere.radius * sphere.radius;
	const float dis = b * b - 4 * a * c;

	if (dis < 0)
		return (0);
	return ((- b - sqrtf(dis)) / (2 * a));
}

float	get_closer_sphere_pt(t_camera const camera, t_sphere *spheres, t_vec3 d)
{
	float	t1;
	float	t2;
	size_t	i;
	const size_t	size = vct_size(spheres);

	i = -1;
	t1 = __FLT_MAX__;
	while (++i < size)
	{
		t2 = get_cercle_pt(camera, spheres[i], d);
		if (t2 < t1 && t2 > 1)
			t1 = t2;
	}
	return (t1);
}

void		render(t_ctx ctx)
{
	int16_t			x;
	int16_t			y;
	float			t;
	t_vec3			d;
	t_point3		render_point;
	

	x = -1;
	while (++x < ctx.win.x)
	{
		y = -1;
		while (++y < ctx.win.y)
		{
			d = win_to_vp(ctx, x, y);
			t = get_closer_sphere_pt(ctx.cam, ctx.spheres, d);
			if (t > 1)
			{
				render_point = render_equation(ctx.cam, d, t);
				put_pixel_img(&ctx.img, (t_point){x, y, argb(0, 245 * (1 - (render_point.z - 900) / 250), 0, 0)});
			}
			else
				put_pixel_img(&ctx.img, (t_point){x, y, argb(0, 0, 0, 0)});
		}
	}
}
