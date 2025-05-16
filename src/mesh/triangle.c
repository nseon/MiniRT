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
#include "libft.h"
#include "errors.h"

t_triangle	*get_triangle(t_mesh *mesh, uint32_t i)
{
	return ((t_triangle *)&mesh->vertices[i * 3]);
}

t_triangle	new_triangle(t_point3 v1, t_point3 v2, t_point3 v3)
{
	return ((t_triangle){v1, v2, v3});
}

int8_t	add_triangle(t_mesh *mesh, t_triangle *triangle)
{
	vct_add(&mesh->vertices, (t_point3 *)triangle);
	vct_add(&mesh->vertices, (t_point3 *)triangle + 1);
	vct_add(&mesh->vertices, (t_point3 *)triangle + 2);
	return (SUCCESS);
}
