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
	t_tuple	tp;
	t_obj	obj;

	obj = plane();
	res = parse_xyz(*(split++), &tp);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, translation(tp.x, tp.y, tp.z, tbu));
	res = parse_normal(*(split++), &tp);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, mtx4_dir_rota(tp, tbu));
	res = parse_color(*(split++), &obj.mat.col);
	if (res != SUCCESS)
		return (res);
	if (BONUS_STATE)
		res = parse_plane_bonus(split, &obj);
	add_world_obj(w, obj);
	return (res);
}
