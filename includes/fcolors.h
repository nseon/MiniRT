/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:34:18 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/29 08:34:18 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCOLORS_H
# define FCOLORS_H

typedef struct s_fcolor
{
	float	r;
	float	g;
	float	b;
}	t_fcolor;

t_fcolor	fcolor(float r, float g, float b);
t_fcolor	color_add(t_fcolor c1, t_fcolor c2);
t_fcolor	color_sub(t_fcolor c1, t_fcolor c2);
t_fcolor	color_scalar(t_fcolor c1, float k);
t_fcolor	color_mul(t_fcolor c1, t_fcolor c2);

#endif
