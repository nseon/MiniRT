/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:18 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 16:24:18 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_H
# define MINIRT_RAY_H

# include "tuple.h"
# include "objects.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	dir;
}	t_ray;

typedef struct s_intersection
{
	float	t;
	t_obj	*obj;
}	t_intersection;

typedef struct s_intersections
{
	int32_t			count;
	t_intersection	i[2];
}	t_intersections;

t_ray		ray(t_tuple origin, t_tuple direction);
t_tuple		position(t_ray ray, float t);
t_intersections	intersect(t_ray r, t_obj *o);

#endif
