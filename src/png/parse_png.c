/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_png.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:57:28 by nseon             #+#    #+#             */
/*   Updated: 2025/10/07 10:51:45 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <png.h>

#include "tuple.h"
#include "maps.h"

int32_t	init_png_struct(png_structp *png, png_infop *info)
{
	*png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!*png)
		return (-1);
	*info = png_create_info_struct(*png);
	if (!*info)
	{
		png_destroy_read_struct(png, NULL, NULL);
		return (-1);
	}
	return (0);
}

int32_t	open_png(char *mapname, png_structp *png, png_infop *info, FILE **file)
{
	*file = fopen(mapname, "rb");
	if (!*file)
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

int32_t	parse_png_map(char *mapname, uint8_t ***map, t_map_infos *data)
{
	FILE		*file;
	png_structp	png;
	png_infop	info;

	if (!mapname || open_png(mapname, &png, &info, &file) == -1)
		return (-1);
	data->h = png_get_image_height(png, info);
	data->w = png_get_image_width(png, info);
	data->channels = png_get_channels(png, info);
	*map = alloc_map(&png, &info);
	if (!*map)
		return (destroy_all(file, &png, &info));
	if (setjmp(png_jmpbuf(png)))
	{
		free_map(*map, data->h);
		png_destroy_info_struct(png, &info);
		png_destroy_read_struct(&png, NULL, NULL);
		fclose(file);
		return (-1);
	}
	png_read_image(png, *map);
	destroy_all(file, &png, &info);
	return (0);
}
