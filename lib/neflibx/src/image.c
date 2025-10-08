/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:49:18 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/06 10:49:18 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "image.h"
#include "libft.h"
#include "window.h"

int8_t	create_image(t_image *image, int32_t w, int32_t h, t_window *window)
{
	image->img = mlx_new_image(window->mlx, w, h);
	if (!image->img)
	{
		mlx_loop_end(window->mlx);
		return (-1);
	}
	image->w = w;
	image->h = h;
	image->win = window;
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->len, &image->endian);
	if (!image->addr)
	{
		mlx_destroy_image(window->mlx, image->img);
		mlx_loop_end(window->mlx);
		return (-1);
	}
	return (0);
}

void	put_img(t_image *img, int x, int y, bool gui)
{
	if (gui)
		gui_render(img);
	mlx_put_image_to_window(img->win->mlx, img->win->win, img->img, x, y);
}

void	clear_image(t_image *image)
{
	ft_bzero(image->addr, image->len * image->h);
}

void	destroy_image(t_image *image)
{
	mlx_destroy_image(image->win->mlx, image->img);
}
