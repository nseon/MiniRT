/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:11:24 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/08 20:11:24 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	set_transform(t_obj *o, t_mtx4 transf)
{
	mtx_mul2(o->transform, transf);
	mtx4_inverse2(o->transform, o->inv_transform);
}
