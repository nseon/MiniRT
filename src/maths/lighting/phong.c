/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:22:53 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/13 14:22:53 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "lighting.h"

t_fcolor	phong(t_material m, t_light light, t_pre_compute *pc)
{
	t_fcolor const	eff_color = color_mul(light.i, m.col);
	t_tuple const	lightv = tp_normalize(tp_sub(light.pos, pc->pos));
	t_fcolor		diffuse;
	t_fcolor		specular;
	float			reflect_dot_eye;

	diffuse = fcolor(0, 0, 0);
	specular = fcolor(0, 0, 0);
	if (tp_dot(lightv, pc->normalv) >= 0)
	{
		diffuse = color_scalar(eff_color, m.diffuse * tp_dot(lightv, pc->normalv));
		reflect_dot_eye = tp_dot(reflect(tp_mul(lightv, -1),
			pc->normalv), pc->eyev);
		if (reflect_dot_eye > 0)
			specular = color_scalar(light.i, m.specular
				* powf(reflect_dot_eye, m.shine));
	}
	return (color_add(color_add(color_scalar(eff_color, m.ambient),
		diffuse), specular));
}
