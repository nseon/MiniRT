/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:34:32 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/21 12:34:32 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "fcolors.h"
# include "matrix.h"
# include "tuple.h"

typedef enum e_pattern_type
{
	STRIPE,
	GRADIENT,
	RING,
	CHECKER,
}	t_pattern_type;

typedef struct s_pattern
{
	t_pattern_type	type;
	t_fcolor		a;
	t_fcolor		b;
	t_mtx4			transf;
	t_mtx4			inv_transf;
}	t_pattern;

void		set_pattern_transf(t_pattern *pat, t_mtx4 transf);
void		mul_pattern_transf(t_pattern *pat, t_mtx4 transf);
t_pattern	pattern(t_fcolor a, t_fcolor b, t_pattern_type type);
t_fcolor	stripe_at(t_pattern pat, t_tuple pt);
t_fcolor	gradient_at(t_pattern pat, t_tuple pt);
t_fcolor	ring_at(t_pattern pat, t_tuple pt);
t_fcolor	checker_at(t_pattern pat, t_tuple pt);

#endif
