/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:48:44 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/24 15:49:27 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			show_error(const char *error)
{
	ft_printf("%tERROR: %t%s%t\n", B_RED, B_WHITE, error, EOC);
	exit(0);
}

void		init_map(t_map *map)
{
	map->map = NULL;
}