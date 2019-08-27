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
void		make_isometric(t_api *api, double xyz[3])
{
	int previous_x;
    int previous_y;

    previous_x = xyz[0];
    previous_y = xyz[1];
    xyz[0] = (previous_x - previous_y) * cos(30 * M_PI / 180);
    xyz[1] = -xyz[2] + (previous_x + previous_y) * sin(30 * M_PI / 180);
}

/*
**	Rotate fiqure by using rotation matrix in directions: X-Axis, Y-Axis, Z-Axis
*/
void			rotate_figure(t_api *api, int key)
{
    int     x;
    int     y;
    int     tmp_x;
    int     tmp_y;

    y = -1;
    while (++y < api->fig_y)
    {
        x = -1;
        while (++x < api->fig_x)
        {
            tmp_x = POINT.x;
            tmp_y = POINT.y;
            POINT.x = (tmp_x - tmp_y) * cos(4 * M_PI / 180);
            POINT.y = -POINT.z + (tmp_x + tmp_y) * sin(4 * M_PI / 180);
        }
    }
    connect_pixels(api);
}
