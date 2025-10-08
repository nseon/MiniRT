/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:47:34 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 13:47:34 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TXT_INPUT_H
# define TXT_INPUT_H

# include "gui/gui.h"

t_guielem	*create_txt_input(t_window *win, uint32_t puid,
				t_txt_cb cb, void *p);
void		draw_txt_input(t_guielem *el, t_image *img);

void		elem_txt_key(t_guielem *input, t_window *win, int keycode);
void		elem_txt_press(t_guielem *input);

#endif
