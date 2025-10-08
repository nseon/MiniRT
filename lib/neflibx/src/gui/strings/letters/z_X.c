/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_X.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:35:05 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/19 09:35:05 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/letters.h"
#include "draw.h"
#include "gui/gui.h"

void	tu_xu(t_image *img, char c, t_point pt, int32_t size)
{
	const char	tu_bits[14] = {0x3F, 0x2D, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00};
	const char	uu_bits[14] = {0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00};
	const char	vu_bits[14] = {0x33, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00};
	const char	wu_bits[14] = {0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00};
	const char	xu_bits[14] = {0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x00};

	if (c == 'T')
		draw_char(img, tu_bits, pt, size);
	else if (c == 'U')
		draw_char(img, uu_bits, pt, size);
	else if (c == 'V')
		draw_char(img, vu_bits, pt, size);
	else if (c == 'W')
		draw_char(img, wu_bits, pt, size);
	else if (c == 'X')
		draw_char(img, xu_bits, pt, size);
	else
		yu_2(img, c, pt, size);
}

void	ou_su(t_image *img, char c, t_point pt, int32_t size)
{
	const char	ou_bits[14] = {0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00};
	const char	pu_bits[14] = {0x3F, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x0F, 0x00};
	const char	qu_bits[14] = {0x1E, 0x33, 0x33, 0x33, 0x3B, 0x1E, 0x38, 0x00};
	const char	ru_bits[14] = {0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00};
	const char	su_bits[14] = {0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00};

	if (c == 'O')
		draw_char(img, ou_bits, pt, size);
	else if (c == 'P')
		draw_char(img, pu_bits, pt, size);
	else if (c == 'Q')
		draw_char(img, qu_bits, pt, size);
	else if (c == 'R')
		draw_char(img, ru_bits, pt, size);
	else if (c == 'S')
		draw_char(img, su_bits, pt, size);
	else
		tu_xu(img, c, pt, size);
}

void	ju_nu(t_image *img, char c, t_point pt, int32_t size)
{
	const char	ju_bits[14] = {0x78, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E, 0x00};
	const char	ku_bits[14] = {0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00};
	const char	lu_bits[14] = {0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00};
	const char	mu_bits[14] = {0x63, 0x77, 0x7F, 0x7F, 0x6B, 0x63, 0x63, 0x00};
	const char	nu_bits[14] = {0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00};

	if (c == 'J')
		draw_char(img, ju_bits, pt, size);
	else if (c == 'K')
		draw_char(img, ku_bits, pt, size);
	else if (c == 'L')
		draw_char(img, lu_bits, pt, size);
	else if (c == 'M')
		draw_char(img, mu_bits, pt, size);
	else if (c == 'N')
		draw_char(img, nu_bits, pt, size);
	else
		ou_su(img, c, pt, size);
}

void	eu_iu(t_image *img, char c, t_point pt, int32_t size)
{
	const char	eu_bits[14] = {0x7F, 0x46, 0x16, 0x1E, 0x16, 0x46, 0x7F, 0x00};
	const char	fu_bits[14] = {0x7F, 0x46, 0x16, 0x1E, 0x16, 0x06, 0x0F, 0x00};
	const char	gu_bits[14] = {0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00};
	const char	hu_bits[14] = {0x33, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x33, 0x00};
	const char	iu_bits[14] = {0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00};

	if (c == 'E')
		draw_char(img, eu_bits, pt, size);
	else if (c == 'F')
		draw_char(img, fu_bits, pt, size);
	else if (c == 'G')
		draw_char(img, gu_bits, pt, size);
	else if (c == 'H')
		draw_char(img, hu_bits, pt, size);
	else if (c == 'I')
		draw_char(img, iu_bits, pt, size);
	else
		ju_nu(img, c, pt, size);
}

void	z_du(t_image *img, char c, t_point pt, int32_t size)
{
	const char	z_bits[14] = {0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00};
	const char	au_bits[14] = {0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00};
	const char	bu_bits[14] = {0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00};
	const char	cu_bits[14] = {0x3C, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3C, 0x00};
	const char	du_bits[14] = {0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00};

	if (c == 'z')
		draw_char(img, z_bits, pt, size);
	else if (c == 'A')
		draw_char(img, au_bits, pt, size);
	else if (c == 'B')
		draw_char(img, bu_bits, pt, size);
	else if (c == 'C')
		draw_char(img, cu_bits, pt, size);
	else if (c == 'D')
		draw_char(img, du_bits, pt, size);
	else
		eu_iu(img, c, pt, size);
}
