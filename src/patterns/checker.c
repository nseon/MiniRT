/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:42:34 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/21 16:42:34 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "patterns.h"
#include "rt_maths.h"

t_fcolor	checker_at(t_pattern pat, t_tuple pt)
{
	if ((int)(round(pt.x) + round(pt.y) + round(pt.z)) % 2 == 0)
		return (pat.a);
	return (pat.b);
}
