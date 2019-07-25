/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:48:44 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/24 15:49:27 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			show_error(const char *error)
{
	ft_printf("%tERROR: %t%s%t\n", B_RED, B_WHITE, error, EOC);
	exit(0);
}

void		init_structures(t_map *map, t_api *api)
{
	map->map = NULL;
}

int			get_percent_color(int color, double percent)
{
	int		r;
	int		g;
	int		b;
	int		res;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	res = r * percent;
	res = res << 8;
	res += g * percent;
	res = res << 8;
	res += b * percent;
	return (res);
}

