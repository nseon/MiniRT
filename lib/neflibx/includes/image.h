/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:12:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/12 17:12:16 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_window	t_window;

typedef struct s_image
{
	t_window	*win;
	void		*img;
	char		*addr;
	int32_t		w;
	int32_t		h;
	int32_t		bpp;
	int32_t		len;
	int32_t		endian;
}	t_image;

int8_t	create_image(t_image *image, int32_t w, int32_t h, t_window *window);
void	clear_image(t_image *image);
void	destroy_image(t_image *image);
void	put_img(t_image *img, int x, int y, bool gui);

#endif
