/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:48:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/09/09 10:48:16 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "neflibx.h"
#include "render.h"
#include "tuple.h"
#include "errors.h"

static int32_t	xor_state;

int32_t	init_random(void)
{
	int32_t fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (FATAL);
	if (read(fd, &xor_state, 4) == -1)
		return (FATAL);
	return (SUCCESS);
}

double frandom(int min, int max)
{
	static int	i;
	float		nb;

	if (i >= RAY_NBR)
		i -= RAY_NBR;
	nb = (float)(random[i]) / ((float)256 / (max - min));
	nb += min;
	i += 3;
	return (nb);
}

t_tuple	random_vec(void)
{
	return(vector(frandom(-1, 1), frandom(-1, 1), frandom(-1, 1)));
}
