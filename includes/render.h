/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:10:47 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/09 16:34:37 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdint.h>
# include <stdbool.h>

# include "tuple.h"
# include "points.h"
# include "objects.h"
# include "neflibx.h"
# include "fcolors.h"
# include "matrix.h"
#include "world.h"

# define T_MAX 3.402823466e+38
# define T_MIN 0.01
# define BACKGROUND_COLOR 0x000001
# define RAY_NBR 100000

typedef struct s_amb_light
{
	double	i;
	t_fcolor	col;
}	t_amb_light;

typedef struct s_ss
{
	int32_t		rays;
	t_rgb96_t	*color_px;
}	t_ss;

typedef struct s_gctx
{
	t_world		w;
	t_camera	cam;
	t_ss		ss;
}	t_gctx;

typedef	struct s_mouse
{
	bool		focus;
	t_point2	axes;
}	t_mouse;


typedef struct s_ctx
{
	t_window		win;
	t_image			img;
	t_gctx			gctx;
	int32_t			error;
	int32_t			file;
	t_mouse			mouse;
	bool parsing;
	bool render;
}	t_ctx;

void		compute_matrices(t_camera *cam, t_obj *objs);
void		compute_cam_matrice(t_camera *cam);
void		compute_obj_matrice(t_obj *o);
uint32_t	get_pixel_color(t_image *image, int x, int y);
t_image		*render(t_ctx *ctx, t_camera *cam, t_world *world);
t_tuple		random_bounce(t_tuple ojb_norm);
int32_t		init_ss(t_ctx *ctx);
int32_t		get_ss_color(t_ss *ss, int32_t x, int32_t y);
void		add_ss_color(t_ss *ss, t_fcolor color, int32_t x, int32_t y);
void		clear_ss(t_ss *ss);

#endif
