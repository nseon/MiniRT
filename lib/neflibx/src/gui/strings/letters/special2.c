/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:13 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/19 17:27:13 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/letters.h"
#include "draw.h"
#include "gui/gui.h"

void	sr_t(t_image *img, char c, t_point pt, int32_t size)
{
	const char	s1_bits[8] = {0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00};
	const char	s2_bits[8] = {0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	if (c == '}')
		draw_char(img, s1_bits, pt, size);
	else if (c == '~')
		draw_char(img, s2_bits, pt, size);
}

void	sc_p(t_image *img, char c, t_point pt, int32_t size)
{
	const char	s1_bits[8] = {0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00};
	const char	s2_bits[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
	const char	s3_bits[8] = {0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00};
	const char	s4_bits[8] = {0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00};
	const char	s5_bits[8] = {0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00};

	if (c == '^')
		draw_char(img, s1_bits, pt, size);
	else if (c == '_')
		draw_char(img, s2_bits, pt, size);
	else if (c == '`')
		draw_char(img, s3_bits, pt, size);
	else if (c == '{')
		draw_char(img, s4_bits, pt, size);
	else if (c == '|')
		draw_char(img, s5_bits, pt, size);
	else
		sr_t(img, c, pt, size);
}
