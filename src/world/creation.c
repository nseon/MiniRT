/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:22:07 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/10 13:29:03 by nseon            ###   ########.fr       */
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
	w->back_col = fcolor(0, 0, 0);
	w->advanced = true;
	w->frac = 1;
	create_wintersec(w);
	return (SUCCESS);
}

// Add more than 2 intersection if not a quadratic object
void	add_world_obj(t_world *w, t_obj obj)
{
	vct_add(&w->objs, &obj);
	realloc_wintersec(w);
}

int32_t	default_world(t_world *w)
{
	int32_t	res;
	t_mtx4	buf;
	t_obj	s;

	res = world(w);
	if (res != SUCCESS)
		return (res);
	w->amb.i = 0.1;
	w->amb.col = fcolor(1, 1, 1);
	vct_add(&w->lights, &(t_light){POINT, point(-10, 10, -10),
		fcolor(1, 1, 1)});
	s = sphere();
	s.mat.col = fcolor(0.8, 1, 0.6);
	s.mat.diffuse = 0.7;
	s.mat.specular = 0.2;
	add_world_obj(w, s);
	s = sphere();
	mul_transform(&s, scaling(0.5, 0.5, 0.5, buf));
	add_world_obj(w, s);
	return (res);
}
