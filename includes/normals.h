/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:11:12 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/12 18:11:12 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_NORMALS_H
# define MINIRT_NORMALS_H

#include "objects.h"

t_tuple	obj_normal(t_obj *o, t_tuple pt);
t_tuple	sphere_normal(t_tuple pt);
t_tuple	plane_normal(t_tuple pt);
t_tuple	cube_normal(t_tuple pt);
t_tuple	cone_normal(t_obj *o, t_tuple pt);
t_tuple	cylinder_normal(t_obj *o, t_tuple pt);

#endif
