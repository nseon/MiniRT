/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_input_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:34:57 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 13:34:57 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"
#include "libft.h"
#include "gui/letters.h"
#include <X11/keysym.h>
#include "window.h"

void	elem_txt_press(t_guielem *input)
{
	input->focus = true;
}

static void	cursor(t_guielem *el, int keycode)
{
	int32_t	to_w;

	to_w = 0;
	if (ft_strlen(el->txt) > (el->w - el->w * 0.1) / (CHAR_W * el->size))
		to_w = ft_strlen(el->txt) - (el->w - el->w * 0.1)
			/ (CHAR_W * el->size);
	if (keycode == XK_Right
		&& el->cursor < (int32_t)vct_size(el->txt) - 1)
		el->cursor += 1;
	else if (keycode == XK_Left && el->cursor > to_w)
		el->cursor -= 1;
}

void	elem_txt_key(t_guielem *input, t_window *win, int keycode)
{
	if (!input->focus)
		return ;
	if (32 <= keycode && keycode <= 126)
	{
		if (win->shift)
			keycode = get_shifted(keycode);
		vct_insert(&input->txt, &keycode, input->cursor);
		input->cursor += 1;
	}
	else if (keycode == XK_Return)
	{
		((t_txt_cb)input->cb.callback)(input->txt, input->cb.cb_param);
		vct_erase(input->txt, 0, vct_size(input->txt) - 1);
		input->cursor = 0;
	}
	else if (keycode == XK_BackSpace && input->cursor > 0)
	{
		vct_delete(input->txt, input->cursor - 1);
		input->cursor -= 1;
	}
	cursor(input, keycode);
}
