/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:22:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/19 18:36:54 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mesh.h"
#include "neflibx.h"

void	end(void *p)
{
	t_window	*win = (t_window *)p;
	end_loop(win);
}

int	main(int c, char **args)
{
	t_window	win;
	t_image		img;
	int			i;
	int			r;
	int			g;
	int			b;
	int			check;

	init_window(&win, 1098, 800, "TEST");
	create_image(&img, 1098, 800, &win);
	put_img(&img, 0, 0);
	register_destroy(win.events, end, &win);
	loop(&win);
	return (0);
}
