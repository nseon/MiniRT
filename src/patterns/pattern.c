/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:34:01 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/21 12:34:01 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"
#include "objects.h"
#include "uv.h"

t_pattern	pattern(t_fcolor a, t_fcolor b, t_pattern_type type)
{
	t_pattern	pat;

	pat.type = type;
	pat.a = a;
	pat.b = b;
	return (pat);
}

t_fcolor	pattern_at_obj(t_pattern pat, t_obj *o, t_tuple pt)
{
	if (pat.type == STRIPE)
		return (stripe_at(pat, pt));
	if (pat.type == GRADIENT)
		return (gradient_at(pat, pt));
	if (pat.type == RING)
		return (ring_at(pat, pt));
	if (pat.type == CHECKER)
		return (checker_at(pat, pt));
	return (fcolor(0, 0, 0));
}
