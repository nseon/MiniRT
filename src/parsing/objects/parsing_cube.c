/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:45:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/04 17:45:03 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "debug.h"
#include "parsing.h"

static int32_t	parse_cube_bonus(char **split, t_obj *o)
{
	int32_t	res;
	double	buf;

	res = parse_double(*(split++), &buf);
	if (res != SUCCESS)
		return (res);
	o->mat.reflective = buf;
	res = parse_double(*(split++), &buf);
	if (res != SUCCESS)
		return (res);
	o->mat.transparency = buf;
	res = parse_double(*(split++), &buf);
	if (res != SUCCESS)
		return (res);
	o->mat.refractive = buf;
	return (res);
}

int32_t	parse_cube(char **split, t_world *w)
{
	int32_t	res;
	t_tuple	tp;
	t_obj	obj;

	obj = cube();
	res = parse_xyz(*(split++), &obj.pos);
	if (res != SUCCESS)
		return (res);
	res = parse_normal(*(split++), &tp);
	if (res != SUCCESS)
		return (res);
	set_rota_from_dir(tp, &obj);
	res = parse_xyz(*(split++), &tp);
	if (res != SUCCESS)
		return (res);
	obj.x_size = tp.x;
	obj.y_size = tp.y;
	obj.z_size = tp.z;
	res = parse_color(*(split++), &obj.mat.col);
	if (res != SUCCESS)
		return (res);
	if (BONUS_STATE)
		res = parse_cube_bonus(split, &obj);
	add_world_obj(w, obj);
	return (res);
}
