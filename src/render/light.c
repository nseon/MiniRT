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

float	get_shine(t_ctx const ctx, t_point3 p, t_vec3 n, t_vec3 l, int s)
{
	t_vec3	r;
	t_vec3	v;
	
	r = v3_sub(v3_multiply(v3_multiply(n, 2), v3_dotproduct(n, l)), l);
	v = get_vec3(p, ctx.cam.pos);
	return (powf(v3_dotproduct(r, v) / (v3_magnitude(r) * v3_magnitude(v)), s));
}

float	get_diffuse(t_ctx const ctx, t_point3 p, t_vec3 n)
{
	t_vec3	l;
	size_t	i;
	float	lum;
	float	dot_n_l;

	i = -1;
	lum = 0;
	lum += ctx.amb_light.i;
	while (++i < vct_size(ctx.lights))
	{
		if (ctx.lights[i].type == POINT)
			l = get_vec3(p, ctx.lights[i].pos);
		else
			l = v3_multiply(ctx.lights[i].pos, -1);
		dot_n_l = v3_dotproduct(n, l);
		if (dot_n_l <= 0)
			continue ;
		lum += ctx.lights[i].i * (dot_n_l / (v3_magnitude(n) * v3_magnitude(l))
			+ get_shine(ctx, p, n, l, 200));
	}
	if (lum > 1)
		lum = 1;
	return (lum);
}
