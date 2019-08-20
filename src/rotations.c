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
static void		make_isometric(t_api *api)
{

}

/*
**	Rotate fiqure by using rotation matrix in directions: X-Aix, Y-Aix, Z-Aix
*/
void			rotate_figure(t_api *api, int key)
{
	if (key == 34)
		make_isometric(api);
}
