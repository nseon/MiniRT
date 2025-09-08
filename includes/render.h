/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:10:47 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/19 10:47:15 by nseon            ###   ########.fr       */
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
# define RAY_NUM 2
# define RAY_NBR 100000

typedef struct s_amb_light
{
	double	i;
	t_fcolor	col;
}	t_amb_light;

typedef struct s_ren_calc
{
	t_point3	p;
	t_tuple		n;
	t_point3	o;
	t_tuple		d;
	t_tuple		v;
	t_tuple		r;
	t_tuple		l;
	int32_t		s;
}	t_ren_calc;

void		compute_matrices(t_camera *cam, t_obj *objs);
void		compute_cam_matrice(t_camera *cam);
void		compute_obj_matrice(t_obj *o);
uint32_t	get_pixel_color(t_image *image, int x, int y);
t_image		*render(t_image *img, t_camera *cam, t_world *world);

#endif
