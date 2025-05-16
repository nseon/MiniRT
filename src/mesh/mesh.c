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
#include "errors.h"
#include "libft.h"

int8_t	new_mesh(t_mesh	*mesh)
{
	mesh->vertices = vct_create(sizeof (t_point3), NULL, 0);
	if (!mesh->vertices)
		return (FATAL);
	return (SUCCESS);
}

// Using free_vct for performance, use vct_destroy if custom deletion is needed
int8_t	delete_mesh(t_mesh	*mesh)
{
	free_vct(mesh->vertices);
	return (SUCCESS);
}

uint32_t	mesh_tri_count(t_mesh *mesh)
{
	return (vct_size(mesh->vertices) / 3);
}
