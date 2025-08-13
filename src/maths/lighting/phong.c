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

t_fcolor	phong(t_material m, t_phong_comp c)
{
	t_fcolor const	eff_color = color_mul(c.light.i, m.col);
	float			light_dot_normal;
	t_fcolor		diffuse;
	t_fcolor		specular;
	float			reflect_dot_eye;

	c.lightv = tp_normalize(tp_sub(c.light.pos, c.pos));
	light_dot_normal = tp_dot(c.lightv, c.normalv);
	diffuse = fcolor(0, 0, 0);
	specular = fcolor(0, 0, 0);
	if (light_dot_normal >= 0)
	{
		diffuse = color_scalar(eff_color, m.diffuse * light_dot_normal);
		reflect_dot_eye = tp_dot(reflect(tp_mul(c.lightv, -1),
			c.normalv), c.eyev);
		if (reflect_dot_eye > 0)
			specular = color_scalar(c.light.i, m.specular
				* powf(reflect_dot_eye, m.shine));
	}
	return (color_add(color_add(color_scalar(eff_color, m.ambient),
		diffuse), specular));
}
