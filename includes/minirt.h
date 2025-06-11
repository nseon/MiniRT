/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 14:32:21 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "neflibx.h"
# include "render.h"
# include "inputs.h"

# define W_WIDTH 1920
# define W_HEIGHT 1080

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
