/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:11:06 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/24 13:11:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "fcolors.h"
#include "parsing.h"
#include "debug.h"
#include "errors.h"
#include "rt_maths.h"
#include "tuple.h"

int32_t	parse_double(char *str, double *f)
{
	if (!str)
	{
		ft_fprintf(STDERR_FILENO, PARSE_MISSING_FLOAT);
		return (PARSE_MISSING_FIELD);
	}
	*f = ft_atof(str);
	return (SUCCESS);
}

int32_t	parse_color(char *str, t_fcolor *color)
{
	int32_t		r;
	int32_t		g;
	int32_t		b;
	char *const	buf = str;

	if (!str)
		return (ft_fprintf(2, PARSE_MISSING_COLOR));
	r = ft_atoi_ptr(&str, false);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_COLOR_MSG, buf));
	str++;
	g = ft_atoi_ptr(&str, false);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_COLOR_MSG, buf));
	str++;
	b = ft_atoi_ptr(&str, false);
	if ((0 > r || r > 255) || (0 > g || g > 255) || (0 > b || b > 255))
	{
		ft_fprintf(2, PARSE_INVAL_COLOR_MSG, buf);
		return (PARSE_INVAL_FORMAT);
	}
	color->r = r / 255;
	color->g = g / 255;
	color->b = b / 255;
	return (SUCCESS);
}

int32_t	parse_xyz(char *str, t_tuple *tp)
{
	char *const	buf = str;

	if (!str)
		return (ft_fprintf(STDERR_FILENO, PARSE_MISSING_XYZ));
	tp->x = ft_atof_ptr(&str);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_XYZ_MSG, buf));
	str++;
	tp->y = ft_atof_ptr(&str);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_XYZ_MSG, buf));
	str++;
	tp->z = ft_atof_ptr(&str);
	tp->w = 0;
	return (SUCCESS);
}

int32_t	parse_normal(char *str, t_tuple *vct)
{
	int32_t	res;

	res = parse_xyz(str, vct);
	if (res != SUCCESS)
		return (res);
	if (f_equal(tp_magnitude(*vct), 1.0f))
		return (SUCCESS);
	printf(PARSE_INVAL_VCT_MSG, str);
	*vct = tp_normalize(*vct);
	printf(PARSE_INVAL_VCT_MSG2, vct->x, vct->y, vct->z);
	return (SUCCESS);
}
