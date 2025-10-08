/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:15:30 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/23 15:15:30 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "includes/neflibx.h"

void	main_loop(void *p)
{
	t_image *const	img = p;

	put_img(img, 0, 0, true);
}

void	cross(void *p)
{
	t_window *const	win = p;

	end_loop(win);
}

void	btn_cb(char *s, void *p)
{
	printf("okok\n");
}

void	check_cb(bool v, void *p)
{
	printf("%d\n", v);
}

int	main(void)
{
	t_window	win;
	t_image		img;
	t_guielem	*el;
	t_guielem	*ct;
	uint32_t	cuid;

	init_window(&win, 1920, 1080, "okok");
	create_image(&img, win.w, win.h, &win);

	ct = create_container(&win, 0);
	ct->vw = 40;
	ct->vh = 70;
	ct->vx = 50;
	ct->vy = 50;
	ct->id = "ctn";
	cuid = ct->uid;
	el = create_txt_input(&win, cuid, btn_cb, 0);
	// el->label = "test button";
	el->id = "btn";
	el->vy = 9;
	el->vx = 50;
	el->vw = 100;
	el->vh = 40;
	el = create_check(&win, cuid, check_cb, 0);
	// el->label = "test button";
	el->id = "btn";
	el->label = "Supersampling";
	el->vy = 90;
	el->vx = 50;
	el->w = 15;
	el->h = 15;
	// get_by_id(&win, "ctn")->hide = true;
	register_loop(win.events, main_loop, &img);
	register_destroy(win.events, cross, &win);
	loop(&win);
	destroy_image(&img);
	destroy_window(&win);
	return (0);
}
