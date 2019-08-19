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

# define PURPLE 0x800080

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			i;
}				t_point;

typedef struct	s_api
{
	void		*mlx;
	void		*win;
	void		*img;
	t_list		*res;
	int			**map;
	int			color;
	int			size_x;
	int			size_y;
	int			len_x;
	int			len_y;
	int			fd;
	int			m_x;
	int			m_y;
	int			zoom;
}				t_api;

typedef	struct	s_line
{
	double		x1;
	double		y1;
	int			z1;
	double		x2;
	double		y2;
	int			z2;
	int			color;
}				t_line;


int				show_error(const char *error);
void            get_map(t_api *api, char *av);
void			init_structures(t_api *api);
void			save_line(t_api *api, int x1, int x2, int y1, int y2);
int				get_percent_color(int color, double percent);
void			draw(t_api *api);
void			draw_xyz(t_api *api);
int				do_something(int key, t_api *api);
void			connect_pixels(t_api *api);
int				centr_x(t_api *api, int x);
int				centr_y(t_api *api, int y);
void			clear_screen(t_api *api);
void			isometrical(t_api *api);
void			zoom_plus(t_api *api);
void			zoom_minus(t_api *api);
void			move_fiqure(t_api *api, int key);
void			rotate_fiqure(t_api *api, int key);






void			paint_map(t_api *api);


#endif