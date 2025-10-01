/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_png.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:57:28 by nseon             #+#    #+#             */
/*   Updated: 2025/10/01 17:52:16 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <png.h>

#include "tuple.h"
#include "normals_maps.h"

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

int32_t	parse_map(const char *mapname, png_bytepp *map, t_data *data)
{
	FILE 		*file;
	png_structp	png;
	png_infop	info;

	if (open_png(mapname, &png, &info, &file) == -1)
		return (-1);
	data->height = png_get_image_height(png, info);
	data->width = png_get_image_width(png, info);
	data->channels = png_get_channels(png, info);
	*map = alloc_map(&png, &info);
	if (!*map)
		return (destroy_all(file, &png, &info));
	if (setjmp(png_jmpbuf(png)))
	{
		free_map(*map, data->height);
		png_destroy_info_struct(png, &info);
		png_destroy_read_struct(&png, NULL, NULL);
		fclose(file);
		return (-1);
	}
	png_read_image(png, *map);
	destroy_all(file, &png, &info);
	return (0);
}

t_tuple rgb_to_vct(png_bytepp map, t_data data, int32_t x, int32_t y)
{
	t_tuple	vct;

	vct.x = map[y][x * data.channels] / 255;
	vct.y = map[y][x * data.channels + 1] / 255;
	vct.z = map[y][x * data.channels + 2] / 255;
	return (tp_normalize(vct));
}

int32_t	create_normal_map(const char *mapname, t_tuple **normal_map)
{
	t_data		data;
	png_bytepp	map;
	int32_t		x;
	int32_t		y;

	y = -1;
	if (parse_map(mapname, &map, &data) == -1)
		return (-1);
	normal_map = malloc(sizeof(t_tuple) * data.height * data.width);
	if (!normal_map || data.channels < 3)
	{
		free_map(map, data.height);
		if (data.channels < 3)
			printf("Invalid normal map\n");
		return (-1);
	}
	while (++y < data.height)
	{
		x = -1;
		while (++x < data.width)
			*normal_map[y * data.width + x] = rgb_to_vct(map, data, x, y);
	}
	return (0);
}
