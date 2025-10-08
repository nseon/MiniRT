/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:35:36 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/21 10:35:36 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_BOX_H
# define TEXT_BOX_H

# include "gui/gui.h"

t_guielem	*create_text_box(t_window *win, uint32_t puid);
void		draw_text_box(t_guielem *el, t_image *img);

void		elem_text_box_key(t_guielem *input, t_window *win, int keycode);
void		elem_text_box_press(t_guielem *input);

#endif
