/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:20:11 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 19:20:11 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "gui/elems/txt_input.h"
#include <stdio.h>

#include "gui/elems/slide.h"

void	keypress_f(t_guielem *elem, t_window *win, int keycode)
{
	if (elem->type == TXT_INPUT)
		elem_txt_key(elem, win, keycode);
}

void	gui_keypress(int keycode, void *p)
{
	t_window *const		win = p;
	t_guielem *const	el = get_focused_el(win);

	if (!el)
		return ;
	if (check_hide(win, el))
		return ;
	keypress_f(el, win, keycode);
}

void	ptr_f(t_guielem *elem, int x, int y)
{
	if (elem->type == SLIDE)
		elem_slide_ptr(elem, x, y);
}

void	gui_ptr(int x, int y, void *p)
{
	t_window *const		win = p;
	t_guielem *const	el = get_by_pos(win, x, y, unhover);

	if (get_focused_el(win))
	{
		ptr_f(get_focused_el(win), x, y);
		return ;
	}
	if (!el || el->type == CONTAINER)
		return ;
	if (check_hide(win, el))
		return ;
	el->hover = true;
}
