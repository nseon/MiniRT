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

t_fcolor	phong(t_material m, t_light light, t_pre_compute *pc,
	uint32_t gparam)
{
	t_fcolor		eff_color;
	t_tuple const	lightv = tp_normalize(tp_sub(light.pos, pc->over_point));
	t_fcolor		diffuse;
	t_fcolor		specular;
	double			reflect_dot_eye;

	if (m.has_pat)
		eff_color = color_mul(light.i, pattern_at_obj(m.pat, pc->obj, pc->pos));
	else
		eff_color = color_mul(light.i, m.col);
	diffuse = fcolor(0, 0, 0);
	specular = fcolor(0, 0, 0);
	if (tp_dot(lightv, pc->normalv) < 0)
		return (fcolor(0, 0, 0));
	if (gparam & DIFFUSE)
		diffuse = col_scalar(eff_color, m.diffuse
				* tp_dot(lightv, pc->normalv));
	reflect_dot_eye = tp_dot(reflect(tp_mul(lightv, -1),
				pc->normalv), pc->eyev);
	if (gparam & SPECULAR && reflect_dot_eye > 0)
		specular = col_scalar(light.i, m.specular
				* powf(reflect_dot_eye, m.shine));
	return (color_add(diffuse, specular));
}
