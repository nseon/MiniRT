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
#include "maps.h"

int32_t	parse_maps(char **split, t_material *m)
{
	t_mtx4	tbuf;
	t_tuple	buf;
	double	dbuf;

	if (!split[0])
		return (SUCCESS);
	if (parse_xyz(*(split++), &buf))
		return (PARSE_INVAL_LINE);
	set_uv_transf(m, translation(buf.x, buf.y, buf.z, tbuf));
	if (parse_double(*(split++), &dbuf))
		return (PARSE_INVAL_LINE);
	mul_uv_transf(m, scaling(dbuf, dbuf, dbuf, tbuf));
	if (parse_png_map(*(split++), &m->nmap.data, &m->nmap.infos) != SUCCESS)
	{
		ft_fprintf(2, "Invalid normal map: %s\n", split[-1]);
		return (PARSE_INVAL_LINE);
	}
	m->has_nmap = true;
	if (parse_png_map(*(split++), &m->tmap.data, &m->tmap.infos) != SUCCESS)
	{
		ft_fprintf(2, "Invalid normal map: %s\n", split[-1]);
		return (PARSE_INVAL_LINE);
	}
	m->has_tmap = true;
	if (parse_png_map(*(split++), &m->aomap.data, &m->aomap.infos) != SUCCESS)
	{
		ft_fprintf(2, "Invalid normal map: %s\n", split[-1]);
		return (PARSE_INVAL_LINE);
	}
	m->has_aomap = true;
	return (SUCCESS);
}

int32_t	parse_pattern(char **split, t_obj *o)
{
	t_tuple	buf;
	t_mtx4	tbuf;

	// if (!split[0])
	// 	return (PARSE_MISSING_FIELD);
	// if (parse_ptype(*(split++), &o->mat.pat.type) != SUCCESS)
	// 	return (parse_maps(split, o));
	// o->mat.has_pat = true;
	// if (parse_color(*(split++), &o->mat.pat.a) != SUCCESS)
	// 	return (PARSE_INVAL_LINE);
	// if (parse_color(*(split++), &o->mat.pat.b) != SUCCESS)
	// 	return (PARSE_INVAL_LINE);
	// if (!split[0])
	// 	return (SUCCESS);
	return (parse_maps(split, &o->mat));
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
