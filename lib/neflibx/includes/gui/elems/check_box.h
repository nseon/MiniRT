/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:51:40 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/23 16:51:40 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BOX_H
# define CHECK_BOX_H

# include "gui/gui.h"

t_guielem	*create_check(t_window *win, uint32_t puid,
				t_bool_cb cb, void *p);
void		draw_check(t_guielem *el, t_image *img);

void		elem_check_press(t_guielem *btn);
void		elem_check_release(t_guielem *btn);

#endif