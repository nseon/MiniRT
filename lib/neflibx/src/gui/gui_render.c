/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:26:17 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/06 15:26:17 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "window.h"
#include "libft.h"
#include "gui/gui_draw.h"
#include "gui/elems/button.h"
#include "gui/elems/check_box.h"
#include "gui/elems/txt_input.h"
#include "gui/elems/container.h"
#include "gui/elems/slide.h"
#include "gui/elems/text_box.h"

void	draw_elem(t_guielem *el, t_image *img)
{
	if (el->type == BUTTON)
		draw_button(el, img);
	else if (el->type == TXT_INPUT)
		draw_txt_input(el, img);
	else if (el->type == CONTAINER)
		draw_container(el, img);
	else if (el->type == SLIDE)
		draw_slide(el, img);
	else if (el->type == TXT_BOX)
		draw_text_box(el, img);
	else if (el->type == CHECK)
		draw_check(el, img);
}

int	compare_z(void *a, void *b)
{
	if (((t_guielem *)a)->z < ((t_guielem *)b)->z)
		return (1);
	return (0);
}

bool	check_hide(t_window *win, t_guielem *e)
{
	if (!e)
		return (false);
	if (e->uid == 0)
		return (false);
	if (e->hide)
		return (true);
	return (check_hide(win, get_by_uid(win, e->puid)));
}

void	gui_render(t_image *img)
{
	size_t			i;
	t_window *const	win = img->win;

	vct_sort(win->gui_elems, compare_z);
	i = -1;
	while (++i < vct_size(win->gui_elems))
		convert_to_vpos(win->gui_elems + i);
	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (check_hide(win, win->gui_elems + i))
			continue ;
		draw_elem(win->gui_elems + i, img);
	}
}
