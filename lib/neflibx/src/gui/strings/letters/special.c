/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:43:57 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/19 15:43:57 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/letters.h"
#include "draw.h"
#include "gui/gui.h"

void	si_r(t_image *img, char c, t_point pt, int32_t size)
{
	const char	s1_bits[8] = {0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00};
	const char	s2_bits[8] = {0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00};
	const char	s3_bits[8] = {0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00};
	const char	s4_bits[8] = {0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00};
	const char	s5_bits[8] = {0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00};

	if (c == '?')
		draw_char(img, s1_bits, pt, size);
	else if (c == '@')
		draw_char(img, s2_bits, pt, size);
	else if (c == '[')
		draw_char(img, s3_bits, pt, size);
	else if (c == '\\')
		draw_char(img, s4_bits, pt, size);
	else if (c == ']')
		draw_char(img, s5_bits, pt, size);
	else
		sc_p(img, c, pt, size);
}

void	sd_g(t_image *img, char c, t_point pt, int32_t size)
{
	const char	sd_bits[8] = {0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00};
	const char	sv_bits[8] = {0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06};
	const char	sp_bits[8] = {0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00};
	const char	se_bits[8] = {0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00};
	const char	sg_bits[8] = {0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00};

	if (c == ':')
		draw_char(img, sd_bits, pt, size);
	else if (c == ';')
		draw_char(img, sv_bits, pt, size);
	else if (c == '<')
		draw_char(img, sp_bits, pt, size);
	else if (c == '=')
		draw_char(img, se_bits, pt, size);
	else if (c == '>')
		draw_char(img, sg_bits, pt, size);
	else
		si_r(img, c, pt, size);
}

void	sp_s(t_image *img, char c, t_point pt, int32_t size)
{
	const char	sp_bits[8] = {0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00};
	const char	sc_bits[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06};
	const char	sm_bits[8] = {0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00};
	const char	st_bits[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00};
	const char	ss_bits[8] = {0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00};

	if (c == '+')
		draw_char(img, sp_bits, pt, size);
	else if (c == ',')
		draw_char(img, sc_bits, pt, size);
	else if (c == '-')
		draw_char(img, sm_bits, pt, size);
	else if (c == '.')
		draw_char(img, st_bits, pt, size);
	else if (c == '/')
		draw_char(img, ss_bits, pt, size);
	else
		sd_g(img, c, pt, size);
}

void	se_a(t_image *img, char c, t_point pt, int32_t size)
{
	const char	se_bits[8] = {0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00};
	const char	sp_bits[8] = {0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00};
	const char	sp1_bits[8] = {0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00};
	const char	sp2_bits[8] = {0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00};
	const char	sa_bits[8] = {0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00};

	if (c == '&')
		draw_char(img, se_bits, pt, size);
	else if (c == '\'')
		draw_char(img, sp_bits, pt, size);
	else if (c == '(')
		draw_char(img, sp1_bits, pt, size);
	else if (c == ')')
		draw_char(img, sp2_bits, pt, size);
	else if (c == '*')
		draw_char(img, sa_bits, pt, size);
	else
		sp_s(img, c, pt, size);
}

void	sx_p(t_image *img, char c, t_point pt, int32_t size)
{
	const char	sx_bits[8] = {0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00};
	const char	sg_bits[8] = {0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	const char	sh_bits[8] = {0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00};
	const char	sd_bits[8] = {0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00};
	const char	sp_bits[8] = {0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00};

	if (c == '!')
		draw_char(img, sx_bits, pt, size);
	else if (c == '\"')
		draw_char(img, sg_bits, pt, size);
	else if (c == '#')
		draw_char(img, sh_bits, pt, size);
	else if (c == '$')
		draw_char(img, sd_bits, pt, size);
	else if (c == '%')
		draw_char(img, sp_bits, pt, size);
	else
		se_a(img, c, pt, size);
}
