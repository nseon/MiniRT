/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:34:01 by nseon             #+#    #+#             */
/*   Updated: 2025/10/08 13:35:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

#ifdef BONUS

void	free_obj(void *p)
{
	t_obj *const	o = p;

	if (o->mat.has_nmap)
		free_map(o->mat.nmap.data, o->mat.nmap.infos.h);
	if (o->mat.has_tmap)
		free_map(o->mat.tmap.data, o->mat.tmap.infos.h);
	if (o->mat.has_aomap)
		free_map(o->mat.aomap.data, o->mat.aomap.infos.h);
}

#else

void	free_obj(void *p)
{
	(void)p;
}

#endif