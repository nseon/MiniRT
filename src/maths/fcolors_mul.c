/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcolors_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:11:05 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/22 10:11:05 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcolors.h"

t_fcolor	col_scalar(t_fcolor c1, double k)
{
	if (k < 0)
		return (fcolor(0, 0, 0));
	return ((t_fcolor){c1.r * k, c1.g * k, c1.b * k});
}

t_fcolor	col_scalar2(t_fcolor c1, double k)
{
	return ((t_fcolor){c1.r * k, c1.g * k, c1.b * k});
}

t_fcolor	color_mul(t_fcolor c1, t_fcolor c2)
{
	return ((t_fcolor){c1.r * c2.r, c1.g * c2.g, c1.b * c2.b});
}