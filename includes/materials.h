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

#ifndef MATERIALS_H
# define MATERIALS_H

# include "fcolors.h"
# include "patterns.h"
# include "maps.h"

typedef struct s_material
{
	t_fcolor	col;
	double		diffuse;
	double		specular;
	double		shine;
	double		reflective;
	double		transparency;
	double		refractive;
	bool		has_nmap;
	t_map		nmap;
	bool		has_texture;
	t_map		tmap;
	bool		has_ao;
	t_map		aomap;
	bool		has_pat;
	t_mtx4		uv_transf;
	t_mtx4		uv_inv_transf;
	t_pattern	pat;
}	t_material;

extern t_material const	g_default_mat;

t_material	material(void);
void		set_pattern(t_material *m, t_pattern pat);
void		mul_uv_transf(t_material *mat, t_mtx4 transf);
void		set_uv_transf(t_material *mat, t_mtx4 transf);
#endif
