/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/12 10:46:27 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "render.h"

# define WIN_W 1920
# define WIN_H 1080

int8_t	init_gui(t_ctx *ctx);
void	test_render(t_ctx * const ctx);
void	keyevent(int keycode, void *p);

#endif
