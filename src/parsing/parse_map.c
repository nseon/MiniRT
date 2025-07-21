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
	char *const *const	split = ft_split(ELEMENTS, WHITESPACES);
	int32_t				i;

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
	return (PARSE_INVAL_TYPE);
}

static int8_t	parse_line(t_ctx *const ctx, char **split)
{
	int8_t	res;

	if (split[0] == NULL)
		return (SUCCESS);
	res = is_element(split[0]);
	if (res == SUCCESS)
	{
		printf("Is an element: %s\n", split[0]);
	}
	return (SUCCESS);
}

int8_t	parse_map(t_ctx *const ctx)
{
	char			*line;
	char *const		*split;
	int8_t			res;

	while (gnl2(ctx->file, &line))
	{
		split = ft_split(line, WHITESPACES);
		free(line);
		if (!split)
			return (FATAL);
		res = parse_line(ctx, split);
		free_split(split);
		if (res != 0)
			return (res);
	}
	close(ctx->file);
	ctx->file = 0;
	return (SUCCESS);
}
