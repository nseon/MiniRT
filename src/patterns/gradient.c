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
#include "uv.h"

t_fcolor	gradient_at(t_pattern pat, t_uv uv)
{
	t_fcolor const	dis = color_sub(pat.b, pat.a);
	double const	fac = uv.u - floor(uv.u);

	return (color_add(pat.a, col_scalar(dis, fac)));
}
