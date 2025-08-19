/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 06:04:20 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/29 06:04:20 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	point(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 1});
}

t_tuple	vector(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 0});
}
