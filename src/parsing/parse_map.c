/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:37:23 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/02 15:37:23 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "neflibx.h"
#include "minirt.h"
#include "errors.h"
#include "parsing.h"

static int8_t	is_element(char const *const str)
{
	char **const	split = ft_split(P_ELEMENTS, WHITESPACES);
	int32_t			i;

	i = -1;
	while (split[++i])
	{
		if (ft_strcmp(str, split[i]) == 0)
		{
			free_split(split);
			return (SUCCESS);
		}
	}
	free_split(split);
	ft_fprintf(STDERR_FILENO, PARSE_INVAL_TYPE_MSG, str);
	return (PARSE_INVAL_TYPE);
}

static int8_t	dispatch_element(char **split, t_gctx * const gctx)
{
	int32_t	res;

	res = 0;
	if (ft_strcmp(split[0], P_AMBI_LIGHT) == 0)
		res = parse_ambi_light(split + 1, &gctx->w.ambient);
	else if (ft_strcmp(split[0], P_CAMERA) == 0)
		res = parse_camera(split + 1, &gctx->cam);
	if (ft_strcmp(split[0], P_PT_LIGHT) == 0)
		res = parse_light(split + 1, vct_add_dest(&gctx->w.lights));
	else if (ft_strcmp(split[0], P_SPHERE) == 0)
		res = parse_sphere(split + 1, &gctx->w);
	// else if (ft_strcmp(split[0], P_CYLINDER) == 0)
	// 	res = parse_cylinder(split + 1, vct_add_dest(&gctx->w.objs));
	// else if (ft_strcmp(split[0], P_PLANE) == 0)
	// 	res = parse_plane(split + 1, vct_add_dest(&gctx->w.objs));
	return (res);
}

static int8_t	parse_line(t_ctx *const ctx, char **split,
	int32_t line_n, char **elms)
{
	int8_t	res;

	(void)ctx;
	if (split[0] == NULL)
		return (SUCCESS);
	res = is_element(split[0]);
	if (res != 0)
		return (res);
	vct_add(elms, split[0]);
	res = dispatch_element(split, &ctx->gctx);
	if (res != 0)
		ft_fprintf(2, "\t" PARSE_LINE_SPEC, line_n);
	return (res);
}

int32_t	check_elms(char *elms)
{
	size_t			i;
	int32_t			count[3];

	i = -1;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (++i < vct_size(elms))
	{
		if (elms[i] == P_CAMERA[0])
			count[0]++;
		else if (elms[i] == P_AMBI_LIGHT[0])
			count[1]++;
		else if (elms[i] == P_PT_LIGHT[0])
			count[2]++;
	}
	free_vct(elms);
	if (BONUS_STATE && count[0] == 1 && count[1] == 1)
		return (SUCCESS);
	if (count[0] == 1 && count[1] == 1 && count[2] == 1)
		return (SUCCESS);
	ft_fprintf(2, PARSE_INVAL_MAND);
	return (PARSE_INVAL_MAP);
}

int32_t	parse_map(t_ctx *const ctx)
{
	char	*line;
	char	**split;
	char	*elms;
	int32_t	res;
	int32_t	line_n;

	line_n = 0;
	elms = vct_create(sizeof (char), 0, 0);
	res = SUCCESS;
	while (gnl2(ctx->file, &line) && ++line_n)
	{
		split = ft_split(line, WHITESPACES);
		free(line);
		if (!split)
			return (free_vct(elms), FATAL);
		if (parse_line(ctx, split, line_n, &elms) != SUCCESS && res == SUCCESS)
			res = PARSE_INVAL_MAP;
		free_split(split);
	}
	close(ctx->file);
	ctx->file = 0;
	get_next_line(-2);
	res += check_elms(elms);
	return (res);
}
