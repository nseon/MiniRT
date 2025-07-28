/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:21:56 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/28 14:44:37 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "colors.h"
# include "vector3.h"

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_obj
{
	t_obj_type	type;
	t_vec3		pos;
	t_vec3		ori;
	t_color		col;
	int32_t		specular;
	float		reflective;
	float		w;
	float		l;
	float		h;
}	t_obj;

#endif
