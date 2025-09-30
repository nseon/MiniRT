/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:04:18 by nseon             #+#    #+#             */
/*   Updated: 2025/09/10 12:48:10 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include <stdbool.h>
# include "render.h"

void	cam_translation(int keycode, void *args);
void	cam_height(int keycode, void *args);
void	authorize_cam_move(int keycode, void *args);
void	rotate_cam(int x, int y, void *args);
void	gui_keys(int keycode, void *p);

#endif
