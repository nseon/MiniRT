/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:01:52 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/16 12:01:52 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"
#include "gui/gui_draw.h"
#include "gui/letters.h"
#include "libft.h"
#include "window.h"

void	draw_container(t_guielem *el, t_image *img)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;

	draw_el_box(el, img);
	draw_str(img, el->label, point_s(x, y - CHAR_H * el->size
			- LABEL_SPACING, TXT_COLOR), el->size);
}

t_guielem	*create_container(t_window *win, uint32_t puid)
{
	t_guielem *const	el = vct_add_dest(&win->gui_elems);

	if (!el)
		return (NULL);
	*el = (t_guielem){.type = CONTAINER, .color = CONTAINER_COLOR, .w = 400,
		.h = 400, .size = 1, .vx = -1, .vy = -1, .win = win, .vw = -1,
		.vh = -1, .id = ""};
	if (puid != 0)
		el->z = get_by_uid(win, puid)->z + 1;
	el->uid = ++win->last_uid;
	el->puid = puid;
	return (el);
}
