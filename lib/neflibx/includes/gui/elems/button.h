/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:47:04 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 13:47:04 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include "gui/gui.h"

t_guielem	*create_button(t_window *win, uint32_t puid,
				t_generic_cb cb, void *p);
void		draw_button(t_guielem *el, t_image *img);

void		elem_btn_press(t_guielem *btn);
void		elem_btn_release(t_guielem *btn);

#endif
