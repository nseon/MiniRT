/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:47:41 by pjarnac           #+#    #+#             */
/*   Updated: 2025/03/04 14:47:41 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:33:33 by pjarnac           #+#    #+#             */
/*   Updated: 2025/03/04 14:33:33 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "libft.h"

void	register_btnpress(t_callback *events[EVENTS_NUM],
			t_btn_cb cb, void *cb_param)
{
	t_callback	e;

	e.callback = (t_generic_cb)cb;
	e.cb_param = cb_param;
	if (vct_add(&events[BTNPRESS_EV], &e) == -1)
		ft_fprintf(2, "error adding event, it will not be available\n");
}

int	btnpress_event(int keycode, int x, int y,
		t_callback *events[EVENTS_NUM])
{
	size_t				i;
	const size_t		size = vct_size(events[BTNPRESS_EV]);

	i = 0;
	while (i < size)
	{
		((t_btn_cb)events[BTNPRESS_EV][i].callback)(keycode, x, y,
			events[BTNPRESS_EV][i].cb_param);
		i++;
	}
	return (0);
}

void	register_btnrelease(t_callback *events[EVENTS_NUM],
			t_btn_cb cb, void *cb_param)
{
	t_callback	e;

	e.callback = (t_generic_cb)cb;
	e.cb_param = cb_param;
	if (vct_add(&events[BTNRELEASE_EV], &e) == -1)
		ft_fprintf(2, "error adding event, it will not be available\n");
}

int	btnrelease_event(int keycode, int x, int y,
		t_callback *events[EVENTS_NUM])
{
	size_t				i;
	const size_t		size = vct_size(events[BTNRELEASE_EV]);

	i = 0;
	while (i < size)
	{
		((t_btn_cb)events[BTNRELEASE_EV][i].callback)(keycode, x, y,
			events[BTNRELEASE_EV][i].cb_param);
		i++;
	}
	return (0);
}
