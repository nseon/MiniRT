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

int8_t	init_gui(t_ctx *ctx)
{
	int8_t	res;

	res = parse_gui(ctx);
	return (res);
}
