/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:32:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/08 21:35:17 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "neflibx.h"
#include "minirt.h"
#include "parsing.h"

static int8_t	parse_gui(t_ctx *ctx)
{
	t_guielem *const	filename = create_txt_input(&ctx->win, 0,
			parse, ctx);

	filename->vw = 30;
	filename->vh = 6;
	filename->vx = 50;
	filename->vy = 50;
	filename->label = FILENAME;
	filename->id = FILENAME_ID;
	filename->size = 2;
	return (SUCCESS);
}

void	bool_switcher(void *param)
{
	*((bool *)param) ^= 1;
}

int8_t	init_gui(t_ctx *ctx)
{
	int8_t	res;
	t_guielem *const	butt = create_button(&ctx->win, 0,
			bool_switcher, &ctx->gctx.global_il);
	
	butt->vx = 5;
	butt->vy = 5;
	butt->txt = "Global Illumination";
	butt->hide = true;
	butt->id = "global_btn";
	res = parse_gui(ctx);
	return (res);
}

