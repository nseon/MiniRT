/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:09:36 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/01 13:09:36 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "render.h"
#include "rt_gui.h"

void	set_edit(t_ctx *ctx, bool b)
{
	if (b)
		ctx->gctx.w.gparam |= EDIT;
	else
		ctx->gctx.w.gparam &= ~EDIT;
	switch_gui_param(ctx, "ss_btn", b ^ true);
	switch_gui_param(ctx, "indir_light_btn", b ^ true);
}

void	set_selected_col(t_obj *o, bool b)
{
	if (!b)
	{
		if (!o->mat.has_pat)
		{
			o->mat.col = o->mat.o_col;
			return ;
		}
		o->mat.pat.a = o->mat.pat.o_a;
		o->mat.pat.b = o->mat.pat.o_b;
		return ;
	}
	if (!o->mat.has_pat)
	{
		o->mat.o_col = o->mat.col;
		o->mat.col = col_scalar(o->mat.col, 1.3);
		return ;
	}
	o->mat.pat.o_a = o->mat.pat.a;
	o->mat.pat.a = col_scalar(o->mat.pat.a, 1.3);
	o->mat.pat.o_b = o->mat.pat.b;
	o->mat.pat.b = col_scalar(o->mat.pat.b, 1.3);
}

void	set_selected_obj(t_world *w, t_obj *o)
{
	if (!o)
	{
		if (!w->selec_o)
			return ;
		set_selected_col(w->selec_o, false);
		w->selec_o = NULL;
	}
	if (w->selec_o == o)
		return ;
	if (w->selec_o)
		set_selected_col(w->selec_o, false);
	set_selected_col(o, true);
	w->selec_o = o;
}

bool	check_click_gui(t_ctx *ctx, int x, int y)
{
	t_guielem *const	el = get_by_pos(&ctx->win, x, y, NULL);

	if (el && !check_hide(&ctx->win, el))
		return (true);
	return (false);
}

void	object_click(int keycode, int x, int y, void *p)
{
	t_ctx *const	ctx = p;
	t_ray			r;
	t_intersections	xs;
	t_intersection	*i;

	if (keycode != 1 || (ctx->gctx.w.gparam & MOVING)
		|| check_click_gui(ctx, x, y))
		return ;
	r = ray_for_pixel(ctx->gctx.w.cam, x, y);
	xs = world_intersec(&ctx->gctx.w, r);
	i = hit(&xs);
	ctx->gctx.w.xs.count -= xs.count;
	if (!i)
	{
		if (ctx->gctx.w.selec_o)
			set_edit(ctx, false);
		set_selected_obj(&ctx->gctx.w, NULL);
		return ;
	}
	set_edit(ctx, true);
	set_selected_obj(&ctx->gctx.w, i->obj);
	printf("Obj selected !\n");
}
