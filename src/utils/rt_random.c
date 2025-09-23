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
#include <iso646.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "neflibx.h"
#include "render.h"
#include "tuple.h"
#include "errors.h"

static uint32_t	xor_state;

int32_t	init_random(void)
{
	int32_t fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (FATAL);
	if (read(fd, &xor_state, 4) == -1)
	{
		close(fd);
		return (FATAL);
	}
	close(fd);
	return (SUCCESS);
}

double frandom(int min, int max)
{
	xor_state ^= xor_state << 13;
	xor_state ^= xor_state >> 17;
	xor_state ^= xor_state << 5;
	return ((double)xor_state / (UINT32_MAX / (max - min)) + min);
}

t_tuple	random_vec(void)
{
	return(vector(frandom(-1, 1), frandom(-1, 1), frandom(-1, 1)));
}
