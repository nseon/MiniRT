/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:16:06 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 21:16:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "window.h"
#include "libft.h"
#include "gui/gui.h"

int	destroy_window(t_window *window)
{
	size_t	i;

	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	if (window->gui_elems)
		vct_destroy(window->gui_elems);
	i = -1;
	while (++i < EVENTS_NUM)
		if (window->events[i])
			vct_destroy(window->events[i]);
	return (-1);
}

int	end_loop(t_window *window)
{
	mlx_loop_end(window->mlx);
	return (0);
}

int	init_window(t_window *window, int32_t w, int32_t h, char *title)
{
	*window = (t_window){0};
	window->mlx = mlx_init();
	if (!window->mlx)
		return (-1);
	window->win = mlx_new_window(window->mlx, w, h, title);
	if (!window->win)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		return (-1);
	}
	window->gui_elems = vct_create(sizeof (t_guielem), free_gui_elem, 0);
	if (!window->gui_elems)
		return (destroy_window(window));
	vct_add(&window->gui_elems, &(t_guielem){.w = w, .h = h, .type = ROOT,
		.z = -9999, .uid = 0, .win = window, .id = ""});
	if (init_events(window) != 0)
		return (destroy_window(window));
	register_events(window);
	window->w = w;
	window->h = h;
	window->title = title;
	return (0);
}
