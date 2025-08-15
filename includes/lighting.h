/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:36:31 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/13 14:36:31 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_LIGHTING_H
# define MINIRT_LIGHTING_H

# include "fcolors.h"
# include "tuple.h"
# include "objects.h"
# include "ray.h"
# include "world.h"

typedef struct s_pre_compute
{
	t_obj	*obj;
	float	t;
	t_tuple	pos;
	t_tuple	eyev;
	t_tuple	normalv;
	bool	inside;
}	t_pre_compute;

t_fcolor		phong(t_material m, t_light light, t_pre_compute *pc);
t_pre_compute	pre_compute(t_intersection *i, t_ray r);
t_fcolor		light_hit(t_world *w, t_pre_compute *pc);
t_fcolor		color_at(t_world *w, t_ray r);

#endif
