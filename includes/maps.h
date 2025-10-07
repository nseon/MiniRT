/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:42:41 by nseon             #+#    #+#             */
/*   Updated: 2025/10/06 09:56:34 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# ifdef BONUS
#  include <stdio.h>
#  include <png.h>
# endif
# include <stdint.h>

# include "fcolors.h"
# include "tuple.h"
# include "uv.h"

typedef struct s_map_infos
{
	int32_t	h;
	int32_t	w;
	uint8_t	channels;
}	t_map_infos;

typedef struct s_map
{
	uint8_t			**data;
	t_map_infos		infos;
}	t_map;

typedef struct s_tbn
{
	t_tuple	t;
	t_tuple	b;
	t_tuple	n;
}	t_tbn;

void		free_map(uint8_t **image, int32_t nb_lines);
int32_t		destroy_all(FILE *file, png_structp *png, png_infop *info);
uint8_t		**alloc_map(png_structp *png, png_infop *info);
t_tuple		map_to_vct(t_map *map, t_uv uv);
t_fcolor	map_to_fcol(t_map *map, t_uv uv);
double		map_to_ao(t_map *map, t_uv uv);
int8_t		map_to_height(t_map *map, t_uv uv);

int32_t		parse_png_map(char *mapname, uint8_t ***map, t_map_infos *data);
t_tuple		pertube_normal(t_tuple ojb_norm, t_tuple map_norm);

#endif
