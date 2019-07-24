/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:53:20 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/24 20:53:24 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"



void			draw_line(t_api *api, int x1, int y1, int x2, int y2)
{
    int     dx;
    int     dy;
	int 	y;
	int		x;
	int		diry;
    int     err;
	int		del_err;
	int		error;

    if (x2 < x1)
    {
        ft_swap(&x1, &x2);
        ft_swap(&y1, &y2);
    }
    dx = x2 - x1;
    dy = abs(y2 - y1);
    err = 0.0;
	del_err = dy;
	y = y1;
	x = x1 - 1;
	diry = y2 - y1;
    if (diry > 0)
		diry = 1;
    if (diry < 0)
		diry = -1;
	while (++x < x2)
	{
		mlx_pixel_put(api->mlx, api->win, x, y, api->color);
		error += del_err;
		if (2 * error >= dx)
		{
			y += diry;
			err -= dx;
		}
	}
}