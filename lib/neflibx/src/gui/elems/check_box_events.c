/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:49:40 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/23 16:49:40 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"

void	elem_check_press(t_guielem *const btn)
{
	btn->focus = true;
}

void	elem_check_release(t_guielem *const btn)
{
	if (btn->focus)
	{
		btn->focus = false;
		btn->checked ^= true;
		((t_bool_cb)btn->cb.callback)(btn->checked, btn->cb.cb_param);
	}
}
