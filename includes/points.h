/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:59:53 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/06 11:03:11 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTS_H
# define POINTS_H

typedef struct s_point2
{
	float	x;
	float	y;
}	t_point2;

typedef struct s_point3
{
	float	x;
	float	y;
	float	z;
}	t_point3;

float	get_distance(t_point3 a, t_point3 b);

#endif
