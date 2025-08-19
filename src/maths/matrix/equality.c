/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:58:47 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/31 20:58:47 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_maths.h"
#include "matrix.h"

bool	mtx4_equal(t_mtx4 const m1, t_mtx4 const m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!f_equal(m1[i][j], m2[i][j]))
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

bool	mtx3_equal(t_mtx3 const m1, t_mtx3 const m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (!d_equal(m1[i][j], m2[i][j]))
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

bool	mtx2_equal(t_mtx2 const m1, t_mtx2 const m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			if (!d_equal(m1[i][j], m2[i][j]))
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}
