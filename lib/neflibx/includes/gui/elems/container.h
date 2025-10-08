/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:17:09 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/18 13:17:09 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_H
# define CONTAINER_H

# include "gui/gui.h"

void		draw_container(t_guielem *el, t_image *img);
t_guielem	*create_container(t_window *win, uint32_t puid);

#endif
