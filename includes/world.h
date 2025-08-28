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
# include "ray.h"

typedef struct s_amb
{
	double		i;
	t_fcolor	col;
}	t_amb;

typedef struct s_world
{
	t_obj				*objs;
	t_light				*lights;
	t_intersections		xs;
	t_amb				amb;
	t_fcolor			back_col;
}	t_world;

void			sort_inter(t_intersections xs);
void			create_wintersec(t_world *w);
void			realloc_wintersec(t_world *w);
t_intersections	world_intersec(t_world *w, t_ray r);
int32_t			world(t_world *w);
void			add_world_obj(t_world *w, t_obj obj);
int32_t			default_world(t_world *w);
void			free_world(t_world *w);

#endif
