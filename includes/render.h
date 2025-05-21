/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:10:47 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/21 12:11:09 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "vector3.h"
# include "points.h"
# include "window.h"
# include "image.h"

typedef struct s_vieuport
{
	float	vw;
	float	vh;
	float	d;
}	t_vieuport;

typedef struct s_camera
{
	t_point3	pos;
	t_vec3		orient;
	t_vieuport	vp;
}	t_camera;

typedef struct s_sphere
{
	t_point3	pos;
	float		radius;
}	t_sphere;

typedef	struct s_ctx
{
	t_camera	cam;
	t_image		img;
	t_window	win;
	t_sphere	*spheres;
}	t_ctx;

void	render(t_ctx ctx);


#endif
