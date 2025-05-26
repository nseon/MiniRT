/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:52:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/26 12:55:11 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "render.h"
#include "neflibx.h"

#include <math.h>
#include <stdint.h>

#include "minirt.h"

static t_vec3	win_to_vp(t_graphic_ctx const gctx, int16_t const x,
	int16_t const y, t_image *img)
{
	const float		vx = x * gctx.cam.vp.vw / img->w + gctx.cam.pos.x
		- gctx.cam.vp.vw / 2;
	const float		vy = y * gctx.cam.vp.vh / img->h + gctx.cam.pos.y
		- gctx.cam.vp.vh / 2;
	const t_vec3	vp_point = {vx, vy, gctx.cam.vp.d + gctx.cam.pos.z};

	return (get_vec3(gctx.cam.pos, vp_point));
}

float	get_cercle_pt(t_point3 const origin,
	t_sphere const sphere, t_vec3 const d)
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
	if ((0 - b - dis[1]) / (2 * a) < 1)
		return ((0 - b + dis[1]) / (2 * a));
	return ((0 - b - dis[1]) / (2 * a));
}

int32_t	multi_color(int32_t color, float m)
{
	return (((int32_t)(((color >> 16) & 0xFF) * m) << 16) |
		((int32_t)(((color >> 8) & 0xFF) * m) << 8) |
		((int32_t)(((color) & 0xFF) * m)));
}

static int32_t	get_render_pt(t_graphic_ctx const gctx, t_ren_calc ren)
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
		t = get_cercle_pt(gctx.cam.pos, gctx.spheres[i], ren.d);
		if (t < t_min && t >= T_MIN)
		{
			t_min = t;
			closest_sphere = gctx.spheres[i];
		}
	}
	if (closest_sphere.radius == 0)
		return (BACKGROUND_COLOR);
	ren.p = v3_add(gctx.cam.pos, v3_multiply(ren.d, t_min));
	ren.n = v3_normalize(get_vec3(closest_sphere.pos, ren.p));
	ren.s = closest_sphere.specular;
	return (multi_color(closest_sphere.color, get_light(gctx, ren)));
}

void	render(t_graphic_ctx const gctx, t_image *img)
{
	int16_t			x;
	int16_t			y;
	t_ren_calc		ren;

	x = -1;
	while (++x < img->w)
	{
		y = -1;
		while (++y < img->h)
		{
			ren = (t_ren_calc){0};
			ren.d = win_to_vp(gctx, x, y, img);
			put_pixel_img(img, (t_point){x, y,
				get_render_pt(gctx, ren)});
		}
	}
}
