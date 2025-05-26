/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:21:56 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/16 17:21:56 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "mesh.h"
# include "vector3.h"

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

typedef struct s_sphere
{
	t_point3	pos;
	float		radius;
	int32_t		color;
	int32_t		specular;
}	t_sphere;

typedef struct s_obj
{
	t_obj_type	type;
	t_vec3		pos;
	t_vec3		ori;
	int32_t		color;
	int32_t		specular;
	float		w;
	float		l;
	float		h;
}	t_obj;

t_mesh	*new_cube(t_point3 pos, t_point3 dim);

#endif
