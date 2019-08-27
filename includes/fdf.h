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
# define ZOOM(X) X * api->zoom
# define POINT api->points[y][x]
# define POINTD api->points[y + 1][x]
# define POINTR api->points[y][x + 1]

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
	int			*img_arr;
	t_point		**points;
	int			color;
	int			win_x;
	int			win_y;
	int			fig_x;
	int			fig_y;
	int			fd;
	int			zoom;
}				t_api;

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_line;



int				show_error(const char *error);
void            get_map(t_api *api, char *av);
int				get_percent_color(int color, double percent);
void			draw_xyz(t_api *api);
// void			pixel_put(t_api *api, int x, int y, int color);
int				manage_key(int key, t_api *api);
void			rotate_figure(t_api *api, int key);
void			draw(t_api *api);
void			move_figure(t_api *api, int key);
void			make_isometric(t_api *api, double xyz[3]);
void			connect_pixels(t_api *api);









void			paint_map(t_api *api);


#endif