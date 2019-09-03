/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:45:52 by pdemian           #+#    #+#             */
/*   Updated: 2019/08/20 13:45:56 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		move_figure(t_api *api, int key)
{
	int		y;
	int		x;
	int		move_x;
	int		move_y;

	move_x = 0;
	move_y = 0;
	y = -1;
	while (++y < api->fig_y)
	{
		x = -1;
		while (++x < api->fig_x)
		{
			if (key == 123 || key == 124)
				POINT.x += (key == 123) ? -10 : 10;
			else if (key == 125 || key == 126)
				POINT.y += (key == 126) ? -10 : 10;
		}
	}
	connect_pixels(api);	
}

/*
**	Changing zoom
*/
static void		zoom(t_api *api, int key)
{
	if (key == 69)
		api->zoom++;
	else if (key == 78 && api->zoom > 1)
		api->zoom--;
	draw(api);
}

/*
**	Perform functions by depending on input from keyboard
*/
int				manage_key(int key, t_api *api)
{
	if (key == 53)
	{
		// system("leaks fdf");
		exit(0);
	}
	else if (key == 78 || key == 69)
		zoom(api, key);
	else if ((key > 122 && key < 127) || (key > 11 && key < 15))
		move_figure(api, key);
	else if ((key > 0 && key < 3) || (key > 11 && key < 15))
		rotate_figure(api, key);
	// else if (key == 4)
	// 	draw_xyz(api);
	// draw(api);
	return (0);
}
