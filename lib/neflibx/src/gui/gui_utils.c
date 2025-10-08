/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:39:46 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 14:39:46 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "window.h"
#include "gui/gui.h"

void	unfocus(t_guielem *el)
{
	if (el)
		el->focus = false;
}

void	unhover(t_guielem *el)
{
	if (el)
		el->hover = false;
}

void	unfocus_all(t_window const *const win)
{
	size_t	i;

	i = -1;
	while (++i < vct_size(win->gui_elems))
		win->gui_elems[i].focus = false;
}
