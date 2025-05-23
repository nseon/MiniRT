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

# include <stdbool.h>

typedef struct s_mouse
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
