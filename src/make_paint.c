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

void			transform(t_api *api, double *x, double *y, char dir)
{
	double		tmp_x;

	*x -= api->size_x / 2;
	*y -= api->size_y / 2;
	tmp_x = *x;
	if (dir)
	{
		*x = *x * cos(4 * M_PI / 180) - *y * sin(4 * M_PI / 180);
		*y = tmp_x * sin(4 * M_PI / 180) + *y * cos(4 * M_PI / 180);
	}
	else
	{
		*x = *x * cos(4 * M_PI / 180) + *y * sin(4 * M_PI / 180);
		*y = tmp_x * sin(4 * M_PI / 180) - *y * cos(4 * M_PI / 180);
	}
	*x += api->size_x / 2;
	*y += api->size_y / 2;
}

void			rotate_fiqure(t_api *api, int key)
{
	t_list	*list;
	t_line	*line;

	list = api->res;
	while (list)
	{
		line = (t_line*)list->content;
		if (key == 0)
		{
			transform(api, &line->x1, &line->y1, 0);
			transform(api, &line->x2, &line->y2, 0);
		}
		else if (key == 2)
		{
			transform(api, &line->x1, &line->y1, 1);
			transform(api, &line->x1, &line->y1, 1);
		}
		list = list->next;
	}
	mlx_clear_window(api->mlx, api->win);
	draw(api);
}

void			move_fiqure(t_api *api, int key)
{
	t_list	*list;

	mlx_clear_window(api->mlx, api->win);
	list = api->res;
	while (list)
	{
		if (key == 126 || key == 125)
		{
			((t_line*)list->content)->y1 += (key == 125) ? 10 : -10;
			((t_line*)list->content)->y2 += (key == 125) ? 10 : -10;
		}
		else if (key == 123 || key == 124)
		{
			((t_line*)list->content)->x1 += (key == 124) ? 10 : -10;
			((t_line*)list->content)->x2 += (key == 124) ? 10 : -10;
		}
		list = list->next;
	}
	draw(api);
}

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
	else if (api->zoom != 2)
		api->zoom -= 2;
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
	line->z1 = api->map[y1][x1];
	line->x2 = x2;
	line->y2 = y2;
	line->z2 = api->map[y2][x2];
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