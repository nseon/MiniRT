/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:30:46 by pjarnac           #+#    #+#             */
/*   Updated: 2024/11/12 17:37:56 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**free_all(char **res, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int	calc_alloc(char const *s, const char *set)
{
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (!in_word && !ft_ischarset(*s, set))
		{
			count++;
			in_word = 1;
		}
		else if (in_word && ft_ischarset(*s, set))
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*split_strdup(char const *s, const char *set)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i] && !ft_ischarset(s[i], set))
		i++;
	dup = malloc((i + 1) * sizeof (char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && !ft_ischarset(s[i], set))
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	**ft_split(char const *s, const char *set)
{
	int				in_word;
	int				count;
	char **const	res = malloc((calc_alloc(s, set) + 1) * sizeof (char *));

	if (!res)
		return (NULL);
	in_word = 0;
	count = 0;
	while (*s)
	{
		if (!in_word && !ft_ischarset(*s, set))
		{
			in_word = 1;
			res[count] = split_strdup(s, set);
			if (!res[count])
				return (free_all(res, count));
			count++;
		}
		else if (in_word && ft_ischarset(*s, set))
			in_word = 0;
		s++;
	}
	res[count] = 0;
	return (res);
}
