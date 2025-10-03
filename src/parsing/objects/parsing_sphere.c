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
#include "lighting.h"
#include "parsing.h"
#include "normal_maps.h"

int32_t	parse_maps(char **split, t_obj *o)
{
	if (!split[0])
		return (SUCCESS);
	if (create_normal_map(*(split++), &o->mat.nmap) != SUCCESS)
	{
		ft_fprintf(2, "Invalid normal map: %s\n", split[-1]);
		return (PARSE_INVAL_LINE);
	}
	o->mat.has_nmap = true;
	return (SUCCESS);
}

int32_t	parse_pattern(char **split, t_obj *o)
{
	t_tuple	buf;
	t_mtx4	tbuf;

	if (!split[0])
		return (PARSE_MISSING_FIELD);
	if (parse_ptype(*(split++), &o->mat.pat.type) != SUCCESS)
		return (parse_maps(split, o));
	o->mat.has_pat = true;
	if (parse_color(*(split++), &o->mat.pat.a) != SUCCESS)
		return (PARSE_INVAL_LINE);
	if (parse_color(*(split++), &o->mat.pat.b) != SUCCESS)
		return (PARSE_INVAL_LINE);
	if (!split[0])
		return (SUCCESS);
	if (parse_xyz(*(split++), &buf))
		return (PARSE_INVAL_LINE);
	set_pattern_transf(&o->mat.pat, translation(buf.x, buf.y, buf.z, tbuf));
	if (parse_xyz(*(split++), &buf))
		return (PARSE_INVAL_LINE);
	mul_pattern_transf(&o->mat.pat, scaling(buf.x, buf.y, buf.z, tbuf));
	return (parse_maps(split, o));
}

static int32_t	parse_sphere_bonus(char **split, t_obj *o)
{
	int32_t	res;
	double	buf;

	res = 0;
	buf = 0;
	if (split[0])
		res = parse_double(*(split++), &buf);
	if (res != SUCCESS)
		return (res);
	o->mat.reflective = buf;
	if (split[0])
		res = parse_double(*(split++), &buf);
	if (res != SUCCESS)
		return (res);
	o->mat.transparency = buf;
	if (split[0])
		res = parse_double(*(split++), &buf);
	else
		buf = AIR_REFRACTIVE;
	if (res != SUCCESS)
		return (res);
	o->mat.refractive = buf;
	return (parse_pattern(split, o));
}

int32_t	parse_sphere(char **split, t_world *w)
{
	int32_t	res;
	double	dbuf;
	t_obj	obj;

	obj = sphere();
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
		if (parse_sphere_bonus(split, &obj) != SUCCESS)
			return (PARSE_INVAL_LINE);
	res = add_world_obj(w, obj);
	return (res);
}
