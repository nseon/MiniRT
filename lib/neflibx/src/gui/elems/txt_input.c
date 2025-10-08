/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:34:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 13:34:21 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"
#include "draw.h"
#include "gui/gui_draw.h"
#include "gui/letters.h"
#include "libft.h"
#include "window.h"

void	draw_txt_input(t_guielem *el, t_image *img)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;
	const int32_t	w = el->w;
	const int32_t	h = el->h;
	const int32_t	to_w = get_c_to_write(el);

	draw_el_box(el, img);
	draw_str(img, el->label, point_s(x, y - CHAR_H * el->size
			- LABEL_SPACING, TXT_COLOR), el->size);
	draw_str(img, el->txt + to_w, point_s(x + w * INPUT_MARGIN, y
			+ (h - CHAR_H * el->size) / 2, TXT_COLOR), el->size);
	if (el->focus)
	{
		draw_rectangle(img, point_s(x + (el->cursor - to_w)
				* CHAR_W * el->size + (w * INPUT_MARGIN), y + h / 2 - 4 - (2
					* el->size), 0xd3c6aa), 1, CHAR_H * el->size + 4);
	}
}

t_guielem	*create_txt_input(t_window *win, uint32_t puid,
				t_txt_cb cb, void *p)
{
	t_guielem *const	el = vct_add_dest(&win->gui_elems);

	if (!el)
		return (NULL);
	*el = (t_guielem){0};
	*el = (t_guielem){.type = TXT_INPUT, .color = GUI_EL_COLOR,
		.w = 150, .h = 20,
		.vx = -1, .vy = -1, .size = 1, .cb = {.callback = (t_generic_cb)cb,
		.cb_param = p}, .win = win, .vw = -1, .vh = -1, .id = ""};
	el->txt = vct_create(sizeof (char), 0, 0);
	vct_add(&el->txt, &(char){0});
	el->uid = ++win->last_uid;
	el->puid = puid;
	if (puid != 0)
		el->z = get_by_uid(win, puid)->z + 1;
	return (el);
}
