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

t_pxl			*make_pxl(int color, int x, int y)
{
	t_pxl	*pxl;

	pxl = (t_pxl*)malloc(sizeof(t_pxl));
	pxl->x = x;
	pxl->y = y;
	pxl->color = color;
	return (pxl);
}

t_point			*make_point(int x, int y, int z)
{
	t_point	*point;
	
	point = (t_point*)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_list			*get_row(char *line, int y)
{
	t_list	*list;
	t_point	*point;
	int		i;
	int		x;

	list = NULL;
	x = 0;
	i = -1;
	ft_lstpush(&list, ft_lstnew(point = make_point(x, y, ft_atoi(line + i)), sizeof(t_point)));
	free(point);
	while (line[++i])
	{
		if (line[i + 1] >= '0' && line[i + 1] <= '9' && line[i] == ' ')
		{
			ft_lstpush(&list, ft_lstnew(point = make_point(++x, y, ft_atoi(line + i)), sizeof(t_point)));
			free(point);
		}
	}
	return (list);
}


void			get_map(t_map *map)
{
	char	*line;
	int		y;
	t_list	*tmp;

	y = -1;
	while (get_next_line(map->fd, &line))
	{
		if (line[0] == '\0')
			break ;
		ft_lstpush(&map->map, ft_lstnew(tmp = get_row(line, ++y), sizeof(t_list)));
		free(tmp);
		ft_strdel(&line);
	}
}