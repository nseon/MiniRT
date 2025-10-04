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

#include "fcolors.h"
#include "stdint.h"
#include "png.h"
#include "tuple.h"
#include "maps.h"
#include "stdlib.h"

t_tuple	map_to_vct(t_map *map, t_uv uv)
{
	int32_t const	x = uv.u * map->infos.w;
	int32_t const	y = uv.v * map->infos.h;

	return (tp_normalize(vector((map->data[y][x * map->infos.channels] / 255.0) * 2 - 1
			, (map->data[y][x * map->infos.channels + 1] / 255.0) * 2 - 1
		, (map->data[y][x * map->infos.channels + 2] / 255.0) * 2 - 1)));
}

t_fcolor	map_to_fcol(t_map *map, t_uv uv)
{
	int32_t const	x = uv.u * map->infos.w;
	int32_t const	y = uv.v * map->infos.h;

	return (fcolor((map->data[y][x * map->infos.channels] / 255.0)
			, (map->data[y][x * map->infos.channels + 1] / 255.0)
		, (map->data[y][x * map->infos.channels + 2] / 255.0)));
}

double	map_to_ao(t_map *map, t_uv uv)
{
	int32_t const	x = uv.u * map->infos.w;
	int32_t const	y = uv.v * map->infos.h;

	return (map->data[y][x * map->infos.channels] / 255.0);
}
