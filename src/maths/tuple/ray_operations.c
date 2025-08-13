/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:16:25 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/13 12:16:25 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (tp_sub(in, tp_mul(normal, 2 * tp_dot(in, normal))));
}
