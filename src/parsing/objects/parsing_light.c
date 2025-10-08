/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:52:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/28 12:52:00 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "debug.h"
#include "parsing.h"

int32_t	parse_light(char **split, t_light *light)
{
	int32_t	res;
	double	i;

	if (!light)
		return (FATAL);
	res = parse_xyz(split[0], &light->pos);
	if (res != SUCCESS)
		return (res);
	res = parse_double(split[1], &i);
	if (res != SUCCESS)
		return (res);
	res = parse_color(split[2], &light->i);
	if (res != SUCCESS)
		return (res);
	light->i = col_scalar(light->i, i);
	light->type = POINT;
	return (res);
}
