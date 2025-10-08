/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_edit_init_maps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:28:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/08 13:28:00 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "neflibx.h"
#include "rt_gui.h"

#ifdef BONUS

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

#else

int32_t	edit_aomap_gui(t_ctx *ctx, uint32_t cuid)
{
	(void)ctx;
	(void)cuid;
	return (SUCCESS);
}

int32_t	edit_tnmap_gui(t_ctx *ctx, uint32_t cuid)
{
	(void)ctx;
	(void)cuid;
	return (SUCCESS);
}

#endif
