/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:21:43 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/13 14:21:43 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

t_material const	g_default_mat = {.col = {1, 1, 1}, .diffuse = 0.9,
	.specular = 0.9, .shine = 200};

t_material	material(void)
{
	return (g_default_mat);
}
