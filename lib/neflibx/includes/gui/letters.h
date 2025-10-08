/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:23:59 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/19 08:23:59 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LETTERS_H
# define LETTERS_H

# define CHAR_W 8
# define CHAR_H 8

# include "image.h"
# include "draw.h"

void			a_e(t_image *img, char c, t_point pt, int32_t size);
void			z_du(t_image *img, char c, t_point pt, int32_t size);
void			yu_2(t_image *img, char c, t_point pt, int32_t size);
void			sx_p(t_image *img, char c, t_point pt, int32_t size);
void			sc_p(t_image *img, char c, t_point pt, int32_t size);
unsigned char	get_shifted(unsigned char c);

#endif
