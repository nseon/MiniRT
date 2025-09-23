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
	SPECULAR = 1,
	DIFFUSE = 1 << 1,
	AMBIENT = 1 << 2,
	SHADOWS = 1 << 3,
	REFLECT = 1 << 4,
	TRANSPARENCY = 1 << 5,
	INDIRECT = 1 << 6,
	MOVING = 1 << 7,
	SS = 1 << 8,
}	t_gparam;

typedef struct s_world
{
	t_camera			cam;
	t_obj				*objs;
	t_light				*lights;
	t_intersections		xs;
	t_amb				amb;
	t_fcolor			back_col;
	int32_t				gparam;
}	t_world;

void			sort_inter(t_intersections xs);
void			create_wintersec(t_world *w);
void			realloc_wintersec(t_world *w);
t_intersections	world_intersec(t_world *w, t_ray r);
int32_t			world(t_world *w);
int32_t			add_world_obj(t_world *w, t_obj obj);
void			free_world(t_world *w);

#endif
