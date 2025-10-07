/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:36:31 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/06 14:33:25 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# define AIR_REFRACTIVE 1.00029
# define MAX_RECUR 5
# define REFRACT_XS_OFFSET 1

# include "fcolors.h"
# include "objects.h"
# include "ray.h"
# include "render.h"
# include "tuple.h"
# include "world.h"

typedef struct s_pre_compute
{
	t_obj	*obj;
	double	t;
	t_tuple	pos;
	t_tuple	eyev;
	t_tuple	normalv;
	bool	inside;
	t_tuple	over_point;
	t_tuple	under_point;
	t_tuple	reflectv;
	t_uv	uv;
	double	n1;
	double	n2;
}	t_pre_compute;

t_fcolor		phong(t_material m, t_light light, t_pre_compute *pc,
					uint32_t gparam);
t_pre_compute	pre_compute(t_intersection *i, t_ray r, t_intersections *xs);
t_fcolor		light_hit(t_world *w, t_pre_compute *pc, int n);
t_fcolor		color_at(t_world *w, t_ray r, int n);
t_fcolor		reflect_color(t_world *w, t_pre_compute *pc, int n);
t_fcolor		refract_color(t_world *w, t_pre_compute *pc, int n);
bool			is_in_shadow(t_world *w, t_tuple p, t_light *l);
double			schlick(t_pre_compute *pc);

#endif
