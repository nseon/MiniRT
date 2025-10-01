/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:57:28 by nseon             #+#    #+#             */
/*   Updated: 2025/10/01 15:55:05 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// #ifdef BONUS
#include <png.h>
// #endif

int32_t	init_png_struct(png_structp *png, png_infop *info)
{
	*png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!*png)
		return (-1);
	*info = png_create_info_struct(*png);
	if (!info)
	{
		png_destroy_read_struct(png, NULL, NULL);
		return (-1);
	}
	return (0);
}

int32_t	open_png(const char *mapname, png_structp *png, png_infop *info, FILE **file)
{
	*file = fopen(mapname, "rb");
	if (!file)
		return (-1);
	if (init_png_struct(png, info) == -1)
	{
		fclose(*file);
		return (-1);
	}
	if (setjmp(png_jmpbuf(*png)))
	{
		png_destroy_info_struct(*png, info);
		png_destroy_read_struct(png, NULL, NULL);
		fclose(*file);
		return (-1);
	}
	png_init_io(*png, *file);
	png_read_info(*png, *info);
	return (0);
}

void	free_map(png_bytepp image, int32_t nb_lines)
{
	while (--nb_lines >= 0)
		free(image[nb_lines]);
	free(image);
}

png_bytepp	alloc_map(png_structp *png, png_infop *info)
{
	png_bytepp		image;
	int32_t			y;
	int32_t	const	height = png_get_image_height(*png, *info);

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

int32_t	parse_map(const char *mapname)
{
	FILE 		*file;
	png_structp	png;
	png_infop	info;
	png_bytepp	map;

	if (open_png(mapname, &png, &info, &file) == -1)
		return (-1);
	map = alloc_map(&png, &info);
	if (!map)
	{
		png_destroy_info_struct(png, &info);
		png_destroy_read_struct(&png, NULL, NULL);
		fclose(file);
		return (-1);
	}
	if (setjmp(png_jmpbuf(png)))
	{
		free_map(map, png_get_image_height(png, info));
		png_destroy_info_struct(png, &info);
		png_destroy_read_struct(&png, NULL, NULL);
		fclose(file);
		return (-1);
	}
	png_read_image(png, map);
	free_map(map, png_get_image_height(png, info));
	png_destroy_info_struct(png, &info);
	png_destroy_read_struct(&png, NULL, NULL);
	fclose(file);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	parse_map(argv[1]);
	return (0);
}
