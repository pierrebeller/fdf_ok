/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:51:43 by pbeller           #+#    #+#             */
/*   Updated: 2017/09/29 17:51:52 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_inc(t_window *window)
{
	if (window->pad < 75)
		window->pad += 1;
	redraw(window);
}

void	zoom_dec(t_window *window)
{
	if (window->pad > 1)
	{
		window->pad -= 1;
		redraw(window);
	}
}

void	increase_h(t_window *window)
{
	window->pad_h += 1;
	redraw(window);
}

void	decrease_h(t_window *window)
{
	if (window->pad_h > 1)
	{
		window->pad_h -= 1;
		redraw(window);
	}
}
