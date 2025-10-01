/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slides.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:27:24 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/01 15:27:24 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "minirt.h"
#include "rt_gui.h"

void	float_switch(float f, void *p)
{
	float *const	o = p;

	*o = f;
}

void	pat_a_col_set(void *p)
{
	t_ctx *const	ctx = p;

	set_color(ctx, &ctx->gctx.w.selec_o->mat.pat.a);
}

void	pat_b_col_set(void *p)
{
	t_ctx *const	ctx = p;

	set_color(ctx, &ctx->gctx.w.selec_o->mat.pat.b);
}

void	base_col_set(void *p)
{
	t_ctx *const	ctx = p;

	set_color(ctx, &ctx->gctx.w.selec_o->mat.col);
}