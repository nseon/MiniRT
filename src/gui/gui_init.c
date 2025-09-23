/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:32:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/02 13:32:28 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "neflibx.h"
#include "minirt.h"
#include "parsing.h"

static int8_t	parse_gui(t_ctx *ctx)
{
	t_guielem *const	parse_ctn = create_container(&ctx->win, 0);
	t_guielem			*el;

	parse_ctn->id = PARSE_CTN_ID;
	parse_ctn->w = ctx->win.w;
	parse_ctn->h = ctx->win.h;
	el = create_txt_input(&ctx->win, get_by_id(&ctx->win,
		"parse_ctn")->uid, parse, ctx);
	el->vw = 30;
	el->vh = 6;
	el->z += 1;
	el->vx = 50;
	el->vy = 50;
	el->label = FILENAME;
	el->id = FILENAME_ID;
	el = create_text_box(&ctx->win, get_by_id(&ctx->win, "parse_ctn")->uid);
	el->size = 1;
	el->vw = 60;
	el->h = WIN_H / 2 - 50;
	el->vx = 68;
	el->y = WIN_H / 2 + 50;
	el->id = PARSE_TXT_ID;
	return (SUCCESS);
}

int8_t	init_gui(t_ctx *ctx)
{
	int8_t	res;

	res = parse_gui(ctx);
	return (res);
}
