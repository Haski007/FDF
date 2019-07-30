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

int			centr_x(t_api *api, int x)
{
	return (api->size_x / 2 - api->len_x / 2 + x * api->zoom);
}

int			centr_y(t_api *api, int y)
{
	return (api->size_y / 2 - api->len_y / 2 + y * api->zoom);
}

void		init_structures(t_api *api)
{
	api->size_x = 1000;
	api->size_y = 1000;
	api->len_x = 0;
	api->len_y = 0;
	api->m_x = 0;
	api->m_y = 0;
	api->zoom = 50;
	api->map = NULL;
	api->res = NULL;
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

void			draw_xyz(t_api *api)
{
	int		h1;
	int		h2;
	//"X"
	h1 = 350;
	h2 = 650;
	save_line(api, 75, h1, 325, h2);
	save_line(api, 75, h2, 325, h1);
//"У"
	save_line(api, 400, h1, 525, h1 + (h2 - h1) / 2);
	save_line(api, 400, h2, 650, h1);
//"Й"
	save_line(api, 725, h1, 725, h2);
	save_line(api, 725, h2, 975, h1);
	save_line(api, 975, h1, 975, h2);
	save_line(api, 850, h1 - 25, 850, h1 - 75);
}

int			do_something(int key, t_api *api)
{
	if (key == 53)
	{
		system("leaks fdf");
		exit(0);
	}
	return (0);
}