
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:41:58 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/23 16:42:19 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			iso(t_api *api, double *x, double *y, int z)
{
    double previous_x;
    double previous_y;

	z *= api->zoom;
    previous_x = centr_x(api, *x);
    previous_y = centr_y(api, *y);
	*x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void			isometrical(t_api *api)
{
	t_list	*list;
	t_line	*line;

	list = api->res;
	while (list)
	{
		line = (t_line*)list->content;
		iso(api, &line->x1, &line->y1, api->map[(int)line->y1][(int)line->x1]);
		iso(api, &line->x2, &line->y2, api->map[(int)line->y2][(int)line->x2]);
		line->x1 += api->size_x / 2;
		line->x2 += api->size_x / 2;
		list = list->next;
	}
}

void			clear_screen(t_api *api)
{
	mlx_clear_window(api->mlx, api->win);
	ft_lstdel(&api->res, ft_lstfree);
}

void			paint_map(t_api *api)
{
	int		x;
	int		y;

	y = -1;
	while (++y < api->len_y)
	{
		x = -1;
		while (++x < api->len_x)
			ft_printf("%3d", api->map[y][x]);
		ft_putchar('\n');
	}
}

int				main(int ac, char **av)
{
	t_api		*api;
	int			i;
	int			color;
	int			x;
	int			y;

	if (ac != 2)
		show_error("Incorrect number of arguments");
	api = (t_api *)malloc(sizeof(t_api));
	api->color = 0x70ff0000;
	init_structures(api);
    api->fd = open(av[1], O_RDONLY);
	get_map(api, av[1]);
	// paint_map(api);
	connect_pixels(api);
	isometrical(api);
	api->mlx = mlx_init();
	api->win = mlx_new_window(api->mlx, api->size_x, api->size_y, "My, fucking graphic\n");
	// clear_screen(api);
	draw(api);
	// draw_xyz(api);
	mlx_hook(api->win, 2, 0, do_something, api);
	mlx_pixel_put(api->mlx, api->win, 501, 501, 0xffffff);
	mlx_loop(api->mlx);
	return (0);
}