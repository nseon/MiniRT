/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:35:53 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/08 13:34:08 by nseon            ###   ########.fr       */
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

t_fcolor	obj_color(t_obj *o, t_uv uv)
{
	if (o->mat.has_pat)
		return (pattern_at_obj(o->mat.pat, uv));
	if (o->mat.has_tmap)
		return (map_to_fcol(&o->mat.tmap, uv));
	return (o->mat.col);
}

t_light	light(t_tuple pos, t_fcolor intensity, t_light_type type)
{
	return ((t_light){.type = type, .pos = pos, .i = intensity});
}
