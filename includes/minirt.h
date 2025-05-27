/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/23 18:37:03 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "neflibx.h"
# include "render.h"
# include "inputs.h"

typedef struct s_ctx
{
	t_image			img;
	bool			render;
	bool			parsing;
	char			*map_name;
	t_window		win;
	t_graphic_ctx	gctx;
}	t_ctx;

#endif
