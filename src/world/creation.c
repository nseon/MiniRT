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

#include "errors.h"
#include "neflibx.h"
#include "world.h"

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
	return (SUCCESS);
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
	vct_add(&w->objs, &s);
	s = sphere();
	set_transform(&s, scaling(0.5, 0.5, 0.5, buf));
	vct_add(&w->objs, &s);
	return (res);
}
