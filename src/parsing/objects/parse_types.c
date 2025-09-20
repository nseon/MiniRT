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
	float		r;
	float		g;
	float		b;
	char *const	buf = str;

	if (!str)
		return (ft_fprintf(2, PARSE_MISSING_COLOR));
	r = ft_atof_ptr(&str);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_COLOR_MSG, buf));
	str++;
	g = ft_atof_ptr(&str);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_COLOR_MSG, buf));
	str++;
	b = ft_atof_ptr(&str);
	if ((0 > r || r > 255) || (0 > g || g > 255) || (0 > b || b > 255))
	{
		ft_fprintf(2, PARSE_INVAL_COLOR_MSG, buf);
		return (PARSE_INVAL_FORMAT);
	}
	color->r = (float)r / 255;
	color->g = (float)g / 255;
	color->b = (float)b / 255;
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
	tp->w = 1;
	return (SUCCESS);
}

int32_t	parse_trans(char *str, t_obj *o)
{
	char *const	buf = str;
	t_mtx4		tbuf;
	t_tuple		tp;

	if (!str)
		return (ft_fprintf(STDERR_FILENO, PARSE_MISSING_XYZ));
	tp.x = ft_atof_ptr(&str);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_XYZ_MSG, buf));
	str++;
	tp.y = ft_atof_ptr(&str);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_XYZ_MSG, buf));
	str++;
	tp.z = ft_atof_ptr(&str);
	mul_transform(o, translation(tp.x, tp.y, tp.z, tbuf));
	return (SUCCESS);
}

int32_t	parse_normal(char *str, t_tuple *vct)
{
	int32_t	res;

	res = parse_xyz(str, vct);
	vct->w = 0;
	if (res != SUCCESS)
		return (res);
	if (f_equal(tp_magnitude(*vct), 1.0f))
		return (SUCCESS);
	if (f_equal(vct->x, 0) && f_equal(vct->y, 0) && f_equal(vct->z, 0))
		return (ft_fprintf(2, PARSE_INVAL_UNIT, str));
	printf(PARSE_INVAL_VCT_MSG, str);
	*vct = tp_normalize(*vct);
	printf(PARSE_INVAL_VCT_MSG2, vct->x, vct->y, vct->z);
	return (SUCCESS);
}
