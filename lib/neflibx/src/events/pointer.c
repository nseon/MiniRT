/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:31:12 by pjarnac           #+#    #+#             */
/*   Updated: 2025/03/05 17:31:12 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "libft.h"

void	register_pointer(t_callback *events[EVENTS_NUM],
			t_ptr_cb cb, void *cb_param)
{
	t_callback	e;

	e.callback = (t_generic_cb)cb;
	e.cb_param = cb_param;
	if (vct_add(&events[POINTER_EV], &e) == -1)
		ft_fprintf(2, "error adding event, it will not be available\n");
}

int	pointer_event(int x, int y,
		t_callback *events[EVENTS_NUM])
{
	size_t				i;
	const size_t		size = vct_size(events[POINTER_EV]);

	i = 0;
	while (i < size)
	{
		((t_ptr_cb)events[POINTER_EV][i].callback)(x, y,
			events[POINTER_EV][i].cb_param);
		i++;
	}
	return (0);
}
