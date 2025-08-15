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

void	create_wintersec(t_intersections *xs, int32_t count)
{
	xs->i = malloc(sizeof (t_intersection) * count);
	xs->count = count;
}

void	realloc_wintersec(t_intersections *xs, int32_t count)
{
	free(xs->i);
	create_wintersec(xs, count);
}
