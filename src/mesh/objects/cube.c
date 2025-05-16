/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:43:56 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/15 16:43:56 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "mesh.h"
#include "neflibx.h"

static int8_t	add_indexes(t_mesh *mesh)
{
	add_itriangle(mesh, (uint32_t[3]){0, 1, 2});
	add_itriangle(mesh, (uint32_t[3]){0, 2, 3});
	add_itriangle(mesh, (uint32_t[3]){1, 5, 6});
	add_itriangle(mesh, (uint32_t[3]){1, 6, 2});
	add_itriangle(mesh, (uint32_t[3]){5, 4, 7});
	add_itriangle(mesh, (uint32_t[3]){5, 7, 6});
	add_itriangle(mesh, (uint32_t[3]){4, 0, 3});
	add_itriangle(mesh, (uint32_t[3]){4, 3, 7});
	add_itriangle(mesh, (uint32_t[3]){0, 4, 5});
	add_itriangle(mesh, (uint32_t[3]){0, 5, 1});
	add_itriangle(mesh, (uint32_t[3]){3, 2, 6});
	add_itriangle(mesh, (uint32_t[3]){3, 6, 7});
	return (SUCCESS);
}

t_mesh	*new_cube(t_point3 pos, t_point3 dim)
{
	t_mesh	*mesh;

	mesh = new_mesh();
	if (!mesh)
		return (NULL);
	vct_add(&mesh->vertices, &(t_point3){pos.x, pos.y, pos.z});
	vct_add(&mesh->vertices, &(t_point3){pos.x + dim.x, pos.y, pos.z});
	vct_add(&mesh->vertices, &(t_point3){pos.x + dim.x, pos.y + dim.y, pos.z});
	vct_add(&mesh->vertices, &(t_point3){pos.x, pos.y + dim.y, pos.z});
	vct_add(&mesh->vertices, &(t_point3){pos.x, pos.y, pos.z + dim.z});
	vct_add(&mesh->vertices, &(t_point3){pos.x + dim.x, pos.y, pos.z + dim.z});
	vct_add(&mesh->vertices, &(t_point3){pos.x + dim.x, pos.y + dim.y, pos.z + dim.z});
	vct_add(&mesh->vertices, &(t_point3){pos.x, pos.y + dim.y, pos.z + dim.z});
	add_indexes(mesh);
	return (mesh);
}
