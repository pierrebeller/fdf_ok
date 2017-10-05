/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:01:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:01:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_create_window(t_window *window)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		exit(1);
	window->win = mlx_new_window(window->mlx, WIN_W, WIN_H, "fdf");
	window->pad = 1;
	window->opt = ISO;
	window->pad_h = 1;
	window->move_lr = 0;
	window->move_ud = 0;
	window->map_w = 0;
	window->legend = ON;
	window->img = mlx_new_image(window->mlx, WIN_W, WIN_H);
	if (window->img == NULL)
		exit(1);
	window->data = mlx_get_data_addr(window->img, &(window->color),\
		&(window->size), &(window->endian));
	if (window->win == NULL || window->data == NULL)
		exit(1);
	window->map = ft_fdf(window);
}

void		ft_do_fdf(t_window *window)
{
	ft_create_window(window);
	calcul_coords(window);
	mlx_hook(window->win, 2, (1L << 0), key_press, window);
	mlx_expose_hook(window->win, expose_hook, window);
	mlx_loop(window->mlx);
}
