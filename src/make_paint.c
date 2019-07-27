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

void			start_coord(t_api *api)
{
	api->len_x *= api->zoom;
	api->len_y *= api->zoom;
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
}

void			connect_pixels(t_api *api)
{
	int		x;
	int		y;
	int		end_x;
	int		end_y;

	end_x = api->len_x;
	end_y = api->len_y;
	start_coord(api);
	y = -1;
	while (++y < end_y)
	{
		x = -1;
		while (++x < end_x)
		{
			if (x + 1 < end_x)
				save_line(api, api->size_x / 2 - api->len_x / 2 + x * api->zoom, api->size_y / 2 - api->len_y / 2 + y * api->zoom,
				api->size_x / 2 - api->len_x / 2 + (x + 1) * api->zoom,
				api->size_y / 2 - api->len_y / 2 + y * api->zoom);
			if (y + 1 < end_y)
				save_line(api, api->size_x / 2 - api->len_x / 2 + x * api->zoom, api->size_y / 2 - api->len_y / 2 + y * api->zoom,
				api->size_x / 2 - api->len_x / 2 + x * api->zoom,
				api->size_y / 2 - api->len_y / 2 + (y + 1) * api->zoom);
		}
	}
}