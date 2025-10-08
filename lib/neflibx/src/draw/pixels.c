/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:56:01 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/14 14:56:01 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "mlx.h"
#include "image.h"
#include "draw.h"
#include "window.h"

void	put_pixel_img(t_image *image, t_point pt)
{
	uint32_t *const	dest = (uint32_t *)image->addr + pt.y * image->w
		+ pt.x;
	t_color const	col = (t_color)pt.color;

	if (pt.x < 0 || pt.x >= image->w || pt.y < 0 || pt.y >= image->h)
		return ;
	if (col.a != 0)
	{
		*dest = colorp(colorx(*dest, (float)col.a / 255),
				colorx(col.argb, 1 - (float)col.a / 255));
	}
	else
		*dest = pt.color;
}
