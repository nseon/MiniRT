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

int32_t	parse_cylinder(char **split, t_world *w)
{
	int32_t	res;
	t_mtx4	tbu;
	t_tuple	tp;
	double	db;
	t_obj	obj;

	obj = cylinder();
	obj.closed = true;
	res = parse_xyz(*(split++), &tp);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, translation(tp.x, tp.y, tp.z, tbu));
	res = parse_normal(*(split++), &tp);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, mtx4_dir_rota(tp, tbu));
	res = parse_double(*(split++), &db);
	if (res != SUCCESS)
		return (res);
	obj.min = -db / 2;
	obj.max = db / 2;
	res = parse_double(*(split++), &db);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, scaling(db, 1, db, tbu));
	res = parse_color(*(split++), &obj.mat.col);
	if (res != SUCCESS)
		return (res);
	// if (BONUS_STATE)
	// 	res = parse_plane_bonus(split, &obj);
	add_world_obj(w, obj);
	return (res);
}
