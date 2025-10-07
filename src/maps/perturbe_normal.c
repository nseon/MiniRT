/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbe_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 08:49:03 by nseon             #+#    #+#             */
/*   Updated: 2025/10/06 09:15:33 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"
#include "rt_maths.h"
#include "tuple.h"

t_tbn	calcul_tbn(t_tuple ojb_norm)
{
	t_tbn	tbn;
	t_tuple	up;

	up = vector(0, 1, 0);
	if (dabs(tp_dot(up, ojb_norm)) > 0.95)
		up = vector(1, 0, 0);
	tbn.t = tp_normalize(tp_cross(ojb_norm, up));
	tbn.b = tp_normalize(tp_cross(ojb_norm, tbn.t));
	tbn.n = ojb_norm;
	return (tbn);
}

t_tuple	pertube_normal(t_tuple ojb_norm, t_tuple map_norm)
{
	t_tbn const	tbn = calcul_tbn(ojb_norm);

	return (tp_normalize(tp_add(tp_add(tp_mul(tbn.t, map_norm.x),
				tp_mul(tbn.b, map_norm.y)), tp_mul(tbn.n, map_norm.z)))); 
}
