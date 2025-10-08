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

# define EDIT_CTN_ID "edit_ctn"

# include <stdbool.h>
# include "minirt.h"

void	xor_denoise(bool b, void *p);
void	xor_ss(bool b, void *p);
void	xor_indirect(bool b, void *p);
void	xor_render(bool b, void *p);
void	object_click(int keycode, int x, int y, void *p);
void	switch_gui_param(t_ctx *ctx, char *id, bool val);
void	gui_loop(t_ctx *ctx);
void	float_switch(float f, void *p);
void	show_edit(t_ctx *ctx);
void	set_color(t_ctx *ctx, t_fcolor *col);
void	double_switch(float f, void *p);
void	refrac_switch(float f, void *p);
void	input_nmap(char *str, void *p);
void	input_tmap(char *str, void *p);
void	input_aomap(char *str, void *p);
void	tmap_bool(bool b, void *p);
void	nmap_bool(bool b, void *p);
void	aomap_bool(bool b, void *p);
int32_t	edit_aomap_gui(t_ctx *ctx, uint32_t cuid);
int32_t	edit_tnmap_gui(t_ctx *ctx, uint32_t cuid);

#endif
