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

void	debug_plane(t_obj o)
{
	printf(BOLD "Plane" RESET "\n{\n");
	printf("\tColor: " COLOR "\n", o.col.argb, o.col.r, o.col.g, o.col.b);
	printf("\tPosition: " POS "\n", o.pos.x, o.pos.y, o.pos.z);
	printf("\tOrientation: " POS "\n", o.ori.x, o.ori.y, o.ori.z);
	printf("}\n\n");
}

int32_t	parse_plane(char **split, t_obj *obj)
{
	int32_t	res;

	*obj = (t_obj){0};
	obj->type = PLANE;
	res = parse_xyz(split[0], &obj->pos);
	if (res != SUCCESS)
		return (res);
	res = parse_normal(split[1], &obj->ori);
	if (res != SUCCESS)
		return (res);
	res = parse_color(split[2], &obj->col);
	if (res != SUCCESS)
		return (res);
	if (DEBUG)
		debug_plane(*obj);
	return (res);
}
