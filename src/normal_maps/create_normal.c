/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 08:42:09 by nseon             #+#    #+#             */
/*   Updated: 2025/10/03 09:15:45 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdint.h"
#include "png.h"
#include "tuple.h"
#include "normal_maps.h"
#include "stdlib.h"

t_tuple	rgb_to_vct(png_bytepp map, t_data data, int32_t x, int32_t y)
{
	return (tp_normalize(vector((map[y][x * data.channels] / 255.0) * 2 - 1
			, (map[y][x * data.channels + 1] / 255.0) * 2 - 1
		, (map[y][x * data.channels + 2] / 255.0) * 2 - 1)));
}

int32_t	create_normal_map(const char *mapname, t_normal_map *map)
{
	png_bytepp	png_map;
	int32_t		x;
	int32_t		y;

	y = -1;
	if (parse_png_map(mapname, &png_map, &map->data) == -1)
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
