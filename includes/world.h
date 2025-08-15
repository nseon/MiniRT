/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:04:48 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/15 11:04:48 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_WORLD_H
# define MINIRT_WORLD_H

# include "objects.h"
#include "ray.h"

typedef struct s_world
{
	t_obj				*objs;
	t_light				*lights;
	t_intersections	xs;
	bool				lights_off;
}	t_world;

#endif
