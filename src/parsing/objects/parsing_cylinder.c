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

int32_t	parse_cylinder(char **split, t_obj *obj)
{
	int32_t	res;

	res = 0;
	(void)split;
	(void)obj;
	// *obj = (t_obj){0};
	// obj->type = CYLINDER;
	// res = parse_xyz(split[0], &obj->pos);
	// if (res != SUCCESS)
	// 	return (res);
	// res = parse_normal(split[1], &obj->ori);
	// if (res != SUCCESS)
	// 	return (res);
	// res = parse_double(split[2], &obj->w);
	// if (res != SUCCESS)
	// 	return (res);
	// obj->w /= 2;
	// res = parse_double(split[3], &obj->h);
	// if (res != SUCCESS)
	// 	return (res);
	// res = parse_color(split[4], &obj->col);
	// if (res != SUCCESS)
	// 	return (res);
	// if (DEBUG)
	// 	debug_cylinder(*obj);
	return (res);
}
