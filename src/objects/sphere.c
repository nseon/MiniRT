/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:21:04 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/12 18:21:04 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "normals.h"
#include "tuple.h"
#include "objects.h"
#include "ray.h"
#include "rt_maths.h"

t_obj	sphere(void)
{
	t_obj	o;

	o = (t_obj){.type = SPHERE, .uid = get_uid(), .mat = g_default_mat};
	mtx4_dup(g_identity_matrix, o.transform);
	mtx4_dup(g_identity_matrix, o.inv_transform);
	return (o);
}

t_obj	glass_sphere(void)
{
	t_obj	o;

	o = sphere();
	o.mat.transparency = 1;
	o.mat.refractive = 1.5;
	return (o);
}

t_tuple	sphere_normal(t_tuple pt)
{
	pt.w = 0;
	return (pt);
}

void	sphere_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	t_tuple const	d = tp_sub(r.origin, point(0, 0, 0));
	double const	b = 2 * tp_dot(r.dir, d);
	double const	a = tp_dot(r.dir, r.dir);
	double const	dis = b * b - 4 * a * (tp_dot(d, d) - 1);

	if (dis >= 0)
	{
		xs->i[xs->count] = intersection((- b - sqrt(dis)) / (2 * a), o);
		if (d_equal(0, dis))
			xs->i[xs->count + 1] = xs->i[0];
		else
			xs->i[xs->count + 1] = intersection((- b + sqrt(dis)) / (2 * a), o);
		xs->count += 2;
	}
}

t_tuple	sphere_uv_point(t_tuple	pt)
{
	pt = tp_negate(pt);
	pt.x = 0.5 + atan2(pt.z, pt.x) / (M_PI * 2);
	pt.z = 0.5 + asin(pt.y) / M_PI;
	pt.x *= 2;
	pt.z *= 2;
	pt.y = 0;
	pt.w = 1;
	return (pt);
}
