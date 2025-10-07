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

t_material const	g_default_mat = {.col = {1, 1, 1}, .diffuse = 0.8,
	.specular = 0.9, .reflective = 0.0, .shine = 20, .has_pat = false,
	.transparency = 0, .refractive = 1, .has_nmap = false, .has_tmap = false, .has_aomap = false,
	.uv_inv_transf = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
	.uv_transf = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
	.tmap = {.data = 0}, .nmap = {.data = 0}, .aomap = {.data = 0}, };

t_material	material(void)
{
	return (g_default_mat);
}

void	set_pattern(t_material *m, t_pattern pat)
{
	m->pat = pat;
	m->has_pat = true;
}
