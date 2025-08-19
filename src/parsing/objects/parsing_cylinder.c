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

void	debug_cylinder(t_obj o)
{
	printf(BOLD "Cylinder" RESET "\n{\n");
	printf("\tColor: " COLOR "\n", o.col.r * 255 + o.col.g * 255
		+ o.col.b * 255, o.col.r * 255, o.col.g * 255, o.col.b * 255);
	printf("\tPosition: " POS "\n", o.pos.x, o.pos.y, o.pos.z);
	printf("\tOrientation: " POS "\n", o.ori.x, o.ori.y, o.ori.z);
	printf("\tRadius: %4.1f\n", o.w);
	printf("\tHeight: %4.1f\n", o.h);
	printf("}\n\n");
}

int32_t	parse_cylinder(char **split, t_obj *obj)
{
	int32_t	res;

	*obj = (t_obj){0};
	obj->type = CYLINDER;
	res = parse_xyz(split[0], &obj->pos);
	if (res != SUCCESS)
		return (res);
	res = parse_normal(split[1], &obj->ori);
	if (res != SUCCESS)
		return (res);
	res = parse_double(split[2], &obj->w);
	if (res != SUCCESS)
		return (res);
	obj->w /= 2;
	res = parse_double(split[3], &obj->h);
	if (res != SUCCESS)
		return (res);
	res = parse_color(split[4], &obj->col);
	if (res != SUCCESS)
		return (res);
	if (DEBUG)
		debug_cylinder(*obj);
	return (res);
}
