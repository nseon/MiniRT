/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:57:28 by nseon             #+#    #+#             */
/*   Updated: 2025/09/29 15:43:06 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>

// #ifdef BONUS
# include <png.h>
// #endif

int32_t    open_map(const char *mapname)
{
    const FILE *file = fopen(mapname, "rb");
    png_structp png;
    
    if (!file)
        return (-1);
    png = png_create_read_struct()
    
}
