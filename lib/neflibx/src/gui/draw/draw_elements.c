/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:55:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/10 11:55:28 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui_draw.h"
#include "draw.h"
#include "colors.h"
#include "libft.h"

void	draw_border(t_guielem *e, uint32_t color, int32_t size, int32_t shift)
{
	draw_rectangle(e->img, point_s(e->x - shift - size + 1, e->y - size
			- shift + 1, color), e->w + shift * 2 + (size - 1) * 2, size);
	draw_rectangle(e->img, point_s(e->x - shift - size + 1, e->y + e->h
			+ shift - 1, color), e->w + shift * 2 + (size - 1) * 2, size);
	draw_rectangle(e->img, point_s(e->x - size - shift + 1,
			e->y - shift, color), size, e->h + shift * 2);
	draw_rectangle(e->img, point_s(e->x + e->w + shift - 1, e->y - shift,
			color), size, e->h + shift * 2);
}

void	draw_gui_aa(t_guielem *e, t_image *img)
{
	int				size;
	const uint32_t	aa_col = color_mix(e->color, 0xffffff, 32) & 0x00FFFFFF;

	size = (e->w + e->h) * AA_MULTIPLIER;
	if (size < 1)
		size = 1;
	e->img = img;
	draw_border(e, aa_col, size, 0 - size);
}

void	draw_gui_active(t_guielem *e, t_image *img)
{
	int	size;
	int	aa_size;

	aa_size = (e->w + e->h) * AA_MULTIPLIER;
	size = (e->w + e->h) * SHADOW_MULTIPLIER;
	if (size < 1)
		size = 1;
	e->img = img;
	draw_border(e, SHADOW_COLOR, size, 0 - size - aa_size);
}

void	draw_el_box(t_guielem *el, t_image *img)
{
	if (el->hover && !el->focus)
		draw_rectangle(img, point_s(el->x, el->y,
				color_mix(el->color, 0xffffff, 16)), el->w, el->h);
	else
		draw_rectangle(img, point_s(el->x, el->y, el->color), el->w, el->h);
	draw_gui_aa(el, img);
	if (el->focus)
		draw_gui_active(el, img);
}
