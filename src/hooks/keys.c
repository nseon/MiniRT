/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:23:23 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/29 15:23:23 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "render.h"
#include "gui/gui.h"

void	gui_keys(int keycode, void *p)
{
	t_ctx *const	ctx = p;

	if (keycode == XK_quoteleft)
		get_by_id(&ctx->win, RENDER_CTN_ID)->hide ^= true;
	else if (keycode == XK_Escape)
		end_loop(&ctx->win);
}
