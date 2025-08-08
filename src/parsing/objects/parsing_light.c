/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:52:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/05 12:16:50 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "debug.h"
#include "parsing.h"

void	debug_light(t_light o)
{
	printf(BOLD "Light" RESET "\n{\n");
	printf("\tColor: " COLOR "\n", o.col.argb, o.col.r, o.col.g, o.col.b);
	printf("\tIntensity: %4.2f\n", o.i);
	printf("\tPosition: " POS "\n", o.pos.x, o.pos.y, o.pos.z);
	printf("}\n\n");
}

int32_t	parse_light(char **split, t_light *light)
{
	int32_t	res;

	res = parse_xyz(split[0], &light->pos);
	if (res != SUCCESS)
		return (res);
	res = parse_float(split[1], &light->i);
	if (res != SUCCESS)
		return (res);
	res = parse_color(split[2], &light->col);
	if (res != SUCCESS)
		return (res);
	light->type = POINT;
	if (DEBUG)
		debug_light(*light);
	return (res);
}
