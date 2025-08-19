/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:08:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/24 13:08:28 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "parsing.h"
#include "debug.h"
#include "errors.h"

int32_t	parse_camera(char **split, t_camera *cam)
{
	int32_t	res;
	t_tuple	from;
	t_tuple	to;
	double	fov;
	t_mtx4	buf;

	res = parse_xyz(split[0], &from);
	if (res != SUCCESS)
		return (res);
	res = parse_normal(split[1], &to);
	to.w = 1;
	if (res != SUCCESS)
		return (res);
	res = parse_double(split[2], &fov);
	if (res != SUCCESS)
		return (res);
	if (fov > 180 || fov < 0)
		return (PARSE_INVAL_LINE);
	*cam = camera(WIN_W, WIN_H, fov * M_PI / 180);
	set_cam_transform(cam, mtx4_view(from, to, vector(0, 1, 0), buf));
	return (res);
}
