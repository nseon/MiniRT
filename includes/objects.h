/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:21:56 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 13:01:26 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "colors.h"
# include "fcolors.h"
# include "materials.h"
# include "tuple.h"
# include "matrix.h"

typedef enum e_light_type
{
	POINT,
	DIR,
	AMB
}	t_light_type;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_light
{
	t_light_type	type;
	t_tuple			pos;
	t_fcolor		i;
}	t_light;

typedef struct s_obj
{
	t_obj_type	type;
	uint32_t	uid;
	t_mtx4		transform;
	t_mtx4		inv_transform;
	t_material	mat;
}	t_obj;

typedef struct s_camera
{
	double	hsize;
	double	vsize;
	double	fov;
	double	pixel_size;
	double	half_height;
	double	half_width;
	t_mtx4	transform;
	t_mtx4	inverse;
}	t_camera;

uint32_t	get_uid(void);
t_camera	camera(double hsize, double vsize, double fov);
t_obj		sphere(void);
void		mul_transform(t_obj *o, t_mtx4 transf);
void		set_transform(t_obj *o, t_mtx4 transf);
t_light		light(t_tuple pos, t_fcolor intensity, t_light_type type);
void		set_cam_transform(t_camera *cam, t_mtx4 transf);
void		mul_cam_transform(t_camera *cam, t_mtx4 transf);

#endif
