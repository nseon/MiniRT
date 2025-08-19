/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:51:23 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/24 16:51:23 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATHS_H
# define RT_MATHS_H

# define EPSILON 0.0001
# define DEPSILON 0.00001

# include <stdbool.h>

bool	d_equal(double a, double b);
bool	f_equal(float a, float b);

#endif
