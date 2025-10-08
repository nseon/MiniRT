/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:46:56 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 13:46:56 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_EVENTS_H
# define GUI_EVENTS_H

void		gui_btnrelease(int keycode, int x, int y, void *p);
void		gui_btnpress(int keycode, int x, int y, void *p);
void		gui_keypress(int keycode, void *p);
void		gui_ptr(int x, int y, void *p);

#endif
