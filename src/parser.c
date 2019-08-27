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

static t_point	*make_point(int x, int y, int z)
{
	t_point		*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

/*
**	Malloc map by 1 goes
*/
static void		size_map(t_api *api)
{
	char	*line;
	int		i;
	
	if (read(api->fd, line, 0) < 0)
		show_error("File is not supported!");
	while (get_next_line(api->fd, &line) > 0)
	{
		i = -1;
		if (!api->fig_x)
			while (line[++i])
			{
				if (ft_isdigit(line[i]))
				{
					while (line[i + 1] && ft_isdigit(line[i]))
						i++;
					api->fig_x++;
				}
			}
		ft_strdel(&line);		
		api->fig_y++;
	}
	api->points = (t_point**)malloc(sizeof(t_point*) * api->fig_y + 1);
	api->points[api->fig_y] = NULL;
	i = -1;
	while (++i < api->fig_y)
		api->points[i] = (t_point*)malloc(sizeof(t_point) * api->fig_x);
}

/*
**	Read and save map
*/
void			get_map(t_api *api, char *file)
{
	char	*line;
	int		x;
	int		y;
	int		i;

    api->fd = open(file, O_RDONLY);
	size_map(api);
	close(api->fd);
    api->fd = open(file, O_RDONLY);
	y = 0;
	while (get_next_line(api->fd, &line) > 0)
	{
		x = -1;
		i = -1;
		while (line[++i])
		{
			if (ft_isdigit(line[i]))
			{
				x++;
				api->points[y][x].x = x;
				api->points[y][x].y = y;
				api->points[y][x].z = ft_atoi(line + i);
				while (line[i + 1] && ft_isdigit(line[i]))
					i++;
			}
		}
		ft_strdel(&line);
		y++;
	}
}