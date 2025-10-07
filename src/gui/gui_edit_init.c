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
#include "rt_gui.h"
#include "neflibx.h"

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

int32_t	edit_aomap_gui(t_ctx *ctx, uint32_t cuid)
{
	t_guielem	*el;

	el = create_check(&ctx->win, cuid, nmap_bool, NULL);
	el->label = "";
	el->id = "nmap_check";
	el->w = 15;
	el->h = 15;
	el->vx = 87;
	el->vy = 80;
	el = create_txt_input(&ctx->win, cuid, input_aomap, NULL);
	el->label = "Ambient Occlusion Map";
	el->id = "aomap_input";
	el->vy = 90;
	el->vw = 70;
	el->vh = 5;
	el->vx = 40;
	el = create_check(&ctx->win, cuid, aomap_bool, NULL);
	el->label = "";
	el->id = "aomap_check";
	el->w = 15;
	el->h = 15;
	el->vx = 87;
	el->vy = 90;
	return (SUCCESS);
}

int32_t	edit_tnmap_gui(t_ctx *ctx, uint32_t cuid)
{
	t_guielem	*el;

	el = create_txt_input(&ctx->win, cuid, input_tmap, NULL);
	el->label = "Texture Map";
	el->id = "tmap_input";
	el->vy = 70;
	el->vw = 70;
	el->vh = 5;
	el->vx = 40;
	el = create_check(&ctx->win, cuid, tmap_bool, NULL);
	el->label = "";
	el->id = "tmap_check";
	el->w = 15;
	el->h = 15;
	el->vx = 87;
	el->vy = 70;
	el = create_txt_input(&ctx->win, cuid, input_nmap, NULL);
	el->label = "Normal Map";
	el->id = "nmap_input";
	el->vy = 80;
	el->vw = 70;
	el->vh = 5;
	el->vx = 40;
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
