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
# include "matrix.h"
# include "normals.h"

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
	t_intersection	*i;
}	t_intersections;

t_ray			ray(t_tuple origin, t_tuple direction);
t_tuple			position(t_ray ray, float t);
void			intersect(t_ray r, t_obj *o, t_intersections *xs);
t_intersection	intersection(float t, t_obj *obj);
t_intersection	*hit(t_intersections *inters);
// int32_t			free_intersections(t_intersections *inters);

t_ray			ray_transform(t_ray r, t_mtx4 m);

#endif
