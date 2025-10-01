/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals_maps.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:42:41 by nseon             #+#    #+#             */
/*   Updated: 2025/10/01 17:06:59 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	NORMALS_MAPS_H
# define	NORMALS_MAPS_H

# include <png.h>
# include <stdint.h>

typedef	struct s_data
{
	int32_t		height;
	int32_t		width;
	png_byte	channels;
}	t_data;

void		free_map(png_bytepp image, int32_t nb_lines);
int32_t		destroy_all(FILE *file, png_structp *png, png_infop *info);
png_bytepp	alloc_map(png_structp *png, png_infop *info);


#endif