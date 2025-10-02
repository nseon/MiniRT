/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_png.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:57:28 by nseon             #+#    #+#             */
/*   Updated: 2025/10/02 10:50:21 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <png.h>

#include "tuple.h"
#include "normal_maps.h"

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

int32_t	parse_png_map(const char *mapname, png_bytepp *map, t_data *data)
{
	FILE		*file;
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

t_tuple	rgb_to_vct(png_bytepp map, t_data data, int32_t x, int32_t y)
{
	return (tp_normalize(vector(map[y][x * data.channels] / 255.0
			, map[y][x * data.channels + 1] / 255.0
		, map[y][x * data.channels + 2] / 255.0)));
}

int32_t	create_normal_map(const char *mapname, t_normal_map *map)
{
	png_bytepp	png_map;
	int32_t		x;
	int32_t		y;

	y = -1;
	if (!mapname || parse_png_map(mapname, &png_map, &map->data) == -1)
		return (-1);
	map->normal = malloc(sizeof(t_tuple) * map->data.height * map->data.width);
	if (!map->normal || map->data.channels < 3)
	{
		free_map(png_map, map->data.height);
		free(map->normal);
		if (map->data.channels < 3)
			printf("Invalid normal map\n");
		return (-1);
	}
	while (++y < map->data.height)
	{
		x = -1;
		while (++x < map->data.width)
			map->normal[y * map->data.width + x]
				= rgb_to_vct(png_map, map->data, x, y);
	}
	free_map(png_map, map->data.height);
	return (0);
}
