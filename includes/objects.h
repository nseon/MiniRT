/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:21:56 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/18 09:53:29 by nseon            ###   ########.fr       */
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
	uint32_t	color;
	int32_t		specular;
	float		reflective;
}	t_sphere;

typedef	struct s_plane
{
	t_point3	pos;
	t_vec3		vct;
	uint32_t	color;
}	t_plane;

typedef struct s_obj
{
	t_obj_type	type;
	t_vec3		pos;
	t_vec3		ori;
	uint32_t		color;
	int32_t		specular;
	float		w;
	float		l;
	float		h;
}	t_obj;

t_mesh	*new_cube(t_point3 pos, t_point3 dim);

#endif
