/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersampling.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:57:56 by nseon             #+#    #+#             */
/*   Updated: 2025/08/27 16:12:18 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERSAMPLING_H
# define SUPERSAMPLING_H

# include "render.h"

float	frandom(uint8_t const random[RAY_NBR], int min, int max);
void	add_rgb96_t(t_rgb96_t *comps, uint32_t color);
int32_t	get_mixed_color(t_rgb96_t comps, int div);
t_tuple	random_vec(uint8_t const random[RAY_NBR]);

#endif
