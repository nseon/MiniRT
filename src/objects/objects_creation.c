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

t_obj	sphere(void)
{
	t_obj	o;

	o = (t_obj){.type = SPHERE, .uid = get_uid(), .pos = point(0, 0, 0),
		.col = {1, 0, 0}, .w = 1};
	mtx4_dup(g_identity_matrix, o.transform);
	return (o);
}
