/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:38:23 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/21 10:38:23 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "gui/gui.h"
#include "draw.h"
#include "gui/gui_draw.h"
#include "gui/letters.h"
#include "libft.h"
#include "window.h"

void	draw_text_box(t_guielem *el, t_image *img)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;
	int32_t			to_w;
	int32_t			i;

	i = 0;
	to_w = vct_size(el->txt) - 1;
	while (to_w > 0)
	{
		draw_nstr(img, el->txt + (vct_size(el->txt) - 1) - to_w, point_s(x,
				y + i * (CHAR_H * el->size + 2), el->txt_color),
			(int32_t[2]){el->size, el->w / (CHAR_W * el->size)});
		to_w -= el->w / (CHAR_W * el->size);
		i++;
	}
}

t_guielem	*create_text_box(t_window *win, uint32_t puid)
{
	t_guielem *const	el = vct_add_dest(&win->gui_elems);

	if (!el)
		return (NULL);
	*el = (t_guielem){0};
	*el = (t_guielem){.type = TXT_BOX, .color = GUI_EL_COLOR, .w = 150,
		.h = 20, .vx = -1, .vy = -1, .size = 1, .win = win,
		.vw = -1, .vh = -1, .id = "", .txt_color = TXT_COLOR};
	el->txt = vct_create(sizeof (char), 0, 0);
	vct_add(&el->txt, &(char){0});
	el->uid = ++win->last_uid;
	el->puid = puid;
	if (puid != 0)
		el->z = get_by_uid(win, puid)->z + 1;
	return (el);
}
