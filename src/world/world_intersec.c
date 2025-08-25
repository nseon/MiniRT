/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_intersec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:02:04 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/15 12:02:04 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ray.h"
#include "world.h"
#include "neflibx.h"

void	create_wintersec(t_world *w)
{
	w->xs.i = malloc(sizeof (t_intersection) * vct_size(w->objs) * 2 * 2);
	w->xs.count = 0;
}

void	realloc_wintersec(t_world *w)
{
	free(w->xs.i);
	create_wintersec(w);
}

t_intersections	world_intersec(t_world *w, t_ray r)
{
	t_intersections	inter;
	size_t			i;

	inter.count = 0;
	inter.i = w->xs.i + w->xs.count;
	i = -1;
	while (++i < vct_size(w->objs))
	{
		obj_intersect(r, w->objs + i, &inter);
	}
	sort_inter(inter);
	w->xs.count += inter.count;
	return (inter);
}
