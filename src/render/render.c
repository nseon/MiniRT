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
#include <stdio.h>

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
	if ((0 - b - dis[1]) / (2 * a) < T_MIN)
		return ((0 - b + dis[1]) / (2 * a));
	return ((0 - b - dis[1]) / (2 * a));
}

uint32_t	multi_color(int32_t color, float m)
{
	t_color		ncolor;
	uint32_t	rgb[3];

	ncolor.argb = color;
	rgb[0] = ncolor.r * m;
	if (rgb[0] > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb[0];
	rgb[1] = ncolor.g * m;
	if (rgb[1] > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb[1];
	rgb[1] = ncolor.b * m;
	if (rgb[1] > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb[1];
	return (ncolor.argb);
}

uint32_t	add_color(uint32_t color, uint32_t color2)
{
	t_color		ncolor;
	t_color		ncolor2;
	uint32_t	rgb[3];

	ncolor.argb = color;
	ncolor2.argb = color2;
	rgb[0] = ncolor.r + ncolor2.r;
	if (rgb[0] > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb[0];
	rgb[1] = ncolor.g + ncolor2.g;
	if (rgb[1] > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb[1];
	rgb[1] = ncolor.b + ncolor2.b;
	if (rgb[1] > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb[1];
	return (ncolor.argb);
}

static int32_t	trace_ray(t_graphic_ctx const gctx,
	t_ren_calc ren, uint8_t n)
{
	float		t_min;
	float		t;
	size_t		i;
	t_sphere	closest_sphere;
	t_vec3		refl_dir;

	i = -1;
	t_min = T_MAX;
	closest_sphere = (t_sphere){0};
	while (++i < vct_size(gctx.spheres))
	{
		t = get_cercle_pt(ren.o, gctx.spheres[i], ren.d);
		if (t < t_min && t >= T_MIN)
		{
			t_min = t;
			closest_sphere = gctx.spheres[i];
		}
	}
	if (closest_sphere.radius == 0)
		return (BACKGROUND_COLOR);
	ren.p = v3_add(ren.o, v3_multiply(ren.d, t_min));
	ren.n = v3_normalize(get_vec3(closest_sphere.pos, ren.p));
	ren.s = closest_sphere.specular;
	if (n == RAY_NUM || closest_sphere.reflective <= 0)
		return (multi_color(closest_sphere.color, get_light(gctx, ren)));
	refl_dir = v3_sub(v3_multiply(v3_multiply(ren.n, 2),
				v3_dotproduct(ren.n, v3_multiply(ren.d, -1))), v3_multiply(ren.d, -1));
	ren.o = ren.p;
	ren.d = refl_dir;
	return (add_color(multi_color(multi_color(closest_sphere.color, get_light(gctx, ren)), 1 - closest_sphere.reflective)
		, multi_color(trace_ray(gctx, ren, n + 1), closest_sphere.reflective)));
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
			ren.o = gctx.cam.pos;
			put_pixel_img(img, (t_point){x, y,
				trace_ray(gctx, ren, 0)});
		}
	}
}
