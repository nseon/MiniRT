/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:06:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/28 13:06:00 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "debug.h"
#include "parsing.h"

static int32_t	parse_sphere_bonus(char **split, t_obj *o)
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

int32_t	parse_sphere(char **split, t_world *w)
{
	int32_t	res;
	double	buf;
	t_mtx4	tbuf;
	t_tuple	pos;
	t_obj	obj;

	obj = sphere();
	res = parse_xyz(*(split++), &pos);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, translation(pos.x, pos.y, pos.z, tbuf));
	res = parse_double(*(split++), &buf);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, scaling(buf / 2, buf / 2, buf / 2, tbuf));
	res = parse_color(*(split++), &obj.mat.col);
	if (res != SUCCESS)
		return (res);
	if (BONUS_STATE)
		res = parse_sphere_bonus(split, &obj);
	add_world_obj(w, obj);
	return (res);
}
