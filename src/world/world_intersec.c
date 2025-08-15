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
	w->xs.i = malloc(sizeof (t_intersection) * vct_size(w->objs) * 2);
	w->xs.count = 0;
}

void	realloc_wintersec(t_world *w)
{
	free(w->xs.i);
	create_wintersec(w);
}
