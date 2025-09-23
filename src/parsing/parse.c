/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:45:33 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/10 12:49:06 by nseon            ###   ########.fr       */
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
#include "inputs.h"

void	open_file(char *str, t_ctx *ctx)
{
	ctx->file = open(str, O_RDWR);
	if (ctx->file == -1)
	{
		ctx->error = errno;
		return ;
	}
	ctx->error = 0;
}

void	draw_file_status(t_ctx *const ctx)
{
	const t_guielem *const	filename = get_by_id(&ctx->win, FILENAME_ID);
	t_point					draw_pt;

	draw_pt = (t_point){filename->x, filename->y + 12 + filename->h, RED_TXT};
	if (ctx->error != 0)
	{
		draw_pt.color = RED_TXT;
		draw_str(&ctx->img, strerror(ctx->error), draw_pt, 2);
	}
	else if (ctx->file > 0)
	{
		draw_pt.color = GREEN_TXT;
		draw_str(&ctx->img, LOADED, draw_pt, 2);
	}
}

void	parse(char *str, void *p)
{
	t_ctx *const	ctx = p;

	open_file(str, ctx);
	draw_file_status(ctx);
	if (ctx->error == 0)
	{
		if (parse_map(ctx) == SUCCESS)
		{
			get_by_id(&ctx->win, FILENAME_ID)->hide = true;
			clear_image(&ctx->img);
			ctx->parsing = true;
			ctx->render = true;
		}
	}
}
