/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_y.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:23:48 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/19 08:23:48 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/letters.h"
#include "draw.h"
#include "gui/gui.h"

void	u_y(t_image *img, char c, t_point pt, int32_t size)
{
	const char	u_bits[8] = {0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00};
	const char	v_bits[8] = {0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00};
	const char	w_bits[8] = {0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00};
	const char	x_bits[8] = {0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00};
	const char	y_bits[8] = {0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F};

	if (c == 'u')
		draw_char(img, u_bits, pt, size);
	else if (c == 'v')
		draw_char(img, v_bits, pt, size);
	else if (c == 'w')
		draw_char(img, w_bits, pt, size);
	else if (c == 'x')
		draw_char(img, x_bits, pt, size);
	else if (c == 'y')
		draw_char(img, y_bits, pt, size);
	else
		z_du(img, c, pt, size);
}

void	p_t(t_image *img, char c, t_point pt, int32_t size)
{
	const char	p_bits[8] = {0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F};
	const char	q_bits[8] = {0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78};
	const char	r_bits[8] = {0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00};
	const char	s_bits[8] = {0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00};
	const char	t_bits[8] = {0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00};

	if (c == 'p')
		draw_char(img, p_bits, pt, size);
	else if (c == 'q')
		draw_char(img, q_bits, pt, size);
	else if (c == 'r')
		draw_char(img, r_bits, pt, size);
	else if (c == 's')
		draw_char(img, s_bits, pt, size);
	else if (c == 't')
		draw_char(img, t_bits, pt, size);
	else
		u_y(img, c, pt, size);
}

void	k_o(t_image *img, char c, t_point pt, int32_t size)
{
	const char	k_bits[8] = {0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00};
	const char	l_bits[8] = {0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00};
	const char	m_bits[8] = {0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00};
	const char	n_bits[8] = {0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00};
	const char	o_bits[8] = {0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00};

	if (c == 'k')
		draw_char(img, k_bits, pt, size);
	else if (c == 'l')
		draw_char(img, l_bits, pt, size);
	else if (c == 'm')
		draw_char(img, m_bits, pt, size);
	else if (c == 'n')
		draw_char(img, n_bits, pt, size);
	else if (c == 'o')
		draw_char(img, o_bits, pt, size);
	else
		p_t(img, c, pt, size);
}

void	f_j(t_image *img, char c, t_point pt, int32_t size)
{
	const char	f_bits[8] = {0x1C, 0x36, 0x06, 0x0f, 0x06, 0x06, 0x0F, 0x00};
	const char	g_bits[8] = {0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F};
	const char	h_bits[8] = {0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00};
	const char	i_bits[8] = {0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00};
	const char	j_bits[8] = {0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E};

	if (c == 'f')
		draw_char(img, f_bits, pt, size);
	else if (c == 'g')
		draw_char(img, g_bits, pt, size);
	else if (c == 'h')
		draw_char(img, h_bits, pt, size);
	else if (c == 'i')
		draw_char(img, i_bits, pt, size);
	else if (c == 'j')
		draw_char(img, j_bits, pt, size);
	else
		k_o(img, c, pt, size);
}

void	a_e(t_image *img, char c, t_point pt, int32_t size)
{
	const char	a_bits[8] = {0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00};
	const char	b_bits[8] = {0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00};
	const char	c_bits[8] = {0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00};
	const char	d_bits[8] = {0x38, 0x30, 0x30, 0x3e, 0x33, 0x33, 0x6E, 0x00};
	const char	e_bits[8] = {0x00, 0x00, 0x1E, 0x33, 0x3f, 0x03, 0x1E, 0x00};

	if (c == 'a')
		draw_char(img, a_bits, pt, size);
	else if (c == 'b')
		draw_char(img, b_bits, pt, size);
	else if (c == 'c')
		draw_char(img, c_bits, pt, size);
	else if (c == 'd')
		draw_char(img, d_bits, pt, size);
	else if (c == 'e')
		draw_char(img, e_bits, pt, size);
	else
		f_j(img, c, pt, size);
}
