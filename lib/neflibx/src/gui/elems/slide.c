/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:24:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/17 14:24:00 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/elems/slide.h"
#include "gui/letters.h"
#include "draw.h"
#include "window.h"
#include "libft.h"
#include "gui/gui_draw.h"

void	draw_slide(t_guielem *el, t_image *img)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;
	t_guielem		bloc;

	draw_rectangle(img, point_s(x, y + el->h / 4, GUI_FOCUS_COLOR),
		el->w, el->h / 2);
	bloc = *el;
	bloc.x = el->x + el->w * el->value - el->h / 2;
	bloc.w = el->h;
	draw_el_box(&bloc, img);
	draw_str(img, el->label, point_s(x, y - CHAR_H * el->size
			- LABEL_SPACING, TXT_COLOR), el->size);
}

t_guielem	*create_slide(t_window *win, uint32_t puid, t_float_cb cb, void *p)
{
	t_guielem *const	el = vct_add_dest(&win->gui_elems);

	if (!el)
		return (NULL);
	*el = (t_guielem){.type = SLIDE, .color = GUI_EL_COLOR, .w = 200, .h = 20,
		.vx = -1, .vy = -1, .size = 1, .cb = {.callback = (t_generic_cb)cb,
		.cb_param = p}, .win = win, .vw = -1, .vh = -1, .value = 0.5f};
	el->id = "";
	if (puid != 0)
		el->z = get_by_uid(win, puid)->z + 1;
	el->uid = ++win->last_uid;
	el->puid = puid;
	return (el);
}
