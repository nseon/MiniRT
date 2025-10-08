/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:52 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/17 13:23:52 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "libft.h"

#include <X11/keysym.h>

void	free_gui_elem(void *p)
{
	t_guielem *const	el = p;

	if (el->type == TXT_INPUT || el->type == TXT_BOX)
		free_vct(el->txt);
}

void	handle_shift_press(int keycode, void *p)
{
	t_window	*win;

	win = (t_window *)p;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		win->shift = true;
	else if (keycode == XK_Caps_Lock)
	{
		if (win->shift == true)
			win->shift = false;
		else if (win->shift == false)
			win->shift = true;
	}
}

void	handle_shift_release(int keycode, void *p)
{
	t_window	*win;

	win = (t_window *)p;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		win->shift = false;
}
