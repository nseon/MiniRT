/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:13:17 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/12 17:13:17 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stdint.h>

# include "events.h"
# include "image.h"
# include "gui/gui.h"

typedef struct s_window
{
	void		*mlx;
	void		*win;
	char		*title;
	t_callback	*events[EVENTS_NUM];
	int			w;
	int			h;
	t_guielem	*gui_elems;
	uint32_t	last_uid;
	bool		shift;
}	t_window;

int		init_window(t_window *window, int32_t w, int32_t h, char *title);
int		destroy_window(t_window *window);
int		end_loop(t_window *window);
void	register_events(t_window *win);
int		init_events(t_window *win);

#endif
