/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:34:01 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/21 12:34:01 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"
#include "objects.h"
#include "uv_maps.h"

t_pattern	pattern(t_fcolor a, t_fcolor b, t_pattern_type type)
{
	t_pattern	pat;

	pat.type = type;
	pat.a = a;
	pat.b = b;
	mtx4_dup(g_identity_matrix, pat.transf);
	mtx4_dup(g_identity_matrix, pat.inv_transf);
	return (pat);
}

void	set_pattern_transf(t_pattern *pat, t_mtx4 transf)
{
	mtx4_dup(transf, pat->transf);
	mtx4_inverse2(pat->transf, pat->inv_transf);
}

void	mul_pattern_transf(t_pattern *pat, t_mtx4 transf)
{
	mtx_mul2(pat->transf, transf);
	mtx4_inverse2(pat->transf, pat->inv_transf);
}

t_fcolor	pattern_at_obj(t_pattern pat, t_obj *o, t_tuple pt)
{
	mtx_tup_mul2(&pt, o->inv_transform);
	if (o->type == SPHERE && (pat.type == CHECKER || pat.type == STRIPE))
		pt = sphere_uv_point(pt);
	mtx_tup_mul2(&pt, pat.inv_transf);
	if (pat.type == STRIPE)
		return (stripe_at(pat, pt));
	if (pat.type == GRADIENT)
		return (gradient_at(pat, pt));
	if (pat.type == RING)
		return (ring_at(pat, pt));
	if (pat.type == CHECKER)
		return (checker_at(pat, pt));
	return (fcolor(0, 0, 0));
}
