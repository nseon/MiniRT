/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:03:27 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/15 15:03:27 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include <stdint.h>
# include <stddef.h>

typedef struct s_point3
{
	float	x;
	float	y;
	float	z;
}	t_point3;

typedef t_point3	*t_point3_vct;

typedef struct s_triangle
{
	t_point3	vertices[3];
}	t_triangle;

typedef struct s_mesh
{
	t_point3_vct	vertices;
}	t_mesh;

int8_t		new_mesh(t_mesh	*mesh);
size_t		mesh_tri_count(t_mesh *mesh);
int8_t		delete_mesh(t_mesh *mesh);
int8_t		add_triangle(t_mesh *mesh, t_triangle *triangle);
t_triangle	new_triangle(t_point3 v1, t_point3 v2, t_point3 v3);
t_triangle	*get_triangle(t_mesh *mesh, size_t i);

#endif
