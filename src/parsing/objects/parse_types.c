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

#include "parsing.h"
#include "debug.h"
#include "errors.h"
#include "rt_maths.h"

int32_t	parse_float(char *str, float *f)
{
	if (!str)
	{
		ft_fprintf(STDERR_FILENO, PARSE_MISSING_FLOAT);
		return (PARSE_MISSING_FIELD);
	}
	*f = ft_atof(str);
	return (SUCCESS);
}

int32_t	parse_color(char *str, t_color *color)
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
	color->argb = r << 16 | g << 8 | b;
	return (SUCCESS);
}

int32_t	parse_xyz(char *str, t_point3 *pt)
{
	char *const	buf = str;

	if (!str)
		return (ft_fprintf(STDERR_FILENO, PARSE_MISSING_XYZ));
	pt->x = ft_atof_ptr(&str);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_XYZ_MSG, buf));
	str++;
	pt->y = ft_atof_ptr(&str);
	if (*str != ',')
		return (ft_fprintf(2, PARSE_INVAL_XYZ_MSG, buf));
	str++;
	pt->z = ft_atof_ptr(&str);
	return (SUCCESS);
}

int32_t	parse_normal(char *str, t_vec3 *vct)
{
	int32_t	res;

	res = parse_xyz(str, vct);
	if (res != SUCCESS)
		return (res);
	if (f_equal(v3_magnitude(*vct), 1.0f))
		return (SUCCESS);
	printf(PARSE_INVAL_VCT_MSG, str);
	*vct = v3_normalize(*vct);
	printf(PARSE_INVAL_VCT_MSG2, vct->x, vct->y, vct->z);
	return (SUCCESS);
}
