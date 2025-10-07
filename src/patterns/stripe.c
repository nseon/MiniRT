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
#include "rt_maths.h"
#include "uv.h"

t_fcolor	stripe_at(t_pattern pat, t_uv uv)
{
	if ((int)floor(uv.u * 2) % 2 == 0)
		return (pat.a);
	return (pat.b);
}
