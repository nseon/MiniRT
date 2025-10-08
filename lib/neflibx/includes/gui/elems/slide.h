/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:24:23 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/17 14:24:23 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLIDE_H
# define SLIDE_H

# include "gui/gui.h"

t_guielem	*create_slide(t_window *win, uint32_t puid, t_float_cb cb, void *p);
void		draw_slide(t_guielem *el, t_image *img);

void		elem_slide_press(t_guielem *const el, int x);
void		elem_slide_release(t_guielem *const el);
void		elem_slide_ptr(t_guielem *const el, int x, int y);

#endif
