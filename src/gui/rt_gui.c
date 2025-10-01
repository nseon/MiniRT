/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_gui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:32:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/01 13:32:14 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_gui.h"

#include "minirt.h"
#include "neflibx.h"

void	switch_gui_param(t_ctx *ctx, char *id, bool val)
{
	t_guielem *const	el = get_by_id(&ctx->win, id);

	if (!el)
		return ;
	el->focus = true;
	el->checked = val ^ true;
	elem_check_release(el);
}

void	gui_loop(t_ctx *ctx)
{
	if (ctx->gctx.w.gparam & MOVING)
		vct_strcpy(&get_by_id(&ctx->win, "state_box")->txt, "MOVING");
	else if (ctx->gctx.w.gparam & EDIT)
		vct_strcpy(&get_by_id(&ctx->win, "state_box")->txt, "EDITING");
	else
		vct_empty_str(get_by_id(&ctx->win, "state_box")->txt);
}

void	show_edit(t_ctx *ctx, t_obj *o)
{
	t_guielem	*slide;

	get_by_id(&ctx->win, EDIT_CTN_ID)->hide = false;
	slide = get_by_id(&ctx->win, "red_slide");
	slide->cb.cb_param = &o->mat.col.r;
	slide->value = o->mat.col.r;
	slide = get_by_id(&ctx->win, "green_slide");
	slide->cb.cb_param = &o->mat.col.g;
	slide->value = o->mat.col.g;
	slide = get_by_id(&ctx->win, "blue_slide");
	slide->cb.cb_param = &o->mat.col.b;
	slide->value = o->mat.col.b;
}