/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:04:13 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 17:04:13 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"
#include "libft.h"

static void	ft_swap(t_vct a, t_vct b, size_t n)
{
	void	*buf;

	buf = malloc(n);
	if (!buf)
		return ;
	ft_memcpy(buf, a, n);
	ft_memcpy(a, b, n);
	ft_memcpy(b, buf, n);
	free(buf);
}

static int	get_pivot(t_vct vct, int first, int last,
	int (*sort_f)(t_vct, t_vct))
{
	int				i;
	int				j;
	size_t const	n = get_vcthead(vct)->e_size;

	i = first;
	j = first;
	while (i < last)
	{
		if (sort_f(vct + i * n, vct + last * n) != 0)
		{
			ft_swap(vct + i * n, vct + j * n, n);
			j++;
		}
		i++;
	}
	ft_swap(vct + last * n, vct + j * n, n);
	return (j);
}

static void	sort(t_vct vct, int first, int last, int (*sort_f)(t_vct, t_vct))
{
	int	pivot;

	if (first <= last)
	{
		pivot = get_pivot(vct, first, last, sort_f);
		sort(vct, first, pivot - 1, sort_f);
		sort(vct, pivot + 1, last, sort_f);
	}
}

void	vct_sort(t_vct vct, int (*sort_f)(t_vct, t_vct))
{
	if (vct_size(vct) < 2)
		return ;
	sort(vct, 0, (int)vct_size(vct) - 1, sort_f);
}
