/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:34:45 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 13:34:45 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"

void	elem_btn_press(t_guielem *const btn)
{
	btn->focus = true;
}

void	elem_btn_release(t_guielem *const btn)
{
	if (btn->focus)
	{
		btn->focus = false;
		btn->cb.callback(btn->cb.cb_param);
	}
}
