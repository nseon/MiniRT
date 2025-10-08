/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:24:02 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/24 16:24:02 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define EVENTS_NUM 7
# define KEYPRESS_EV 0
# define KEYRELEASE_EV 1
# define BTNPRESS_EV 2
# define BTNRELEASE_EV 3
# define POINTER_EV 4
# define DESTROY_EV 5
# define LOOP_EV 6

# include <stdint.h>
# include <stdbool.h>

typedef void	(*t_generic_cb)(void *p);
typedef void	(*t_key_cb)(int keycode, void *p);
typedef void	(*t_btn_cb)(int keycode, int x, int y, void *p);
typedef void	(*t_ptr_cb)(int x, int y, void *p);
typedef void	(*t_txt_cb)(char *txt, void *p);
typedef void	(*t_float_cb)(float f, void *p);
typedef void	(*t_bool_cb)(bool b, void *p);

typedef struct s_callback
{
	t_generic_cb	callback;
	void			*cb_param;
}	t_callback;

void	register_keypress(t_callback *events[EVENTS_NUM],
			t_key_cb cb, void *cb_param);
int		keypress_event(int keycode,
			t_callback *events[EVENTS_NUM]);

void	register_keyrelease(t_callback *events[EVENTS_NUM],
			t_key_cb cb, void *cb_param);
int		keyrelease_event(int keycode,
			t_callback *events[EVENTS_NUM]);

void	register_btnpress(t_callback *events[EVENTS_NUM],
			t_btn_cb cb, void *cb_param);
int		btnpress_event(int keycode, int x, int y,
			t_callback *events[EVENTS_NUM]);

void	register_btnrelease(t_callback *events[EVENTS_NUM],
			t_btn_cb cb, void *cb_param);
int		btnrelease_event(int keycode, int x, int y,
			t_callback *events[EVENTS_NUM]);

void	register_pointer(t_callback *events[EVENTS_NUM],
			t_ptr_cb cb, void *cb_param);
int		pointer_event(int x, int y,
			t_callback *events[EVENTS_NUM]);

void	register_destroy(t_callback *events[EVENTS_NUM],
			t_generic_cb cb, void *cb_param);
int		destroy_event(t_callback *events[EVENTS_NUM]);

void	register_loop(t_callback *events[EVENTS_NUM],
			t_generic_cb cb, void *cb_param);
int		loop_event(t_callback *events[EVENTS_NUM]);

#endif
