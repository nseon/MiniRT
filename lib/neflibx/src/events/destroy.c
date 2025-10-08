/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:41:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/06 09:41:26 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "libft.h"

void	register_destroy(t_callback *events[EVENTS_NUM],
			t_generic_cb cb, void *cb_param)
{
	t_callback	e;

	e.callback = (t_generic_cb)cb;
	e.cb_param = cb_param;
	if (vct_add(&events[DESTROY_EV], &e) == -1)
		ft_fprintf(2, "error adding event, it will not be available\n");
}

int	destroy_event(t_callback *events[EVENTS_NUM])
{
	size_t				i;
	const size_t		size = vct_size(events[DESTROY_EV]);

	i = 0;
	while (i < size)
	{
		((t_generic_cb)events[DESTROY_EV][i].callback)(
			events[DESTROY_EV][i].cb_param);
		i++;
	}
	return (0);
}
