/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:26:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 20:26:28 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "ray.h"
#include "rt_maths.h"
#include "lib/libft/src/vector/vector.h"

t_intersection	intersection(double t, t_obj *obj)
{
	return ((t_intersection){t, obj});
}

void obj_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	r = ray_transform(r, o->inv_transform);
	if (o->type == SPHERE)
		sphere_intersect(r, o, xs);
}

t_intersection	*hit(t_intersections *inters)
{
	t_intersection	*min;
	int32_t			i;

	min = NULL;
	i = -1;
	while (++i < inters->count)
	{
		if (inters->i[i].t < 0)
			continue ;
		if (min == NULL || inters->i[i].t < min->t)
			min = inters->i + i;
	}
	return (min);
}
//
// int32_t	free_intersections(t_intersections *inters)
// {
// 	free(inters->i);
// 	return (0);
// }
