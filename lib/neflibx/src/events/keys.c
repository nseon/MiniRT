/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:23:42 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/24 16:23:42 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "events.h"
#include "libft.h"

void	register_keypress(t_callback *events[EVENTS_NUM],
			t_key_cb cb, void *cb_param)
{
	t_callback	e;

	e.callback = (t_generic_cb)cb;
	e.cb_param = cb_param;
	if (vct_add(&events[KEYPRESS_EV], &e) == -1)
		ft_fprintf(2, "error adding event, it will not be available\n");
}

int	keypress_event(int keycode, t_callback *events[EVENTS_NUM])
{
	size_t				i;
	const size_t		size = vct_size(events[KEYPRESS_EV]);

	i = 0;
	while (i < size)
	{
		((t_key_cb)events[KEYPRESS_EV][i].callback)(keycode,
			events[KEYPRESS_EV][i].cb_param);
		i++;
	}
	return (0);
}

void	register_keyrelease(t_callback *events[EVENTS_NUM],
			t_key_cb cb, void *cb_param)
{
	t_callback	e;

	e.callback = (t_generic_cb)cb;
	e.cb_param = cb_param;
	if (vct_add(&events[KEYRELEASE_EV], &e) == -1)
		ft_fprintf(2, "error adding event, it will not be available\n");
}

int	keyrelease_event(int keycode, t_callback *events[EVENTS_NUM])
{
	size_t				i;
	const size_t		size = vct_size(events[KEYRELEASE_EV]);

	i = 0;
	while (i < size)
	{
		((t_key_cb)events[KEYRELEASE_EV][i].callback)(keycode,
			events[KEYRELEASE_EV][i].cb_param);
		i++;
	}
	return (0);
}
