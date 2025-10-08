/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:01:25 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/05 13:01:25 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "gui/gui.h"
#include "libft.h"
#include "gui/letters.h"

int32_t	get_c_to_write(t_guielem const *const el)
{
	if (ft_strlen(el->txt) > (el->w * (1 - INPUT_MARGIN * 2))
		/ (CHAR_W * el->size))
		return (ft_strlen(el->txt) - (el->w * (1 - INPUT_MARGIN * 2))
			/ (CHAR_W * el->size));
	return (0);
}

int32_t	get_center_h(t_guielem const *const el)
{
	return (el->y + (el->h - CHAR_H * el->size) / 2);
}

int32_t	get_center_w(t_guielem const *const el, const char *const str)
{
	int32_t	len;
	int32_t	max_len;
	int32_t	i;

	i = -1;
	max_len = -1;
	len = 0;
	while (str[++i] != 0)
	{
		if (str[i] == '\n')
		{
			if (len > max_len)
				max_len = len;
			len = 0;
			continue ;
		}
		len++;
	}
	if (len > max_len)
		max_len = len;
	return (el->x + (el->w - max_len * CHAR_W * el->size) / 2);
}
