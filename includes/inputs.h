/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:04:18 by nseon             #+#    #+#             */
/*   Updated: 2025/09/04 16:29:17 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include <stdbool.h>

void	move_cam(int keycode, void *args);
void	move_wheel(int keycode, int x, int y, void *args);
void	mouse_click(int keycode, int x, int y, void *args);
void	mouse_unclick(int keycode, int x, int y, void *args);
void	mouse_move(int x, int y, void *args);
void	release(int keycode, void *args);
void	cam_translation(int keycode, void *args);
void	cam_height(int keycode, void *args);
void	authorize_cam_move(int keycode, void *args);
void	rotate_cam(int x, int y, void *args);
void	window_focus(int keycode, int x, int y, void *args);
void	window_unfocus(int keycode, void *args);

#endif
