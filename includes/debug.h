/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:21:27 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/24 12:21:27 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# define BOLD "\e[1m"
# define RESET "\e[m"

# define COLOR "%1$#.6x (%2$d, %3$d, %4$d) \x1b[48;2;%2$d;%3$d;%4$dm   \x1b[0m"
# define POS "(x: %.2f, y: %.2f, z: %.2f)"

# include "render.h"

#endif
