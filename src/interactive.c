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

static void		move_figure(t_api *api, int key)
{

}

static void		zoom(t_api *api, int key)
{
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
	else if ((key > 0 && key < 3) || key == 13)
		rotate_figure(api, key);
	else if (key == 4)
		draw_xyz(api);
	return (0);
}
