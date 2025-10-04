/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:35:53 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 19:35:53 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "matrix.h"
#include "objects.h"

uint32_t	get_uid(void)
{
	static uint32_t	uid;

	return (uid++);
}

void	set_rota_from_dir(t_tuple dir, t_obj *o)
{
	o->y_rot = atan2(dir.z, dir.x);
	o->z_rot = -asin(dir.y);
}

void	free_obj(void *p)
{
	t_obj *const	o = p;

	if (o->mat.has_nmap)
		free(o->mat.nmap.data);
}

t_light	light(t_tuple pos, t_fcolor intensity, t_light_type type)
{
	return ((t_light){.type = type, .pos = pos, .i = intensity});
}
