/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:59:02 by pdemian           #+#    #+#             */
/*   Updated: 2019/08/20 13:59:05 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Make rotation for parallel fiqure to make fake 3D
*/
void		make_isometric(t_api *api, double xyz[3], int degre)
{
	double previous_x;
    double previous_y;

    previous_x = xyz[0];
    previous_y = xyz[1];
    xyz[0] = (previous_x - previous_y) * cos(degre * M_PI / 180);
    xyz[1] = -xyz[2] + (previous_x + previous_y) * sin(degre * M_PI / 180);
}

/*
**	Rotate fiqure by using rotation matrix in directions: X-Axis, Y-Axis, Z-Axis
*/
void			rotate_figure(t_api *api, int key)
{
    int     x;
    int     y;
    double  xyz[3];
    double  tmp_x;
    static int  zaix = 2;

    y = -1;
    while (++y < api->fig_y)
    {
        x = -1;
        while (++x < api->fig_x)
        {
            xyz[0] = (x - api->fig_x / 2) * api->zoom;
			xyz[1] = (y - api->fig_y / 2) * api->zoom;
			xyz[2] = api->points[y][x].z * api->zoom;
            tmp_x = xyz[0];
            xyz[0] = tmp_x * cos(zaix * M_PI / 180) - xyz[1] * sin(zaix * M_PI / 180);
            xyz[1] = tmp_x * sin(zaix * M_PI / 180) + xyz[1] * cos(zaix * M_PI / 180);
            make_isometric(api, xyz, 30);
			POINT.x = (int)xyz[0] + api->win_x / 2;
			POINT.y = (int)xyz[1] + api->win_y / 2;
        }
    }
    zaix += 2;
    connect_pixels(api);
}
