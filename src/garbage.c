/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:29:22 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/24 17:29:58 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			paint_map(t_map *map)
{
	t_list	*list;
	t_list	*row;
	t_point	*point;

	list = map->map;
	while (list)
	{
		row = (t_list*)list->content;
		while (row)
		{
			point = (t_point*)row->content;
			printf("%3d", point->z);
			row = row->next;
		}
		printf("\n");
		list = list->next;
	}
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
	ft_lstpush(&list, ft_lstnew(make_point(x, y, ft_atoi(line + i)), sizeof(t_point)));
	while (line[++i])
	{
		if (line[i + 1] >= '0' && line[i + 1] <= '9' && line[i] == ' ')
			ft_lstpush(&list, ft_lstnew(point = make_point(++x, y, ft_atoi(line + i)), sizeof(t_point)));
	}
	return (list);
}
