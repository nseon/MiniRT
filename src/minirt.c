/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/21 13:49:05 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "mesh.h"
#include "render.h"
#include "neflibx.h"
#include "inputs.h"

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

t_point3	render_equation(t_camera const camera, t_point3 vp, float t)
{
	return (v3_add(camera.pos, v3_multiply(get_vec3(camera.pos, vp), t)));
}

float		get_cercle_pt(t_camera const camera, t_sphere const sphere, t_point3 vp)
{
	const t_vec3	CO = get_vec3(sphere.pos, camera.pos);
	const t_vec3	D = get_vec3(camera.pos, vp);
	const float	b = 2 * v3_dotproduct(CO, D);
	const float a = v3_dotproduct(D, D);
	const float c = v3_dotproduct(CO, CO) - sphere.radius * sphere.radius;
	const float dis = b * b - 4 * a * c;

	if (dis < 0)
		return (0);
	return ((- b - sqrtf(dis)) / (2 * a));
}

t_point3	get_vp_place(t_camera const camera)
{
	return ((t_point3){camera.pos.x - camera.vp.vw / 2, camera.pos.y - camera.vp.vh / 2, camera.pos.z + camera.vp.d});
}

void		render(t_camera const camera, t_image *img)
{
	const t_sphere		sphere = {{960, 540, 1000}, 100};
	float				t;
	t_point3			render_point;

	for (int x = 0; x < camera.vp.vw; x++)
	{
		for (int y = 0; y < camera.vp.vh; y++)
		{
			t = get_cercle_pt(camera, sphere, v3_add(get_vp_place(camera), (t_point3){x, y, 0}));
			if (t == 0)
			{
				put_pixel_img(img, (t_point){x, y, argb(0, 245, 222, 179)});
			}
			else
			{
				render_point = render_equation(camera, v3_add(get_vp_place(camera), (t_point3){x, y, 0}), t);
				put_pixel_img(img, (t_point){x, y, argb(0, 245 * (1 - (render_point.z - 900) / 250), 0, 0)});
			}
		}
	}
}

int	main(int c, char **args)
{
	t_camera	camera = {.pos = {960, 540, 0}, .orient = {0, 0, 1},
		.vp = {1920, 1080, 1500}};

	t_point3			render_point;
	float				t;
	t_window		win;
	t_image			img;

	init_window(&win, 1920, 1080, "MiniRT");
	create_image(&img, 1920, 1080, &win);
	render(camera, &img);
	put_img(&img, 0, 0);
	register_destroy(win.events, end, &win);
	register_keypress(win.events, move_cam, &((t_ctx){camera, img, win}));
	loop(&win);
	return (0);
}
