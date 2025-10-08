/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:48 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/07 10:37:03 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS

# include "errors.h"
# include "materials.h"

void	input_nmap(char *str, void *p)
{
	t_material *const	mat = p;

	free_map(mat->nmap.data, mat->nmap.infos.h);
	if (parse_png_map(str, &mat->nmap.data, &mat->nmap.infos) != SUCCESS)
	{
		mat->nmap.data = 0;
		mat->has_nmap = false;
	}
	else
		mat->has_nmap = true;
}

void	input_tmap(char *str, void *p)
{
	t_material *const	mat = p;

	free_map(mat->tmap.data, mat->tmap.infos.h);
	if (parse_png_map(str, &mat->tmap.data, &mat->tmap.infos) != SUCCESS)
	{
		mat->tmap.data = 0;
		mat->has_tmap = false;
	}
	else
		mat->has_tmap = true;
}

void	input_aomap(char *str, void *p)
{
	t_material *const	mat = p;

	free_map(mat->aomap.data, mat->aomap.infos.h);
	if (parse_png_map(str, &mat->aomap.data, &mat->aomap.infos) != SUCCESS)
	{
		mat->aomap.data = 0;
		mat->has_aomap = false;
	}
	else
		mat->has_aomap = true;
}

#endif
