/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_switcher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:14:22 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/25 17:14:22 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_gui.h"
#include "render.h"

void	xor_denoise(bool b, void *p)
{
	int32_t *const	gp = p;

	if (b)
		*gp |= DENOISE;
	else
		*gp &= ~DENOISE;
}

void	xor_ss(bool b, void *p)
{
	t_ctx *const	ctx = p;

	if (b)
		ctx->gctx.w.gparam |= SS;
	else
		ctx->gctx.w.gparam &= ~SS;
	clear_ss(&ctx->gctx.ss);
}

void	xor_indirect(bool b, void *p)
{
	t_ctx *const	ctx = p;

	if (b)
		ctx->gctx.w.gparam |= INDIRECT;
	else
		ctx->gctx.w.gparam &= ~INDIRECT;
	clear_ss(&ctx->gctx.ss);
}

void	xor_render(bool b, void *p)
{
	t_ctx *const	ctx = p;

	if (b)
		ctx->gctx.w.gparam |= RENDER;
	else
		ctx->gctx.w.gparam &= ~RENDER;
}