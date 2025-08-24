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
# include "patterns.h"

typedef struct s_material
{
	t_fcolor	col;
	double		diffuse;
	double		specular;
	double		shine;
	double		reflective;
	bool		has_pat;
	t_pattern	pat;
}	t_material;

extern t_material const	g_default_mat;

t_material	material(void);
void		set_pattern(t_material *m, t_pattern pat);

#endif
