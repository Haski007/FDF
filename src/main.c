
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

void			paint_map(t_api *api)
{
	t_list		*list;
	t_point		*p;

	list = api->points;
	while (list)
	{
		p = (t_point*)list->content;
		ft_printf("%d ", p->z);
		if (p->x == api->fig_x - 1)
			ft_putchar('\n');
		list = list->next;
	}
}

/*
** 	Set start value for structures
*/
static void		init_structures(t_api *api)
{
	api->mlx = NULL;
	api->win_x = 1000;
	api->win_y = 1000;
	api->zoom = 40;
	api->fd = 0;
	api->fig_x = 0;
	api->fig_y = 0;
	api->points = NULL;
}

int				main(int ac, char **av)
{
	t_api		*api;
	int			p;
	int			t;
	int			r;

	if (ac != 2)
		show_error("Incorrect number of arguments");
	api = (t_api *)malloc(sizeof(t_api));
	api->color = 0x70ff0000;
	init_structures(api);
	get_map(api, av[1]);
	api->mlx = mlx_init();
	api->win = mlx_new_window(api->mlx, api->win_x, api->win_y, "Zaebalo, blyat\n");
	api->img = mlx_new_image(api->mlx, api->win_x, api->win_y);
	api->img_arr = (int *)mlx_get_data_addr(api->img, &p, &t, &r);
	draw(api);
	// draw_xyz(api);
	mlx_hook(api->win, 2, 0, manage_key, api);
	mlx_loop(api->mlx);
	// system("leaks fdf");
	return (0);
}