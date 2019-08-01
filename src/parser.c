/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:14:07 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/24 14:14:11 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point			*make_point(int x, int y, int z)
{
	t_point		*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

void			init_map(t_api *api)
{
	char	*line;
	int		i;
	int		**map;

	while (get_next_line(api->fd, &line) > 0)
	{
		i = -1;
		if (!api->len_x)
			while (line[++i])
				if (ft_isdigit(line[i]))
				{
					api->len_x++;
					while (ft_isdigit(line[i]))
						i++;
				}
		api->len_y++;
		ft_strdel(&line);
	}
	map = (int**)malloc(sizeof(int*) * (api->len_y + 1));
	map[api->len_y] = NULL;
	i = -1;
	while (++i < api->len_y)
		map[i] = (int*)malloc(sizeof(int) * api->len_x);
	api->map = map;
}

void			get_map(t_api *api, char *av)
{
	char	*line;
	int		y;
	int		x;
	int		i;

	init_map(api);
	close(api->fd);
	api->fd = open(av, O_RDONLY);
	y = -1;
	while (get_next_line(api->fd, &line) > 0)
	{
		y++;
		i = -1;
		x = -1;
		while (line[++i] != '\0')
			if (ft_isdigit(line[i]) || (line[i] == '-' && ft_isdigit(line[i])))
			{
				api->map[y][++x] = ft_atoi(line + i);
				while (ft_isdigit(line[i]))
					i++;
			}
		ft_strdel(&line);
	}
}