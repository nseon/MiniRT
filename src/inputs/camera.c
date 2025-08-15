/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:06:54 by nseon             #+#    #+#             */
/*   Updated: 2025/06/04 16:03:06 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "inputs.h"
#include "image.h"
#include "render.h"
#include "minirt.h"
#include <X11/keysym.h>
#include <stdlib.h>

void	release(int keycode, void *args)
{
	(void)keycode;
	((t_ctx *)args)->render = false;
}

void	mouse_unclick(int keycode, int x, int y, void *args)
{
	t_mouse *mouse;

	mouse = (t_mouse *)args;
	(void)x;
	(void)y;
	if (keycode == 1)
		mouse->click = false;
}

