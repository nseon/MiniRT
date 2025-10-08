/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:58:29 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/12 16:58:29 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdint.h>

# include "image.h"

typedef struct s_point
{
	int32_t		x;
	int32_t		y;
	uint32_t	color;
}	t_point;

t_point	point_s(int32_t x, int32_t y, uint32_t color);
void	put_pixel_img(t_image *image, t_point pt);
void	draw_line(t_point pt1, t_point pt2, t_image *img);
void	draw_rectangle(t_image *img, t_point origin, int32_t w, int32_t h);
void	draw_str(t_image *img, const char *str, t_point pt, int32_t size);
void	draw_nstr(t_image *img, const char *str, t_point pt, int32_t sn[2]);
void	draw_char(t_image *img, const char *bits, t_point pt, int32_t size);
void	draw_background(t_image *img, uint32_t color);

#endif
