/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:22:07 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/15 11:22:07 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "errors.h"
#include "neflibx.h"
#include "world.h"

void	free_world(t_world *w)
{
	free_vct(w->objs);
	free_vct(w->lights);
	free(w->xs.i);
}

int32_t	world(t_world *w)
{
	w->objs = vct_create(sizeof (t_obj), 0, DESTROY_ON_FAIL);
	if (!w->objs)
		return (FATAL);
	w->lights = vct_create(sizeof (t_light), 0, DESTROY_ON_FAIL);
	if (!w->lights)
	{
		free_vct(w->objs);
		return (FATAL);
	}
	create_wintersec(&w->xs, 0);
	return (SUCCESS);
}

// Add more than 2 intersection if not a quadratic object
void	add_world_obj(t_world *w, t_obj obj)
{
	vct_add(&w->objs, &obj);
	realloc_wintersec(&w->xs, w->xs.count + 2);
}

int32_t	default_world(t_world *w)
{
	int32_t	res;
	t_mtx4	buf;
	t_obj	s;

	res = world(w);
	if (!res)
		return (res);
	vct_add(&w->lights, &(t_light){POINT, point(-10, 10, -10),
		fcolor(1, 1, 1)});
	s = sphere();
	s.mat.col = fcolor(0.8, 1, 0.6);
	s.mat.diffuse = 0.7;
	s.mat.specular = 0.2;
	add_world_obj(w, s);
	s = sphere();
	set_transform(&s, scaling(0.5, 0.5, 0.5, buf));
	add_world_obj(w, s);
	return (res);
}
