/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:21:58 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/13 14:21:58 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATERIALS_H
# define MINIRT_MATERIALS_H

# include "fcolors.h"

typedef struct s_material
{
	t_fcolor	col;
	double		diffuse;
	double		ambient;
	double		specular;
	double		shine;
}	t_material;

extern t_material const	g_default_mat;

t_material	material(void);

#endif
