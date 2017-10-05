/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:22:37 by pbeller           #+#    #+#             */
/*   Updated: 2017/06/28 15:22:41 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_settings(t_window *window)
{
	window->pad = 1;
	window->opt = ISO;
	window->pad_h = 1;
	window->move_lr = 0;
	window->move_ud = 0;
	window->legend = ON;
	redraw(window);
}

void	move_l(t_window *window)
{
	window->move_lr -= 5;
	redraw(window);
}

void	move_r(t_window *window)
{
	window->move_lr += 5;
	redraw(window);
}

void	move_u(t_window *window)
{
	window->move_ud -= 5;
	redraw(window);
}

void	move_d(t_window *window)
{
	window->move_ud += 5;
	redraw(window);
}
