/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:26:45 by pbeller           #+#    #+#             */
/*   Updated: 2017/09/29 18:26:47 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	switch_legend(t_window *window)
{
	if (window->legend == ON)
		window->legend = OFF;
	else if (window->legend == OFF)
		window->legend = ON;
	redraw(window);
}

void	put_legend(t_window *window)
{
	mlx_string_put(window->mlx, window->win, 20, 60, 0x00FF0000, "Map :");
	mlx_string_put(window->mlx, window->win, 70, 60, 0x00FF0000, window->path);
	mlx_string_put(window->mlx, window->win, 20, 80, 0x00FF0000,
		"Zoom : + and -");
	mlx_string_put(window->mlx, window->win, 20, 100, 0x00FF0000,
		"Change projection : P");
	mlx_string_put(window->mlx, window->win, 20, 120, 0x00FF0000,
		"Move : Arrows");
	mlx_string_put(window->mlx, window->win, 20, 140, 0x00FF0000,
		"Change altitude : [ and ]");
	mlx_string_put(window->mlx, window->win, 20, 160, 0x00FF0000,
		"Default settings : O");
	mlx_string_put(window->mlx, window->win, 20, 180, 0x00FF0000,
		"Hide legend : H");
	mlx_string_put(window->mlx, window->win, 20, 200, 0x00FF0000,
		"Zoom Level : ");
	if (window->pad == 1)
		mlx_string_put(window->mlx, window->win, 150, 200, 0x00FF0000,
			"Min");
	else if (window->pad < 75)
		mlx_string_put(window->mlx, window->win, 150, 200, 0x00FF0000,
			ft_itoa(window->pad));
	else
		mlx_string_put(window->mlx, window->win, 150, 200, 0x00FF0000,
			"Max");
}
