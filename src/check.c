/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:00:51 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:00:58 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		check_x(int x)
{
	if (x > 0 && x < WIN_W)
		return (1);
	return (0);
}

int		check_y(int y)
{
	if (y > 0 && y < WIN_H)
		return (1);
	return (0);
}

int		ft_length(char **tab)
{
	int len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

void	ft_destroy(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	tab[i] = NULL;
}
