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

int32_t	parse_ambi_light(char **split, t_amb *amb)
{
	int32_t	res;

	res = parse_double(split[0], &amb->i);
	if (res != SUCCESS)
		return (res);
	res = parse_color(split[1], &amb->col);
	if (res != SUCCESS)
		return (res);
	return (res);
}
