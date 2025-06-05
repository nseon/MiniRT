/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:45:33 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/14 17:45:33 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "errors.h"
#include "minirt.h"
#include "neflibx.h"
#include "parsing.h"

void	filename_input_cb(char *str, void *p)
{
	t_ctx *const	ctx = p;

	if (ctx->filename)
		close(ctx->file);
	ctx->file = open(str, O_RDWR);
	if (ctx->file == -1)
	{
		ctx->filename = 0;
		ctx->error = errno;
		return ;
	}
	ctx->error = 0;
	ctx->filename = str;
}

void	draw_status(t_ctx *const ctx)
{
	const t_guielem *const	filename = get_by_label(&ctx->win, FILENAME);
	t_point			draw_pt;

	draw_pt = (t_point){filename->x, filename->y + 12 + filename->h};
	if (ctx->error != 0)
	{
		draw_pt.color = RED_TXT;
		draw_str(&ctx->img, strerror(ctx->error), draw_pt, 2);
	}
	// else if (ctx->filename)
	// {
	// 	draw_pt.color = GREEN_TXT;
	// 	draw_str(&ctx->img, LOADED, draw_pt, 2);
	// }
}

int8_t	parse(t_ctx *const ctx)
{
	draw_background(&ctx->img, BACK_COLOR);
	draw_status(ctx);
	if (ctx->filename)
	{
		if (parse_map(ctx) == SUCCESS)
			ctx->parsing = true;
	}
	get_next_line(-2);
	return (SUCCESS);
}
