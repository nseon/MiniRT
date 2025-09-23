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
	w->gparam = SPECULAR | DIFFUSE | AMBIENT | SHADOWS | REFLECT | TRANSPARENCY
		| INDIRECT | SS;
	create_wintersec(w);
	return (SUCCESS);
}

int32_t	add_world_obj(t_world *w, t_obj obj)
{
	vct_add(&w->objs, &obj);
	realloc_wintersec(w);
	if (!w->xs.i)
		return (FATAL);
	return (SUCCESS);
}
