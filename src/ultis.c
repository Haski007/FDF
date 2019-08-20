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

// int			get_percent_color(int color, double percent)
// {
// 	int		r;
// 	int		g;
// 	int		b;
// 	int		res;

// 	r = (color >> 16) & 0xFF;
// 	g = (color >> 8) & 0xFF;
// 	b = color & 0xFF;
// 	res = r * percent;
// 	res = res << 8;
// 	res += g * percent;
// 	res = res << 8;
// 	res += b * percent;
// 	return (res);
// }

void			draw_xyz(t_api *api)
{
// 	int		h1;
// 	int		h2;
// 	//"X"

// 	clear_screen(api);
// 	h1 = -1;
// 	while (++h1 < api->size_y)
// 	{
// 		h2 = -1;
// 		while (++h2 < api->size_x)
// 			mlx_pixel_put(api->mlx, api->win, h1, h2, 0x00000);
// 	}
// 	h1 = 350;
// 	h2 = 650;
// 	draw(api, save_line(75, h1, 325, h2));
// 	draw(api, save_line(75, h2, 325, h1));
// //"У"
// 	draw(api, save_line(400, h1, 525, h1 + (h2 - h1) / 2));
// 	draw(api, save_line(400, h2, 650, h1));
// //"Й"
// 	draw(api, save_line(725, h1, 725, h2));
// 	draw(api, save_line(725, h2, 975, h1));
// 	draw(api, save_line(975, h1, 975, h2));
// 	draw(api, save_line(850, h1 - 25, 850, h1 - 75));
// 	draw(api);
}
