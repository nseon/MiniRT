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
# include "tuple.h"

typedef struct s_pattern
{
	t_fcolor	a;
	t_fcolor	b;
}	t_pattern;

t_pattern	stripe_pattern(t_fcolor a, t_fcolor b);
t_fcolor	stripe_at(t_pattern pat, t_tuple pt);

#endif
