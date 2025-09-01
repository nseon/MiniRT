/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:18 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/27 17:20:27 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "matrix.h"
# include "objects.h"
# include "tuple.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	dir;
}	t_ray;

typedef struct s_intersection
{
	double	t;
	t_obj	*obj;
}	t_intersection;

typedef struct s_intersections
{
	int32_t			count;
	t_intersection	*i;
}	t_intersections;

t_ray			ray(t_tuple origin, t_tuple direction);
t_ray			ray_for_pixel(t_camera cam, double x, double y);
t_tuple			position(t_ray ray, double t);
void			obj_intersect(t_ray r, t_obj *o, t_intersections *xs);
void			sphere_intersect(t_ray r, t_obj *o, t_intersections *xs);
void			plane_intersect(t_ray r, t_obj *o, t_intersections *xs);
void			cube_intersect(t_ray r, t_obj *o, t_intersections *xs);
t_intersection	intersection(double t, t_obj *obj);
t_intersection	*hit(t_intersections *inters);

t_ray			ray_transform(t_ray r, t_mtx4 m);

#endif
