/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_gui.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:14:49 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/25 17:14:49 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_GUI_H
# define RT_GUI_H

# include <stdbool.h>
# include "minirt.h"

void	xor_denoise(bool b, void *p);
void	xor_ss(bool b, void *p);
void	xor_indirect(bool b, void *p);
void	xor_render(bool b, void *p);
void	object_click(int keycode, int x, int y, void *p);
void	switch_gui_param(t_ctx *ctx, char *id, bool val);
void	gui_loop(t_ctx *ctx);

#endif
