/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:11:01 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/15 16:11:01 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define PARSE_INVAL_MAP -255

# define PARSE_INVAL_TYPE -2
# define PARSE_INVAL_TYPE_MSG "invalid object type: %s\n"
# define PARSE_INVAL_LINE -3

# define PARSE_LINE_SPEC "on line: %d\n"

# define PARSE_MISSING_FIELD -5
# define PARSE_MISSING_FLOAT "missing double field\n"
# define PARSE_MISSING_COLOR "missing color field\n"
# define PARSE_MISSING_XYZ "missing xyz coordinates field\n"
# define PARSE_MISSING_VCT "missing normal vector field\n"

# define PARSE_INVAL_FORMAT -6
# define PARSE_INVAL_COLOR_MSG "invalid color format: (%s)\n"
# define PARSE_INVAL_XYZ_MSG "invalid xyz coordinates format: (%s)\n"
# define PARSE_INVAL_UNIT "invalid unit vector: (%s)\n"
# define PARSE_INVAL_VCT_MSG "vector is not unit vector: (%s): "
# define PARSE_INVAL_VCT_MSG2 "auto-normalizing -> (%f, %f, %f)\n"
# define PARSE_INVAL_FOV "invalid fov range (%d) needs to be [0, 180]\n"
# define PARSE_INVAL_MAND "mandatory elements misconfiguration\n"

# define FATAL -1
# define SUCCESS 0

#endif
