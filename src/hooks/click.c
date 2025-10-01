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
	size_t	i;

	if (b)
		ctx->gctx.w.gparam |= EDIT;
	else
		ctx->gctx.w.gparam &= ~EDIT;
	switch_gui_param(ctx, "ss_btn", b ^ true);
	i = -1;
	while (++i < vct_size(ctx->gctx.w.objs))
		ctx->gctx.w.objs[i].hide = b;
}

void	set_selected_obj(t_ctx *ctx, t_obj *o)
{
	size_t	i;

	if (!o)
	{
		ctx->gctx.w.selec_o = NULL;
		get_by_id(&ctx->win, EDIT_CTN_ID)->hide = true;
		return ;
	}
	i = -1;
	while (++i < vct_size(ctx->gctx.w.objs))
	{
		if (ctx->gctx.w.objs + i == o)
		{
			ctx->gctx.w.objs[i].hide = false;
			show_edit(ctx, o);
			ctx->gctx.w.selec_o = o;
		}
	}
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
		set_edit(ctx, false);
		set_selected_obj(ctx, NULL);
		return ;
	}
	set_edit(ctx, true);
	set_selected_obj(ctx, i->obj);
}
