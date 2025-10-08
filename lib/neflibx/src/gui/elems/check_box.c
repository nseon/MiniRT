/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:47:06 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/23 16:47:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"
#include "window.h"
#include "gui/gui_draw.h"
#include "gui/letters.h"

void	draw_check(t_guielem *el, t_image *img)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;

	draw_el_box(el, img);
	if (el->checked)
	{
		draw_rectangle(img, point_s(x + 3, y + 3, 0x7F7F7F),
			el->w - 3 * 2, el->h - 3 * 2);
	}
	draw_str(img, el->label, point_s(get_center_w(el, el->label),
			y - CHAR_H * el->size - LABEL_SPACING, TXT_COLOR), el->size);
}

t_guielem	*create_check(t_window *win, uint32_t puid, t_bool_cb cb, void *p)
{
	t_guielem *const	el = vct_add_dest(&win->gui_elems);

	if (!el)
		return (NULL);
	*el = (t_guielem){.type = CHECK, .color = GUI_EL_COLOR, .w = 15, .h = 15,
		.vx = -1, .vy = -1, .size = 1, .cb = {.callback = (t_generic_cb)cb,
		.cb_param = p}, .win = win, .vw = -1, .vh = -1, .id = "", .txt = ""};
	if (puid != 0)
		el->z = get_by_uid(win, puid)->z + 1;
	el->uid = ++win->last_uid;
	el->puid = puid;
	return (el);
}
