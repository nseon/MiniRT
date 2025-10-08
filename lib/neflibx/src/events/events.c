/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:03:54 by pjarnac           #+#    #+#             */
/*   Updated: 2025/03/03 11:03:54 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>

#include "events.h"
#include "libft.h"
#include "mlx.h"
#include "window.h"
#include "gui/gui_events.h"

void	register_events(t_window *win)
{
	mlx_hook(win->win, KeyPress, KeyPressMask, keypress_event, win->events);
	mlx_hook(win->win, KeyRelease, KeyReleaseMask,
		keyrelease_event, win->events);
	mlx_hook(win->win, ButtonPress, ButtonPressMask,
		btnpress_event, win->events);
	mlx_hook(win->win, ButtonRelease, ButtonReleaseMask,
		btnrelease_event, win->events);
	mlx_hook(win->win, MotionNotify, PointerMotionMask,
		pointer_event, win->events);
	mlx_hook(win->win, DestroyNotify, StructureNotifyMask,
		destroy_event, win->events);
	mlx_loop_hook(win->mlx, loop_event, win->events);
}

int	init_events(t_window *win)
{
	int	i;

	i = -1;
	while (++i < EVENTS_NUM)
	{
		win->events[i] = vct_create(sizeof (t_callback), 0, 0);
		if (!win->events[i])
			return (-1);
	}
	register_btnpress(win->events, gui_btnpress, win);
	register_btnrelease(win->events, gui_btnrelease, win);
	register_keypress(win->events, gui_keypress, win);
	register_keypress(win->events, handle_shift_press, win);
	register_keyrelease(win->events, handle_shift_release, win);
	register_pointer(win->events, gui_ptr, win);
	return (0);
}
