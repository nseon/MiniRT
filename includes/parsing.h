/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:24:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 13:24:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define FILENAME "Map filename:"
# define FILENAME_ID "filename_input"
# define PARSE_CTN_ID "parse_ctn"
# define PARSE_TXT_ID "parse_txt_box"
# define LOADED "Map loaded !"
# define WHITESPACES "\t\n\v\f\r "

# ifdef BONUS
#  define BONUS_STATE 1
#  define MANDATORY "C"
#  define P_ELEMENTS "A lpt ldir C sp pl cy bl cb #"
#  define P_AMBI_LIGHT "A"
#  define P_PT_LIGHT "lpt"
#  define P_DIR_LIGHT "ldir"
#  define P_CAMERA "C"
#  define P_SPHERE "sp"
#  define P_PLANE "pl"
#  define P_CYLINDER "cy"
#  define P_BACKLIGHT "bl"
#  define P_CUBE "cb"
# else
#  define BONUS_STATE 0
#  define MANDATORY "A L C"
#  define P_ELEMENTS "A L C sp pl cy #"
#  define P_AMBI_LIGHT "A"
#  define P_PT_LIGHT "L"
#  define P_CAMERA "C"
#  define P_SPHERE "sp"
#  define P_PLANE "pl"
#  define P_CYLINDER "cy"
#  define P_BACKLIGHT "bl"
#  define P_CUBE "cb"
# endif

# include "minirt.h"
# include "fcolors.h"

void	open_file(char *str, t_ctx *ctx);
void	parse(char *str, void *p);

int32_t	parse_map(t_ctx *ctx);
void	draw_file_status(t_ctx *ctx);

int32_t	parse_color(char *str, t_fcolor *color);
int32_t	parse_double(char *str, double *f);
int32_t	parse_xyz(char *str, t_tuple *tp);
int32_t	parse_trans(char *str, t_obj *o);
int32_t	parse_normal(char *str, t_tuple *vct);
int32_t	parse_ptype(char *str, t_pattern_type *p);

int32_t	parse_ambi_light(char **split, t_amb *amb_light);
int32_t	parse_camera(char **split, t_camera *cam);
int32_t	parse_light(char **split, t_light *light);
int32_t	parse_sphere(char **split, t_world *w);
int32_t	parse_plane(char **split, t_world *w);
int32_t	parse_cylinder(char **split, t_world *w);
int32_t	parse_backlight(char **split, t_fcolor *bl);
int32_t	parse_cube(char **split, t_world *w);
int32_t	parse_pattern(char **split, t_obj *o);
int32_t	parse_maps(char **split, t_obj *o);

#endif
