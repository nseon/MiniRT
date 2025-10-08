/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:32:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/07 10:27:49 by nseon            ###   ########.fr       */
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

int32_t	render_gui_elems(t_ctx *ctx, uint32_t cuid)
{
	t_guielem	*el;

	el = create_check(&ctx->win, cuid, xor_indirect, ctx);
	el->label = "Indir. Light";
	el->id = "indir_light_btn";
	el->checked = (ctx->gctx.w.gparam & INDIRECT) > 0;
	el->vx = 20;
	el->vy = 20;
	el->w = 15;
	el->h = 15;
	el = create_check(&ctx->win, cuid, xor_render, ctx);
	el->label = "Render";
	el->id = "render_btn";
	el->checked = (ctx->gctx.w.gparam & RENDER) > 0;
	el->vx = 50;
	el->vy = 95;
	el->w = 15;
	el->h = 15;
	el = create_text_box(&ctx->win, 0);
	el->id = "state_box";
	el->vx = 65;
	el->vy = 10;
	el->vw = 40;
	el->vh = 10;
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
	render_ctn->hide = true;
	el = create_check(&ctx->win, cuid, xor_denoise, &ctx->gctx.w.gparam);
	el->label = "Denoise";
	el->checked = (ctx->gctx.w.gparam & DENOISE) > 0;
	el->vx = 20;
	el->vy = 10;
	el->w = 15;
	el->h = 15;
	el = create_check(&ctx->win, cuid, xor_ss, ctx);
	el->label = "Supersampling";
	el->id = "ss_btn";
	el->checked = (ctx->gctx.w.gparam & SS) > 0;
	el->vx = 70;
	el->vy = 10;
	el->w = 15;
	el->h = 15;
	return (render_gui_elems(ctx, cuid));
}

int8_t	init_gui(t_ctx *ctx)
{
	int8_t	res;

	if (vct_allocate(&ctx->win.gui_elems, 32) != SUCCESS)
		return (FATAL);
	res = parse_gui(ctx);
	res = render_gui(ctx);
	res = edit_gui(ctx);
	return (res);
}
