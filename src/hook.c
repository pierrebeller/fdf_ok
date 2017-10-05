/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:01:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:01:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_window *win)
{
	calcul_coords(win);
	return (0);
}

void	redraw(t_window *window)
{
	ft_bzero(window->data, WIN_H * WIN_W * 4);
	calcul_coords(window);
}

void	projection(t_window *window)
{
	if (window->opt == ISO)
		window->opt = PARA;
	else if (window->opt == PARA)
		window->opt = ISO;
	redraw(window);
}

int		key_press(int keycode, t_window *window)
{
	if (keycode == 53)
		ft_quit(window);
	if (keycode == 69)
		zoom_inc(window);
	if (keycode == 78)
		zoom_dec(window);
	if (keycode == 123)
		move_l(window);
	if (keycode == 124)
		move_r(window);
	if (keycode == 126)
		move_u(window);
	if (keycode == 125)
		move_d(window);
	if (keycode == 35)
		projection(window);
	if (keycode == 30)
		increase_h(window);
	if (keycode == 33)
		decrease_h(window);
	if (keycode == 4)
		switch_legend(window);
	if (keycode == 31)
		reset_settings(window);
	return (0);
}
