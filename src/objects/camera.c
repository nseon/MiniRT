/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:56:34 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/18 14:56:34 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "objects.h"

t_camera	camera(double hsize, double vsize, double fov)
{
	t_camera		cam;
	double const	half = tan(fov / 2);
	double const	aspect = hsize / vsize;

	cam.hsize = hsize;
	cam.vsize = vsize;
	cam.fov = fov;
	cam.y_rot = 0;
	cam.x_rot = 0;
	mtx4_dup(g_identity_matrix, cam.transform);
	mtx4_dup(g_identity_matrix, cam.inverse);
	if (aspect >= 1)
	{
		cam.half_width = half;
		cam.half_height = half / aspect;
	}
	else
	{
		cam.half_width = half * aspect;
		cam.half_height = half;
	}
	cam.pos = point(0, 0, 0);
	cam.orient = vector(0, 0, 1);
	cam.pixel_size = cam.half_width * 2 / cam.hsize;
	return (cam);
}

void	set_cam_transform(t_camera *cam, t_mtx4 transf)
{
	mtx4_dup(transf, cam->transform);
	mtx4_inverse2(cam->transform, cam->inverse);
}

void	mul_cam_transform(t_camera *cam, t_mtx4 transf)
{
	mtx_mul2(cam->transform, transf);
	mtx4_inverse2(cam->transform, cam->inverse);
}
