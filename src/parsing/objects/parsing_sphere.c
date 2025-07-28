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

void	debug_sphere(t_obj o)
{
	printf(BOLD "Sphere" RESET "\n{\n");
	printf("\tColor: " COLOR "\n", o.col.argb, o.col.r, o.col.g, o.col.b);
	printf("\tPosition: " POS "\n", o.pos.x, o.pos.y, o.pos.z);
	printf("\tRadius: %4.1f\n", o.w);
	printf("}\n\n");
}

int32_t	parse_sphere(char **split, t_obj *obj)
{
	int32_t	res;

	*obj = (t_obj){0};
	obj->type = SPHERE;
	res = parse_xyz(split[0], &obj->pos);
	if (res != SUCCESS)
		return (res);
	res = parse_float(split[1], &obj->w);
	if (res != SUCCESS)
		return (res);
	obj->w /= 2;
	res = parse_color(split[2], &obj->col);
	if (res != SUCCESS)
		return (res);
	if (DEBUG)
		debug_sphere(*obj);
	return (res);
}
