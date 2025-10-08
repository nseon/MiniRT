/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_edit_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:40:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/07 16:40:14 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "neflibx.h"
#include "rt_gui.h"

int32_t	edit_addi_gui(t_ctx *ctx, uint32_t cuid)
{
	t_guielem	*el;

	el = create_slide(&ctx->win, cuid, double_switch, NULL);
	el->label = "Reflection";
	el->id = "refl_slide";
	el->vy = 40;
	el->vh = 3.5;
	el->vw = 50;
	el->vx = 30;
	el = create_slide(&ctx->win, cuid, double_switch, NULL);
	el->label = "Transparency";
	el->id = "transp_slide";
	el->vy = 48;
	el->vh = 3.5;
	el->vw = 50;
	el->vx = 30;
	el = create_slide(&ctx->win, cuid, refrac_switch, NULL);
	el->label = "Refractive";
	el->id = "refrac_slide";
	el->vy = 56;
	el->vh = 3.5;
	el->vw = 50;
	el->vx = 30;
	return (SUCCESS);
}

int32_t	edit_color_gui(t_ctx *ctx, uint32_t cuid)
{
	t_guielem	*el;

	el = create_slide(&ctx->win, cuid, float_switch, NULL);
	el->label = "Red";
	el->id = "red_slide";
	el->vy = 10;
	el->vh = 3.5;
	el->vw = 50;
	el->vx = 30;
	el = create_slide(&ctx->win, cuid, float_switch, NULL);
	el->label = "Green";
	el->id = "green_slide";
	el->vy = 18;
	el->vh = 3.5;
	el->vw = 50;
	el->vx = 30;
	el = create_slide(&ctx->win, cuid, float_switch, NULL);
	el->label = "Blue";
	el->id = "blue_slide";
	el->vy = 26;
	el->vh = 3.5;
	el->vw = 50;
	el->vx = 30;
	return (SUCCESS);
}

int32_t	edit_gui(t_ctx *ctx)
{
	t_guielem *const	render_ctn = create_container(&ctx->win, 0);
	t_guielem			*el;
	const uint32_t		cuid = render_ctn->uid;

	render_ctn->id = EDIT_CTN_ID;
	render_ctn->vw = 22;
	render_ctn->vh = 70;
	render_ctn->vy = 0;
	render_ctn->vx = 100;
	render_ctn->z = 5;
	render_ctn->hide = true;
	edit_color_gui(ctx, cuid);
	edit_addi_gui(ctx, cuid);
	edit_tnmap_gui(ctx, cuid);
	edit_aomap_gui(ctx, cuid);
	return (SUCCESS);
}
