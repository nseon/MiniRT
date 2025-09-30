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

#ifndef WORLD_H
# define WORLD_H

# include "objects.h"
# include "ray.h"

typedef struct s_amb
{
	double		i;
	t_fcolor	col;
}	t_amb;

typedef enum e_gparam
{
	SPECULAR = 1U,
	DIFFUSE = 1U << 1U,
	AMBIENT = 1U << 2U,
	SHADOWS = 1U << 3U,
	REFLECT = 1U << 4U,
	TRANSPARENCY = 1U << 5U,
	INDIRECT = 1U << 6U,
	MOVING = 1U << 7U,
	SS = 1U << 8U,
	DENOISE = 1U << 9U,
	RENDER = 1U << 10U,
}	t_gparam;

typedef struct s_world
{
	t_camera			cam;
	t_obj				*objs;
	t_light				*lights;
	t_intersections		xs;
	t_amb				amb;
	t_fcolor			back_col;
	uint32_t				gparam;
}	t_world;

void			sort_inter(t_intersections xs);
void			create_wintersec(t_world *w);
void			realloc_wintersec(t_world *w);
t_intersections	world_intersec(t_world *w, t_ray r);
int32_t			world(t_world *w);
int32_t			add_world_obj(t_world *w, t_obj obj);
void			free_world(t_world *w);

#endif
