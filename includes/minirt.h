/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/03 14:02:09 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "neflibx.h"
# include "render.h"
# include "inputs.h"

typedef struct s_ctx
{
	t_image			img;
	bool			render;
	t_window		win;
	t_mouse			mouse;
	t_graphic_ctx	gctx;
	int32_t			fd;
	uint8_t			random[2 * RAY_NBR];
}	t_ctx;

#endif
