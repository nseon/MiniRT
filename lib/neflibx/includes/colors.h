/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:05 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/18 17:59:32 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdint.h>

typedef union u_color
{
	uint32_t	argb;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
}	t_color;

typedef union u_color64
{
	uint64_t		argb;
	struct
	{
		uint16_t	b;
		uint16_t	g;
		uint16_t	r;
		uint16_t	a;
	};
}	t_color64;

typedef struct s_rgb96_t
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}	t_rgb96_t;

t_color		argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b);
uint32_t	colorx(int32_t color, float m);
uint32_t	colorx64(int64_t color, float m);
uint32_t	colorp(uint32_t color, uint32_t color2);
uint32_t	color_mix(uint32_t color, uint32_t mix_color, uint32_t nb_mix);

#endif
