/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_backlight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:44:38 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/04 17:44:38 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "errors.h"
#include "render.h"
#include "parsing.h"

int32_t	parse_backlight(char **split, t_fcolor *bl)
{
	int32_t	res;

	res = parse_color(*(split++), bl);
	if (res != SUCCESS)
		return (res);
	return (res);
}
