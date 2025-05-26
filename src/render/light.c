/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:58:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/23 17:25:21 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "neflibx.h"

#include <stddef.h>
#include <math.h>

float	get_specular(t_graphic_ctx const gctx, t_ren_calc ren)
{
	float	dot_r_v;

	if (ren.s < 0)
		return (0);
	ren.r = v3_sub(v3_multiply(v3_multiply(ren.n, 2),
				v3_dotproduct(ren.n, ren.l)), ren.l);
	ren.v = get_vec3(ren.p, gctx.cam.pos);
	dot_r_v = v3_dotproduct(ren.r, ren.v);
	if (dot_r_v < 0)
		return (0);
	return (powf(dot_r_v
		/ (v3_magnitude(ren.r) * v3_magnitude(ren.v)), ren.s));
}

float	get_light(t_graphic_ctx const gctx, t_ren_calc ren)
{
	size_t	i;
	float	lum;
	float	dot_n_l;

	i = -1;
	lum = 0;
	lum += gctx.amb_light.i;
	if (gctx.lights_off)
		return (lum);
	while (++i < vct_size(gctx.lights))
	{
		if (gctx.lights[i].type == POINT)
			ren.l = get_vec3(ren.p, gctx.lights[i].pos);
		else
			ren.l = v3_multiply(gctx.lights[i].pos, -1);
		dot_n_l = v3_dotproduct(ren.n, ren.l);
		if (dot_n_l <= 0)
			continue ;
		lum += gctx.lights[i].i * (dot_n_l / (v3_magnitude(ren.n)
					* v3_magnitude(ren.l)) + get_specular(gctx, ren));
	}
	if (lum > 1)
		lum = 1;
	return (lum);
}
