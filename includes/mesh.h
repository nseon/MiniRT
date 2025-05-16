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

typedef uint32_t	*t_uint32_vct;

typedef struct s_point3
{
	float	x;
	float	y;
	float	z;
}	t_point3;

typedef t_point3	*t_point3_vct;

typedef struct s_triangle
{
	t_point3	*vertices[3];
}	t_triangle;

typedef struct s_mesh
{
	t_point3_vct	vertices;
	t_uint32_vct	v_indexes;
	t_point3		pos;
	t_point3		dim;
}	t_mesh;

t_mesh			*new_mesh(void);
uint32_t		mesh_tri_count(t_mesh *mesh);
int8_t			delete_mesh(t_mesh *mesh);
int8_t			add_triangle(t_mesh *mesh, t_triangle triangle);
int8_t			add_itriangle(t_mesh *mesh, uint32_t idx[3]);
t_triangle		get_triangle(t_mesh *mesh, uint32_t i);

#endif
