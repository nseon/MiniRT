/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:36:39 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/06 15:36:39 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_gui.h"

void	tmap_bool(bool b, void *p)
{
	t_material *const	mat = p;

	if (!mat->tmap.data)
		return ;
	mat->has_tmap = b;
}

void	nmap_bool(bool b, void *p)
{
	t_material *const	mat = p;

	if (!mat->nmap.data)
		return ;
	mat->has_nmap = b;
}

void	aomap_bool(bool b, void *p)
{
	t_material *const	mat = p;

	if (!mat->aomap.data)
		return ;
	mat->has_aomap = b;
}
