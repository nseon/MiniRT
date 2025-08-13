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

#include "colors.h"
# include "fcolors.h"
#include "materials.h"
# include "tuple.h"
# include "matrix.h"

typedef enum e_light_type
{
	POINT,
	DIR
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
	t_fcolor		col; // deprecated
}	t_light;

typedef struct s_obj
{
	t_obj_type	type;
	uint32_t	uid;
	t_tuple		pos; // deprecated
	t_tuple		ori; // deprecated
	t_mtx4		transform;
	t_mtx4		inv_transform;
	t_material	mat;
	t_fcolor	col; // deprecated
	float		w; // deprecated
	float		l; // deprecated
	float		h; // deprecated
}	t_obj;

t_obj	sphere(void);
void	set_transform(t_obj *o, t_mtx4 transf);
t_light	light(t_tuple pos, t_fcolor intensity, t_light_type type);

#endif
