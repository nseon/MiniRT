/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_9.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:23:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/19 15:23:21 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/letters.h"
#include "draw.h"
#include "gui/gui.h"

void	c8_9(t_image *img, char c, t_point pt, int32_t size)
{
	const char	c8_bits[8] = {0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00};
	const char	c9_bits[8] = {0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00};

	if (c == '8')
		draw_char(img, c8_bits, pt, size);
	else if (c == '9')
		draw_char(img, c9_bits, pt, size);
	else
		sx_p(img, c, pt, size);
}

void	c3_7(t_image *img, char c, t_point pt, int32_t size)
{
	const char	c3_bits[8] = {0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00};
	const char	c4_bits[8] = {0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00};
	const char	c5_bits[8] = {0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00};
	const char	c6_bits[8] = {0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00};
	const char	c7_bits[8] = {0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00};

	if (c == '3')
		draw_char(img, c3_bits, pt, size);
	else if (c == '4')
		draw_char(img, c4_bits, pt, size);
	else if (c == '5')
		draw_char(img, c5_bits, pt, size);
	else if (c == '6')
		draw_char(img, c6_bits, pt, size);
	else if (c == '7')
		draw_char(img, c7_bits, pt, size);
	else
		c8_9(img, c, pt, size);
}

void	yu_2(t_image *img, char c, t_point pt, int32_t size)
{
	const char	yu_bits[8] = {0x33, 0x33, 0x33, 0x1E, 0x0C, 0x0C, 0x1E, 0x00};
	const char	zu_bits[8] = {0x7F, 0x63, 0x31, 0x18, 0x4C, 0x66, 0x7F, 0x00};
	const char	c0_bits[8] = {0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00};
	const char	c1_bits[8] = {0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00};
	const char	c2_bits[8] = {0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00};

	if (c == 'Y')
		draw_char(img, yu_bits, pt, size);
	else if (c == 'Z')
		draw_char(img, zu_bits, pt, size);
	else if (c == '0')
		draw_char(img, c0_bits, pt, size);
	else if (c == '1')
		draw_char(img, c1_bits, pt, size);
	else if (c == '2')
		draw_char(img, c2_bits, pt, size);
	else
		c3_7(img, c, pt, size);
}
