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

	while (get_next_line(api->fd, &line) > 0)
	{
		i = -1;
		line[ft_strlen(line) + 1] = '\0';
		if (!api->len_x)
			while (line[++i] != '\0')
				if (line[i] >= '0' && line[i] <= '9')
				{
					api->len_x++;
					while (line[i] >= '0' && line[i] <= '9')
						i++;
				}
		ft_strdel(&line);
		api->len_y++;
	}
	api->map = (int**)malloc(sizeof(int*) * api->len_y + 1);
	api->map[api->len_y] = NULL;
	i = -1;
	while (++i < api->size_y)
		api->map[i] = (int*)malloc(sizeof(int) * api->len_x);
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
		line[ft_strlen(line) + 1] = '\0';
		while (line[++i] != '\0')
			if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-' &&
			line[i + 1] >= '0' && line[i + 1] <= '9'))
			{
				api->map[y][++x] = ft_atoi(line + i);
				while (line[i] >= '0' && line[i] <= '9')
					i++;
			system("leaks fdf");
			exit(1);
			}
		ft_strdel(&line);
	}
}