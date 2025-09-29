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
	t_guielem *const	txt_box = get_by_id(&ctx->win, PARSE_TXT_ID);

	if (ctx->error != 0)
	{
		txt_box->txt_color = RED_TXT;
		if (ctx->error != PARSE_INVAL_MAP)
			vct_strcpy(&txt_box->txt, strerror(ctx->error));
		else
			vct_strcpy(&txt_box->txt, INVAL_MAP_MSG);
	}
	else if (ctx->file > 0)
	{
		// draw_pt.color = GREEN_TXT;
		// draw_str(&ctx->img, LOADED, draw_pt, 2);
	}
}

void	parse(char *str, void *p)
{
	t_ctx *const	ctx = p;

	open_file(str, ctx);
	if (ctx->error == 0)
	{
		if (parse_map(ctx) == SUCCESS)
		{
			get_by_id(&ctx->win, PARSE_CTN_ID)->hide = true;
			set_events(ctx);
			ctx->parsing = true;
			ctx->render = true;
		}
		else
		{
			ctx->error = PARSE_INVAL_MAP;
		}
	}
}
