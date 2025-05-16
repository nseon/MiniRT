/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:05:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/15 15:05:14 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include "neflibx.h"
#include "errors.h"

t_triangle	get_triangle(t_mesh *mesh, uint32_t i)
{
	return ((t_triangle){mesh->vertices + mesh->v_indexes[3 * i],
		mesh->vertices + mesh->v_indexes[3 * i + 1],
		mesh->vertices + mesh->v_indexes[3 * i + 2]});
}

int8_t	add_triangle(t_mesh *mesh, t_triangle triangle)
{
	const size_t	v_size = vct_size(mesh->vertices);

	vct_add(&mesh->vertices, triangle.vertices[0]);
	vct_add(&mesh->vertices, triangle.vertices[1]);
	vct_add(&mesh->vertices, triangle.vertices[2]);
	vct_add(&mesh->v_indexes, &(uint32_t){v_size});
	vct_add(&mesh->v_indexes, &(uint32_t){v_size + 1});
	vct_add(&mesh->v_indexes, &(uint32_t){v_size + 2});
	return (SUCCESS);
}

int8_t	add_itriangle(t_mesh *mesh, uint32_t idx[3])
{
	vct_add(&mesh->v_indexes, idx);
	vct_add(&mesh->v_indexes, idx + 1);
	vct_add(&mesh->v_indexes, idx + 2);
	return (SUCCESS);
}

