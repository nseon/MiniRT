/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:10:47 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/23 15:41:16 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "vector3.h"
# include "points.h"
# include "window.h"
# include "image.h"
# include "inputs.h"

# define T_MAX 3.402823466e+38
# define T_MIN 1
# define BACKGROUND_COLOR 0x000001

typedef enum e_light_type
{
	POINT,
	DIR
}	t_light_type;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

typedef struct s_vieuport
{
	float	vw;
	float	vh;
	float	d;
}	t_vieuport;

typedef struct s_camera
{
	t_point3	pos;
	t_vec3		orient;
	t_vieuport	vp;
}	t_camera;

typedef struct s_sphere
{
	t_point3	pos;
	float		radius;
	int32_t		color;
	int32_t		specular;
}	t_sphere;

typedef struct s_light
{
	t_light_type	type;
	t_point3		pos;
	float			i;
}	t_light;

typedef struct s_amb_light
{
	float	i;
}	t_amb_light;

typedef struct s_ren_calc
{
	t_point3	p;
	t_vec3		n;
	t_vec3		d;
	t_vec3		v;
	t_vec3		r;
	t_vec3		l;
	float		s;
}	t_ren_calc;

typedef struct s_ctx
{
	t_camera	cam;
	t_image		img;
	t_window	win;
	t_mouse		mouse;
	t_sphere	*spheres;
	t_light		*lights;
	bool		lights_off;
	t_amb_light	amb_light;
}	t_ctx;

typedef struct s_obj
{
	int		type;

}	t_obj;

void	render(t_ctx ctx);
float	get_light(t_ctx ctx, t_ren_calc ren);

#endif
