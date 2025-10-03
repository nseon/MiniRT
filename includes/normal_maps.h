/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_maps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:42:41 by nseon             #+#    #+#             */
/*   Updated: 2025/10/03 09:15:03 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_MAPS_H
# define NORMAL_MAPS_H

# include <png.h>
# include <stdint.h>

# include "tuple.h"

typedef struct s_data
{
	int32_t		height;
	int32_t		width;
	png_byte	channels;
}	t_data;

typedef struct s_normal_map
{
	t_tuple	*normal;
	t_data	data;
}	t_normal_map;

typedef struct s_tbn
{
	t_tuple	t;
	t_tuple	b;
	t_tuple	n;
}	t_tbn;

void		free_map(png_bytepp image, int32_t nb_lines);
int32_t		destroy_all(FILE *file, png_structp *png, png_infop *info);
png_bytepp	alloc_map(png_structp *png, png_infop *info);
int32_t		create_normal_map(const char *mapname, t_normal_map *map);
int32_t		parse_png_map(const char *mapname, png_bytepp *map, t_data *data);
t_tuple		pertube_normal(t_tuple ojb_norm, t_tuple map_norm);

#endif