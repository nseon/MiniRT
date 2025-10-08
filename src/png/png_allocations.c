/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_allocations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:41:29 by nseon             #+#    #+#             */
/*   Updated: 2025/10/08 13:31:38 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS

# include <png.h>
# include <stdint.h>
# include <stdlib.h>

void	free_map(uint8_t **image, int32_t nb_lines)
{
	if (!image)
		return ;
	while (--nb_lines >= 0)
		free(image[nb_lines]);
	free(image);
}

int32_t	destroy_all(FILE *file, png_structp *png, png_infop *info)
{
	png_destroy_info_struct(*png, info);
	png_destroy_read_struct(png, NULL, NULL);
	fclose(file);
	return (-1);
}

png_bytepp	alloc_map(png_structp *png, png_infop *info)
{
	png_bytepp		image;
	int32_t			y;
	int32_t const	height = png_get_image_height(*png, *info);

	y = -1;
	image = malloc(sizeof(png_bytep) * height);
	if (!image)
		return (NULL);
	while (++y < height)
	{
		image[y] = malloc(png_get_rowbytes(*png, *info));
		if (!image[y])
		{
			free_map(image, y);
			return (NULL);
		}
	}
	return (image);
}

#endif
