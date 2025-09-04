/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:04:47 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/28 13:04:47 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "debug.h"
#include "parsing.h"

static int32_t	parse_plane_bonus(char **split, t_obj *o)
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

int32_t	parse_plane(char **split, t_world *w)
{
	int32_t	res;
	t_mtx4	tbu;
	t_tuple	pos;
	t_tuple	to;
	t_obj	obj;

	obj = plane();
	res = parse_xyz(*(split++), &pos);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, translation(pos.x, pos.y, pos.z, tbu));
	res = parse_normal(*(split++), &to);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, mtx4_view(pos, tp_add(pos, point(0, 0, 1)), to, tbu));
	res = parse_color(*(split++), &obj.mat.col);
	if (res != SUCCESS)
		return (res);
	if (BONUS_STATE)
		res = parse_plane_bonus(split, &obj);
	add_world_obj(w, obj);
	return (res);
}
