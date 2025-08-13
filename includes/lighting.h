/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:36:31 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/13 14:36:31 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_LIGHTING_H
# define MINIRT_LIGHTING_H

# include "fcolors.h"
# include "tuple.h"
# include "objects.h"

typedef struct s_phong_comp
{
	t_tuple	pos;
	t_tuple	eyev;
	t_tuple	normalv;
	t_light	light;
	t_tuple	lightv;
}	t_phong_comp;

t_fcolor	phong(t_material m, t_phong_comp c);

#endif
