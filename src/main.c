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

void			paint_map(t_map *map)
{
	t_list	*list;
	t_list	*row;
	t_point	*point;

	list = map->map;
	while (list)
	{
		row = (t_list*)list->content;
		while (row)
		{
			point = (t_point*)row->content;
			printf("%3d", point->z);
			row = row->next;
		}
		printf("\n");
		list = list->next;
	}
}

int				main(int ac, char **av)
{
	t_api		*api;
	t_map		map;
	int			i;
	int			color;
	int			x;
	int			y;

	// if (ac != 2)
	// 	show_error("Incorrect number of arguments");
	api = (t_api *)malloc(sizeof(t_api));
	api->color = 0x70ff0000;
	init_structures(&map, api);
    // map.fd = open("test_maps/42.fdf", O_RDONLY);
	// get_map(&map);
	// paint_map(&map);
	api->mlx = mlx_init();
	api->win = mlx_new_window(api->mlx, 1050, 1050, "My, fucking graphic\n");
	// y = -1;
	// while (++y < 1000)
	// {
	// 	x = -1;
	// 	while (++x < 1000)
	// 		mlx_pixel_put(api->mlx, api->win, x, y, 0xffffff);
	// }
	int		h1 = 350;
	int		h2 = 650;
//"X"
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
	mlx_pixel_put(api->mlx, api->win, 260, 200, api->color);
	// mlx_pixel_put(api->mlx, api->win, 25, 25, color);
	draw(api, &map);
	mlx_loop(api->mlx);
	// system("leaks fdf");
	return (0);
}