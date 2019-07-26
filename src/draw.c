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

void			draw(t_api *api, t_map *map)
{
	t_list	*list;
	t_pxl	*pxl;

	list = api->res;
	while (list)
	{
		pxl = (t_pxl*)list->content;
		mlx_pixel_put(api->mlx, api->win, pxl->x, pxl->y, pxl->color);
		list = list->next;
	}
}