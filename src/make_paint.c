/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:34:46 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/26 18:35:15 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			zoom_plus(t_api *api)
{
	api->zoom += 1;
	clear_screen(api);
	connect_pixels(api);
	isometrical(api);
	draw(api);
}

void			zoom_minus(t_api *api)
{
	if (api->zoom == 1)
		api->zoom = api->zoom;
	else if (api->zoom != 1)
		api->zoom -= 1;
	clear_screen(api);
	connect_pixels(api);
	isometrical(api);
	draw(api);
}

void			save_line(t_api *api, int x1, int y1, int x2, int y2)
{
	int 	y;
	int		x;
	t_line	*line;

	line = (t_line*)malloc(sizeof(t_line));
	line->x1 = x1;
	line->y1 = y1;
	line->x2 = x2;
	line->y2 = y2;
	ft_lstpush(&api->res, ft_lstnew(line, sizeof(t_line)));
	free(line);
}

void			connect_pixels(t_api *api)
{
	int		x;
	int		y;

	y = -1;
	while (++y < api->len_y)
	{
		x = -1;
		while (++x < api->len_x)
		{
			if (x + 1 < api->len_x)
				save_line(api, x, y, x + 1, y);
			if (y + 1 < api->len_y)
				save_line(api, x, y, x, y + 1);
		}
	}
}