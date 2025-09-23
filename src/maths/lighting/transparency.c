/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 01:30:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/25 01:30:03 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: peut etre compute les refract du hit seulement si transparence

#include <math.h>

#include "lighting.h"
#include "ray.h"
#include "normals.h"
#include "rt_maths.h"

double	schlick(t_pre_compute *pc)
{
	double	cos;
	double	n_ratio;
	double	sin2_t;
	double	r0;

	cos = tp_dot(pc->eyev, pc->normalv);
	if (pc->n1 > pc->n2)
	{
		n_ratio = pc->n1 / pc->n2;
		sin2_t = n_ratio * n_ratio * (1 - cos * cos);
		if (sin2_t > 1)
			return (1);
		cos = sqrt(1 - sin2_t);
	}
	r0 = pow((pc->n1 - pc->n2) / (pc->n1 + pc->n2), 2);
	return (r0 + (1 - r0) * pow(1 - cos, 5));
}

t_fcolor	refract_color(t_world *w, t_pre_compute *pc, int n)
{
	t_ray		r;
	t_tuple		dir;
	double		ratio;
	double		cos_i;
	double		sin2_t;

	if (n < 1 || d_equal(pc->obj->mat.transparency, 0))
		return (fcolor(0, 0, 0));
	ratio = pc->n1 / pc->n2;
	cos_i = tp_dot(pc->eyev, pc->normalv);
	sin2_t = ratio * ratio * (1 - cos_i * cos_i);
	if (sin2_t > 1)
		return (fcolor(0, 0, 0));
	dir = tp_sub(tp_mul(pc->normalv, ratio * cos_i - sqrt(1 - sin2_t)),
			tp_mul(pc->eyev, ratio));
	r = ray(pc->under_point, dir);
	return (col_scalar(color_at(w, r, n - 1), pc->obj->mat.transparency));
}
