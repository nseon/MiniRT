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

#include "errors.h"
#include "lighting.h"
#include "maps.h"
#include "parsing.h"
#include "render.h"

#ifdef BONUS

int32_t	parse_maps(char **split, t_material *m)
{
	if (!split[0])
		return (SUCCESS);
	if (parse_png_map(*(split++), &m->tmap.data, &m->tmap.infos) != SUCCESS)
		return (PARSE_INVAL_LINE);
	m->has_tmap = true;
	if (!split[0])
		return (SUCCESS);
	if (parse_png_map(*(split++), &m->nmap.data, &m->nmap.infos) != SUCCESS)
		return (PARSE_INVAL_LINE);
	m->has_nmap = true;
	if (!split[0])
		return (SUCCESS);
	if (parse_png_map(*(split++), &m->aomap.data, &m->aomap.infos) != SUCCESS)
		return (PARSE_INVAL_LINE);
	m->has_aomap = true;
	return (SUCCESS);
}

#else

int32_t	parse_maps(char **split, t_material *m)
{
	ft_fprintf(2, "Invalid pattern: %s\n", *split);
	(void)m;
	return (PARSE_INVAL_LINE);
}

#endif

int32_t	parse_pattern(char **split, t_obj *o)
{
	double	dbuf;
	t_tuple	tbuf;
	t_mtx4	buf;
	int32_t	res;

	if (!split[0])
		return (SUCCESS);
	if (parse_xyz(*(split++), &tbuf))
		return (PARSE_INVAL_LINE);
	set_uv_transf(&o->mat, translation(tbuf.x, tbuf.y, tbuf.z, buf));
	if (parse_double(*(split++), &dbuf))
		return (PARSE_INVAL_LINE);
	mul_uv_transf(&o->mat, scaling(dbuf, dbuf, dbuf, buf));
	res = parse_ptype(*split, &o->mat.pat.type);
	if (res == PARSE_MISSING_FIELD)
		return (ft_fprintf(2, "Missing maps field\n"));
	if (res == PARSE_INVAL_FORMAT)
		return (parse_maps(split, &o->mat));
	split++;
	o->mat.has_pat = true;
	if (parse_color(*(split++), &o->mat.pat.a) != SUCCESS)
		return (PARSE_INVAL_LINE);
	if (parse_color(*(split++), &o->mat.pat.b) != SUCCESS)
		return (PARSE_INVAL_LINE);
	return (SUCCESS);
}

static int32_t	parse_bonus(char **split, t_obj *o)
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
		if (parse_bonus(split, &obj) != SUCCESS)
			return (PARSE_INVAL_LINE);
	res = add_world_obj(w, obj);
	return (res);
}
