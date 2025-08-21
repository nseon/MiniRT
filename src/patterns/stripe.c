/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:39:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/21 12:39:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "patterns.h"

t_fcolor	stripe_at(t_pattern pat, t_tuple pt)
{
	if ((int)floor(pt.x) % 2 == 0)
		return (pat.a);
	return (pat.b);
}
