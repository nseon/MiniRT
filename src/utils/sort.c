/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:06:06 by pjarnac           #+#    #+#             */
/*   Updated: 2025/08/15 15:06:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neflibx.h"
#include "ray.h"

static void	ft_swap(t_intersection *a, t_intersection *b)
{
	t_intersection	buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

static int	get_pivot(t_intersection *xs, int first, int last)
{
	int				i;
	int				j;

	i = first;
	j = first;
	while (i < last)
	{
		if (xs[i].t < xs[last].t)
		{
			ft_swap(xs + i, xs + j);
			j++;
		}
		i++;
	}
	ft_swap(xs + last, xs + j);
	return (j);
}

static void	sort(t_intersection *xs, int first, int last)
{
	int	pivot;

	if (first <= last)
	{
		pivot = get_pivot(xs, first, last);
		sort(xs, first, pivot - 1);
		sort(xs, pivot + 1, last);
	}
}

void	sort_inter(t_intersections xs)
{
	if (xs.count < 2)
		return ;
	sort(xs.i, 0, xs.count - 1);
}
