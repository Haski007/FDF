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
# include <math.h>

# include "../libft/includes/libft.h"

# define ipart_(X) ((int)(X))
# define round_(X) ((int)(((double)(X))+0.5))
# define fpart_(X) (((double)(X))-(double)ipart_(X))
# define rfpart_(X) (1.0-fpart_(X))
# define swap_(a, b) do{ __typeof__(a) tmp;  tmp = a; a = b; b = tmp; }while(0)


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
	t_list		*res;
	int			color;
}				t_api;

typedef	struct	s_pxl
{
	int			x;
	int			y;
	int			color;
}				t_pxl;

typedef struct	s_map
{
	t_list		*map;
	int			fd;
}				t_map;

int				show_error(const char *error);
void            get_map(t_map *map);
void			init_structures(t_map *map, t_api *api);
void			save_line(t_api *api, int x1, int x2, int y1, int y2);
int				get_percent_color(int color, double percent);
t_pxl			*make_pxl(int color, int x, int y);
void			draw(t_api *api, t_map *map);



#endif