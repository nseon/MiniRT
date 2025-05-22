/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:04:18 by nseon             #+#    #+#             */
/*   Updated: 2025/05/22 17:27:54 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361

#include <stdbool.h>

typedef	struct s_mouse
{
	bool	click;
	int		x;
	int		y;
}	t_mouse;


void	move_cam(int keycode, void *args);
void	move_wheel(int keycode, int x, int y, void *args);
void	mouse_click(int keycode, int x, int y, void *args);
void	mouse_unclick(int keycode, int x, int y, void *args);
void	mouse_move(int x, int y, void *args);

#endif
