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

float	get_specular(t_ctx const ctx, t_ren_calc ren)
{
	t_vec3	r;
	t_vec3	v;

	r = v3_sub(v3_multiply(v3_multiply(ren.n, 2),
				v3_dotproduct(ren.n, ren.l)), ren.l);
	v = get_vec3(ren.p, ctx.cam.pos);
	return (powf(v3_dotproduct(r, v)
			/ (v3_magnitude(r) * v3_magnitude(v)), ren.s));
}

float	get_light(t_ctx const ctx, t_ren_calc ren)
{
	size_t	i;
	float	lum;
	float	dot_n_l;

	i = -1;
	lum = 0;
	lum += ctx.amb_light.i;
	if (ctx.lights_off)
		return (lum);
	while (++i < vct_size(ctx.lights))
	{
		if (ctx.lights[i].type == POINT)
			ren.l = get_vec3(ren.p, ctx.lights[i].pos);
		else
			ren.l = v3_multiply(ctx.lights[i].pos, -1);
		dot_n_l = v3_dotproduct(ren.n, ren.l);
		if (dot_n_l <= 0)
			continue ;
		lum += ctx.lights[i].i * (dot_n_l / (v3_magnitude(ren.n)
					* v3_magnitude(ren.l)) + get_specular(ctx, ren));
	}
	if (lum > 1)
		lum = 1;
	return (lum);
}
