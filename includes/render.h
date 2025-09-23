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

# include <stdbool.h>
# include <stdint.h>

# include "fcolors.h"
# include "neflibx.h"
# include "objects.h"
# include "points.h"
# include "tuple.h"
# include "world.h"

# define T_MAX 3.402823466e+38
# define T_MIN 0.01
# define BACKGROUND_COLOR 0x000001
# define RAY_NBR 100000

typedef struct s_amb_light
{
	double		i;
	t_fcolor	col;
}	t_amb_light;

typedef struct s_ss
{
	int32_t		sample_num;
	int32_t		max_sample;
	t_rgb96_t	*samples;
}	t_ss;

typedef struct s_gctx
{
	t_world		w;
	t_fcolor	*frame;
	t_fcolor	*buf_frame;
	int32_t		frac;
	t_ss		ss;
	float		o_r;
	float		o_d;
	float		bil_size;
	int32_t		bil_passes;
	int32_t		bil_max;
}	t_gctx;

typedef struct s_mouse
{
	bool		focus;
	t_point2	axes;
}	t_mouse;

typedef struct s_ctx
{
	t_window	win;
	t_image		img;
	t_gctx		gctx;
	int32_t		error;
	int32_t		file;
	t_mouse		mouse;
	bool		parsing;
	bool		render;
}	t_ctx;

void		compute_matrices(t_camera *cam, t_obj *objs);
void		compute_cam_matrice(t_camera *cam);
void		compute_obj_matrice(t_obj *o);
void		render(t_gctx *gctx, t_world *w);
t_tuple		random_bounce(t_tuple ojb_norm);
int32_t		init_ss(t_gctx *gctx, int32_t max_rays);
t_fcolor	get_ss_color(t_ss *ss, int32_t x, int32_t y);
void		add_ss_frame(t_ss *ss, t_fcolor *frame);
void		clear_ss(t_ss *ss);
void		bilateral_filter(t_gctx *gctx);

#endif
