/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambi_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:09:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/22 14:09:00 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "debug.h"
#include "parsing.h"

void	debug_ambi_light(t_amb_light o)
{
	printf(BOLD "Ambient Light" RESET "\n{\n");
	printf("\tColor: " COLOR "\n", o.col.argb, o.col.r, o.col.g, o.col.b);
	printf("\tIntensity: %4.2f\n", o.i);
	printf("}\n\n");
}

int32_t	parse_ambi_light(char **split, t_amb_light *amb_light)
{
	int32_t	res;

	res = parse_float(split[0], &amb_light->i);
	if (res != SUCCESS)
		return (res);
	res = parse_color(split[1], &amb_light->col);
	if (res != SUCCESS)
		return (res);
	if (DEBUG)
		debug_ambi_light(*amb_light);
	return (res);
}
