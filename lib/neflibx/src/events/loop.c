/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:14:30 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/06 15:14:30 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "libft.h"

void	register_loop(t_callback *events[EVENTS_NUM],
			t_generic_cb cb, void *cb_param)
{
	t_callback	e;

	e.callback = (t_generic_cb)cb;
	e.cb_param = cb_param;
	if (vct_add(&events[LOOP_EV], &e) == -1)
		ft_fprintf(2, "error adding event, it will not be available\n");
}

int	loop_event(t_callback *events[EVENTS_NUM])
{
	size_t				i;
	const size_t		size = vct_size(events[LOOP_EV]);

	i = 0;
	while (i < size)
	{
		(events[LOOP_EV][i].callback)(events[LOOP_EV][i].cb_param);
		i++;
	}
	return (0);
}
