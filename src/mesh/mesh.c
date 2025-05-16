/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:08:32 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/15 16:08:32 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "neflibx.h"

t_mesh	*new_mesh(void)
{
	t_mesh	*mesh;

	mesh = malloc(sizeof (t_mesh));
	mesh->vertices = vct_create(sizeof (t_point3), NULL, 0);
	if (!mesh->vertices)
		return (NULL);
	mesh->v_indexes = vct_create(sizeof (uint32_t), NULL, 0);
	if (!mesh->v_indexes)
	{
		free_vct(mesh->vertices);
		return (NULL);
	}
	return (mesh);
}

// Using free_vct for performance, use vct_destroy if custom deletion is needed
int8_t	delete_mesh(t_mesh	*mesh)
{
	printf("%zu + %zu\n", vct_size(mesh->vertices) * sizeof (t_point3), vct_size(mesh->v_indexes) * sizeof (uint32_t));
	free_vct(mesh->vertices);
	free_vct(mesh->v_indexes);
	free(mesh);
	return (SUCCESS);
}

uint32_t	mesh_tri_count(t_mesh *mesh)
{
	return (vct_size(mesh->v_indexes) / 3);
}
