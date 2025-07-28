/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:58:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/26 14:20:28 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "neflibx.h"

#include <stddef.h>
#include <math.h>
#include <stdio.h>

bool	is_in_shadow(t_light light, t_obj *objs, t_ren_calc ren)
{
	size_t	i;
	float	t;

	i = -1;
	while (++i < vct_size(objs))
	{
		if (objs[i].type != SPHERE)
			continue ;
		t = sphere_intersect(objs[i], ren.p, ren.l);
		if ((light.type == POINT && 0.01 < t && t < 1) || (light.type == DIR && t > 0.01))
			return (1);
	}
	return (0);
}

float	get_specular(t_graphic_ctx *gctx, t_ren_calc ren)
{
	float	dot_r_v;

	if (ren.s < 0)
		return (0);
	ren.r = v3_sub(v3_multiply(v3_multiply(ren.n, 2),
				v3_dotproduct(ren.n, ren.l)), ren.l);
	ren.v = get_vec3(ren.p, gctx->cam.pos);
	dot_r_v = v3_dotproduct(ren.r, ren.v);
	if (dot_r_v < 0)
		return (0);
	return (powf(dot_r_v
		/ (v3_magnitude(ren.r) * v3_magnitude(ren.v)), ren.s));
}

float	get_light(t_graphic_ctx *gctx, t_ren_calc ren)
{
	size_t	i;
	float	lum;
	float	dot_n_l;

	i = -1;
	lum = 0;
	lum += gctx->amb_light.i;
	if (gctx->lights_off)
		return (lum);
	while (++i < vct_size(gctx->lights))
	{
		if (gctx->lights[i].type == POINT)
			ren.l = get_vec3(ren.p, gctx->lights[i].pos);
		else
			ren.l = v3_multiply(gctx->lights[i].pos, -1);
		dot_n_l = v3_dotproduct(ren.n, ren.l);
		if (dot_n_l <= 0 || is_in_shadow(gctx->lights[i], gctx->objs, ren))
			continue ;
		lum += gctx->lights[i].i * (dot_n_l / (v3_magnitude(ren.n)
					* v3_magnitude(ren.l)) + get_specular(gctx, ren));
	}
	return (lum);
}
