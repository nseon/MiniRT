/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:22:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/07 10:00:55 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include "points.h"

typedef t_point3	t_vec3;

float	v3_magnitude(t_vec3 vec);
t_vec3	get_vec3(t_point3 pt1, t_point3 pt2);
t_vec3	v3_add(t_point3 pt1, t_point3 pt2);
t_vec3	v3_sub(t_point3 pt1, t_point3 pt2);
t_vec3	v3_multiply(t_vec3 vec, float k);
t_vec3	v3_normalize(t_vec3 vec);
float	v3_dotproduct(t_vec3 v1, t_vec3 v2);
t_vec3	v3_crossproduct(t_vec3 v1, t_vec3 v2);
void	v3_invert(t_vec3 *vec);

#endif
