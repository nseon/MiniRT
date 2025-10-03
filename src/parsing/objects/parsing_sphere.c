/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:06:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/03 10:44:41 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "debug.h"
#include "parsing.h"
#include "normal_maps.h"

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
	double	dbuf;
	t_obj	obj;

	obj = sphere();
	res = create_normal_map("animal_skin.png", &obj.map);
	res = parse_xyz(*(split++), &obj.pos);
	if (res != SUCCESS)
		return (res);
	res = parse_double(*(split++), &dbuf);
	if (res != SUCCESS)
		return (res);
	obj.x_size = dbuf / 2;
	obj.y_size = dbuf / 2;
	obj.z_size = dbuf / 2;
	res = parse_color(*(split++), &obj.mat.col);
	if (res != SUCCESS)
		return (res);
	if (BONUS_STATE)
		res = parse_sphere_bonus(split, &obj);
	res = add_world_obj(w, obj);
	return (res);
}
