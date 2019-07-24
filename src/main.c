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

	// if (ac != 2)
	// 	show_error("Incorrect number of arguments");
	api = (t_api *)malloc(sizeof(t_api));
	api->color = 0x70ff0000;
    // map.fd = open("test_maps/42.fdf", O_RDONLY);
	// get_map(&map);
	// paint_map(&map);
	api->mlx = mlx_init();
	api->win = mlx_new_window(api->mlx, 1000, 1000, "My, fucking graphic\n");
	draw_line(api, 500, 500, 600, 520);
	mlx_pixel_put(api->mlx, api->win, 600, 520, api->color);
	// mlx_pixel_put(api->mlx, api->win, 25, 25, color);
	mlx_loop(api->mlx);
	// system("leaks fdf");
	return (0);
}