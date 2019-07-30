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
	api->mlx = mlx_init();
	api->win = mlx_new_window(api->mlx, api->size_x, api->size_y, "My, fucking graphic\n");
	draw(api);
	mlx_pixel_put(api->mlx, api->win, 501, 501, 0xffffff);
	mlx_hook(api->win, 2, 0, do_something, api);
	mlx_loop(api->mlx);
	draw_xyz(api);
	// system("leaks fdf");
	// clear_screen(api);
	return (0);
}