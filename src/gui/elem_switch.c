/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:27:24 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/07 10:27:19 by nseon            ###   ########.fr       */
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

void	double_switch(float f, void *p)
{
	double *const	o = p;

	*o = (double)f;
}

void	refrac_switch(float f, void *p)
{
	double *const	o = p;

	*o = (double)f * 10;
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
