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

#include <stdio.h>
#include <unistd.h>

#include "parsing.h"
#include "debug.h"
#include "errors.h"

void	debug_camera(t_camera o)
{
	printf(BOLD "Camera" RESET "\n{\n");
	printf("\tFOV: %4.2f\n", o.fov);
	printf("}\n\n");
}

int32_t	parse_camera(char **split, t_camera *camera)
{
	int32_t	res;

	// res = parse_xyz(split[0], &camera->pos);
	// if (res != SUCCESS)
	// 	return (res);
	// res = parse_normal(split[1], &camera->orient);
	// if (res != SUCCESS)
	// 	return (res);
	// res = parse_float(split[2], &camera->fov);
	// if (res != SUCCESS)
	// 	return (res);
	if (camera->fov > 180 || camera->fov < 0)
	{
		ft_fprintf(STDERR_FILENO, PARSE_INVAL_FOV, (int)camera->fov);
		return (PARSE_INVAL_LINE);
	}
	// camera->vp.d = 1200;
	// camera->vp.vw = WIN_W;
	// camera->vp.vh = WIN_H;
	if (DEBUG)
		debug_camera(*camera);
	return (res);
}
