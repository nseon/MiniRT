/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:52:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/21 14:52:26 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "render.h"
#include "neflibx.h"

#include <math.h>
#include <stdint.h>

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

void		render(t_ctx ctx)
{
	int16_t			x;
	int16_t			y;
	float			t;
	t_vec3			d;
	t_point3		render_point;
	const t_sphere	sphere = {{0, 0, 1000}, 100};

	x = -1;
	while (++x < ctx.win.x)
	{
		y = -1;
		while (++y < ctx.win.y)
		{
			d = win_to_vp(ctx, x, y);
			t = get_cercle_pt(ctx.cam, sphere, win_to_vp(ctx, x, y));
			if (t < 1)
			{
				put_pixel_img(&ctx.img, (t_point){x, y, argb(0, 245, 222, 179)});
			}
			else
			{
				render_point = render_equation(ctx.cam, d, t);
				put_pixel_img(&ctx.img, (t_point){x, y, argb(0, 245 * (1 - (render_point.z - 900) / 250), 0, 0)});
			}
		}
	}
}
