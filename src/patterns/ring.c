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
#include "uv.h"

t_fcolor	ring_at(t_pattern pat, t_uv uv)
{
	if ((int)floor(sqrt(uv.u * uv.u + uv.v * uv.v)) % 2 == 0)
		return (pat.a);
	return (pat.b);
}
