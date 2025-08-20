/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:35:53 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 19:35:53 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "objects.h"

uint32_t	get_uid(void)
{
	static uint32_t	uid;

	return (uid++);
}

t_light	light(t_tuple pos, t_fcolor intensity, t_light_type type)
{
	return ((t_light){.type = type, .pos = pos, .i = intensity});
}
