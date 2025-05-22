/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:58:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/22 17:58:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "neflibx.h"

#include <stddef.h>

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
		lum += ctx.lights[i].i * dot_n_l / (v3_magnitude(n) * v3_magnitude(l));
	}
	if (lum > 1)
		lum = 1;
	return (lum);
}
