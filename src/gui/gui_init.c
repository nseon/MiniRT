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
#include "minirt.h"
#include "neflibx.h"
#include "parsing.h"
#include "rt_gui.h"

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

int32_t	render_gui(t_ctx *ctx)
{
	t_guielem *const	render_ctn = create_container(&ctx->win, 0);
	t_guielem			*el;
	const uint32_t		cuid = render_ctn->uid;

	render_ctn->id = RENDER_CTN_ID;
	render_ctn->vw = 30;
	render_ctn->vh = 80;
	render_ctn->vy = 50;
	render_ctn->z = 5;
	el = create_check(&ctx->win, cuid, xor_denoise, &ctx->gctx.w.gparam);
	el->label = "Denoise";
	el->checked = (ctx->gctx.w.gparam & DENOISE) > 0;
	el->vx = 20;
	el->vy = 10;
	el->w = 15;
	el->h = 15;
	el = create_check(&ctx->win, cuid, xor_ss, ctx);
	el->label = "Supersampling";
	el->checked = (ctx->gctx.w.gparam & SS) > 0;
	el->vx = 70;
	el->vy = 10;
	el->w = 15;
	el->h = 15;
	el = create_check(&ctx->win, cuid, xor_indirect, ctx);
	el->label = "Indir. Light";
	el->checked = (ctx->gctx.w.gparam & INDIRECT) > 0;
	el->vx = 20;
	el->vy = 20;
	el->w = 15;
	el->h = 15;
	el = create_check(&ctx->win, cuid, xor_render, ctx);
	el->label = "Render";
	el->checked = (ctx->gctx.w.gparam & INDIRECT) > 0;
	el->vx = 50;
	el->vy = 95;
	el->w = 15;
	el->h = 15;
	get_by_uid(&ctx->win, cuid)->hide = true;
	return (SUCCESS);
}

int8_t	init_gui(t_ctx *ctx)
{
	int8_t	res;

	res = parse_gui(ctx);
	res = render_gui(ctx);
	return (res);
}
