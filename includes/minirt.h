/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/23 18:37:03 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "neflibx.h"
# include "render.h"
# include "world.h"

# define WIN_W 1080
# define WIN_H 600

typedef struct s_gctx
{
	t_world		w;
	t_camera	cam;
}	t_gctx;

typedef struct s_ctx
{
	t_window		win;
	t_image			img;
	t_gctx			gctx;
	int32_t			error;
	int32_t			file;
	int32_t			fd;
	uint8_t			random[2 * RAY_NBR];
	bool parsing;
	bool render;
}	t_ctx;

int8_t	init_gui(t_ctx *ctx);
void	test_render(t_ctx * const ctx);
void	keyevent(int keycode, void *p);

#endif
