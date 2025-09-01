/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:39:25 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/01 09:39:25 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "rt_maths.h"

void	plane_intersect(t_ray r, t_obj *o, t_intersections *xs)
{
	if (dabs(r.dir.y) < EPSILON)
		return ;
	xs->i[xs->count] = intersection(-r.origin.y / r.dir.y, o);
	xs->count++;
}
