/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/14 16:22:55 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mesh.h"
#include "neflibx.h"

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

int	main(int c, char **args)
{
	t_mesh		mesh;
	t_triangle	triangle;
	new_mesh(&mesh);
	for (uint32_t i = 0; i < 1000000; i++)
	{
		add_triangle(&mesh, &triangle);
	}
	return (0);
}
