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

int32_t	parse_sphere(char **split, t_world *w)
{
	int32_t	res;
	double	buf;
	t_mtx4	tbuf;
	t_obj	obj;

	obj = sphere();
	res = parse_trans(split[0], &obj);
	if (res != SUCCESS)
		return (res);
	res = parse_double(split[1], &buf);
	if (res != SUCCESS)
		return (res);
	mul_transform(&obj, scaling(buf / 2, buf / 2, buf / 2, tbuf));
	res = parse_color(split[2], &obj.mat.col);
	if (res != SUCCESS)
		return (res);
	add_world_obj(w, obj);
	return (res);
}
