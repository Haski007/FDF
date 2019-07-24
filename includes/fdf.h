/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:42:44 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/23 16:42:45 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# include "../libft/includes/libft.h"

# define PURPLE 0x800080

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_api
{
	void		*mlx;
	void		*win;
	void		*img;
	int			color;
}				t_api;

typedef struct	s_map
{
	t_list		*map;
	int			fd;
}				t_map;

int				show_error(const char *error);
void            get_map(t_map *map);
void			init_map(t_map *map);
void			draw_line(t_api *api, int x1, int x2, int y1, int y2);




#endif