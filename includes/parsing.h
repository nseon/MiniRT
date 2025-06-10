/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:24:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 13:24:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define FILENAME "Map filename:"
# define LOADED "Map loaded !"
# define WHITESPACES "\t\n\v\f\r "

# ifdef BONUS
# define ELEMENTS "a lpt ldir C sp pl cy"
#  define AMBI_LIGHT "a"
#  define PT_LIGHT "lpt"
#  define DIR_LIGHT "ldir"
#  define CAMERA "C"
#  define SPHERE "sp"
#  define PLANE "pl"
#  define CYLINDER "cy"
# else
#  define ELEMENTS "A L C sp pl cy"
#  define AMBI_LIGHT "A"
#  define PT_LIGHT "L"
#  define CAMERA "C"
#  define SPHERE "sp"
#  define PLANE "pl"
#  define CYLINDER "cy"
# endif

# include "minirt.h"

void	filename_input_cb(char *str, void *p);
int8_t	parse(t_ctx *ctx);
int8_t	parse_map(t_ctx *ctx);

#endif
