/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:24:09 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/17 14:24:09 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "gui/gui.h"

void	elem_slide_press(t_guielem *const el, int x)
{
	float const	rx = x - el->x;
	float const	prec = el->value;

	el->focus = true;
	el->l_clicked = true;
	el->value = rx / el->w;
	if (prec != el->value)
		((t_float_cb)el->cb.callback)(el->value, el->cb.cb_param);
}

void	elem_slide_release(t_guielem *const el)
{
	if (el->focus)
	{
		el->focus = false;
		el->l_clicked = false;
	}
}

void	elem_slide_ptr(t_guielem *const el, int x, int y)
{
	float const	rx = x - el->x;
	float const	prec = el->value;

	(void)y;
	if (!el->l_clicked)
		return ;
	el->value = rx / el->w;
	if (el->value < 0 || el->value > 1)
	{
		if (el->value < 0)
			el->value = 0;
		if (el->value > 1)
			el->value = 1;
	}
	if (prec != el->value)
		((t_float_cb)el->cb.callback)(el->value, el->cb.cb_param);
}
