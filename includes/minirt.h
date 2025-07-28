/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/28 14:44:31 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "neflibx.h"
# include "render.h"
# include "inputs.h"

# define WIN_W 1080
# define WIN_H 600

typedef struct s_ctx
{
	t_image			img;
	bool			render;
	bool			parsing;
	int32_t			error;
	int32_t			file;
	t_window		win;
	t_graphic_ctx	gctx;
	int32_t			fd;
	uint8_t			random[2 * RAY_NBR];
}	t_ctx;

int8_t	init_gui(t_ctx *ctx);

#endif
