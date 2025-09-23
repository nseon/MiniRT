/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:06:06 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/28 13:06:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "debug.h"
#include "parsing.h"
#include "rt_maths.h"

static int32_t	parse_cylinder_bonus(char **split, t_obj *o)
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

static int32_t	parse_cylinder2(char **split, t_obj *obj)
{
	int32_t	res;
	double	db;

	res = parse_double(*(split++), &db);
	if (res != SUCCESS)
		return (res);
	obj->x_size = db;
	obj->z_size = db;
	res = parse_double(*(split++), &db);
	if (res != SUCCESS)
		return (res);
	obj->min = -db / 2;
	obj->max = db / 2;
	res = parse_color(*(split++), &obj->mat.col);
	if (res != SUCCESS)
		return (res);
	if (BONUS_STATE)
		res = parse_cylinder_bonus(split, obj);
	return (res);
}

int32_t	parse_cylinder(char **split, t_world *w)
{
	int32_t	res;
	t_tuple	tp;
	t_obj	obj;

	obj = cylinder();
	obj.closed = true;
	res = parse_xyz(*(split++), &obj.pos);
	if (res != SUCCESS)
		return (res);
	res = parse_normal(*(split++), &tp);
	if (res != SUCCESS)
		return (res);
	set_rota_from_dir(tp, &obj);
	parse_cylinder2(split, &obj);
	add_world_obj(w, obj);
	return (res);
}
