/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:22:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/19 17:22:21 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include "points.h"

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

float	v2_magnitude(t_vec2 vec);
t_vec2	get_vec2(t_point2 pt1, t_point2 pt2);
t_vec2	v2_add(t_point2 pt1, t_point2 pt2);

#endif
