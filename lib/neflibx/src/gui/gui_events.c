/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:34:13 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/14 12:34:13 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "gui/elems/button.h"
#include "gui/elems/check_box.h"
#include "gui/elems/slide.h"
#include "gui/elems/txt_input.h"

void	btnpress_f(t_guielem *const elem, int x)
{
	if (elem->type == BUTTON)
		elem_btn_press(elem);
	else if (elem->type == TXT_INPUT)
		elem_txt_press(elem);
	else if (elem->type == SLIDE)
		elem_slide_press(elem, x);
	else if (elem->type == CHECK)
		elem_check_press(elem);
}

void	btnrelease_f(t_guielem *const elem)
{
	if (elem->type == BUTTON)
		elem_btn_release(elem);
	else if (elem->type == SLIDE)
		elem_slide_release(elem);
	else if (elem->type == CHECK)
		elem_check_release(elem);
}

void	gui_btnpress(int keycode, int x, int y, void *p)
{
	t_window *const		win = p;
	t_guielem *const	el = get_by_pos(win, x, y, unfocus);

	if (keycode != 1)
		return ;
	if (!el)
		return ;
	if (check_hide(win, el))
		return ;
	btnpress_f(el, x);
}

void	gui_btnrelease(int keycode, int x, int y, void *p)
{
	t_window *const		win = p;
	t_guielem *const	el = get_by_pos(win, x, y, unfocus);

	if (keycode != 1)
		return ;
	if (!el)
		return ;
	if (check_hide(win, el))
		return ;
	btnrelease_f(el);
}
