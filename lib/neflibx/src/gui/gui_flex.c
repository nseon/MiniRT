/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_flex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:11:45 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/20 15:11:45 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"

void	convert_vxy(t_guielem *e, t_guielem *p)
{
	if (e->vy >= 0)
		e->y = p->h * (e->vy / 100) - e->h / 2 + p->y;
	if (e->y < p->y)
		e->y = p->y;
	if (e->y + e->h > p->y + p->h)
		e->y = p->y + p->h - e->h;
	if (e->vx >= 0)
		e->x = p->w * (e->vx / 100) - e->w / 2 + p->x;
	if (e->x < p->x)
		e->x = p->x;
	if (e->x + e->w > p->x + p->w)
		e->x = p->x + p->w - e->w;
}

void	convert_vwh(t_guielem *e, t_guielem *p)
{
	if (e->vw >= 0)
		e->w = p->w * (e->vw / 100);
	if (e->vh >= 0)
		e->h = p->h * (e->vh / 100);
}

void	convert_to_vpos(t_guielem *e)
{
	t_guielem	*p;
	int32_t		min;

	if (e->type == ROOT)
		return ;
	if (e->vy >= 0 || e->vx >= 0 || e->vh >= 0 || e->vy >= 0)
		p = get_by_uid(e->win, e->puid);
	else
		return ;
	convert_vwh(e, p);
	convert_vxy(e, p);
	if (e->vh < 0)
		return ;
	if (e->w > e->h)
		min = e->h;
	else
		min = e->w;
	e->size = min / 50 + 1;
}
