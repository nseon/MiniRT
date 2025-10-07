/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:56:30 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/07 10:52:54 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "patterns.h"

t_fcolor	gradient_at(t_pattern pat, t_tuple pt)
{
	t_fcolor const	dis = color_sub(pat.b, pat.a);
	double const	fac = pt.x - floor(pt.x);

	return (color_add(pat.a, col_scalar(dis, fac)));
}
