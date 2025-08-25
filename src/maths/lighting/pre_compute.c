/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:07:40 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/25 00:07:40 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "normals.h"
#include "rt_maths.h"

void	add_remove_last(t_intersection *last, int32_t *j, t_intersection it)
{
	int32_t	i;

	i = -1;
	while (++i < *j)
	{
		if (last[i].obj == it.obj)
		{
			while (i < *j - 1)
			{
				last[i] = last[i + 1];
				i++;
			}
			(*j)--;
			return ;
		}
	}
	last[*j] = it;
	*j += 1;
}

void	compute_refract_points(t_pre_compute *pc, t_intersections *xs)
{
	t_intersection	*last = xs->i + xs->count * REFRACT_XS_OFFSET;
	int32_t	j;
	int32_t	i;

	i = -1;
	j = 0;
	while (++i < xs->count)
	{
		if (xs->i[i].t == pc->t)
		{
			if (j == 0)
				pc->n1 = AIR_REFRACTIVE;
			else
				pc->n1 = last[j - 1].obj->mat.refractive;
		}
		add_remove_last(last, &j, xs->i[i]);
		if (xs->i[i].t == pc->t)
		{
			if (j == 0)
				pc->n2 = AIR_REFRACTIVE;
			else
				pc->n2 = last[j - 1].obj->mat.refractive;
		}
	}
}

t_pre_compute	pre_compute(t_intersection *i, t_ray r, t_intersections *xs)
{
	t_pre_compute	pc;

	pc.t = i->t;
	pc.obj = i->obj;
	pc.pos = position(r, pc.t);
	pc.eyev = tp_negate(r.dir);
	pc.normalv = obj_normal(i->obj, pc.pos);
	if (tp_dot(pc.normalv, pc.eyev) < 0)
	{
		pc.inside = true;
		pc.normalv = tp_negate(pc.normalv);
	}
	else
		pc.inside = false;
	pc.over_point = tp_add(pc.pos, tp_mul(pc.normalv, DEPSILON));
	pc.under_point = tp_sub(pc.pos, tp_mul(pc.normalv, DEPSILON));
	pc.reflectv = reflect(r.dir, pc.normalv);
	if (xs)
		compute_refract_points(&pc, xs);
	return (pc);
}
