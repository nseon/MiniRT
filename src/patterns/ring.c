/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:46:42 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/21 15:46:42 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "patterns.h"

t_fcolor	ring_at(t_pattern pat, t_tuple pt)
{
	if ((int)floor(sqrt(pt.x * pt.x + pt.z * pt.z)) % 2 == 0)
		return (pat.a);
	return (pat.b);
}
