/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:53:20 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/24 20:53:24 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			pixel_put(t_api *api, int x, int y, int color)
{
	if (x < api->win_x && x >= 0 && 
		y < api->win_y && y >= 0)
	api->img_arr[y * api->win_x + x] = color;
}

void			easyline(t_api *api, t_line *line)
{
	double	gradi;
	double	xend;
	double	yend;
	double 	xgap;
	int 	xpxl1;
	int 	ypxl1;
	int		xpxl2;
	int		ypxl2;
	double	err;
	double	dx;
	double	dy;

	if (line->x2 <= line->x1)
    {
        ft_swap(&line->x1, &line->x2);
        ft_swap(&line->y1, &line->y2);
    }
	dx = (double)line->x2 - (double)line->x1;
	dy = (double)line->y2 - (double)line->y1;
	gradi = dy / dx;
	xend = round_(line->x1);
	yend = line->y1 + gradi * (xend - line->x1);
	xgap = rfpart_(line->x1 + 0.5);
	xpxl1 = xend;
	ypxl1 = ipart_(yend);
	pixel_put(api, xpxl1, ypxl1, get_percent_color(api->color, rfpart_(yend) * xgap));
	pixel_put(api, xpxl1, ypxl1 + 1, get_percent_color(api->color, fpart_(yend) * xgap));
	err = yend + gradi;
	xend = round_(line->x2);
	yend = line->y2 + gradi * (xend - line->x2);
	xgap = fpart_(line->x2 + 0.5);
	ypxl2 = ipart_(yend);
	xpxl2 = xend;
	pixel_put(api, xpxl2, ypxl2, get_percent_color(api->color, rfpart_(yend) * xgap));
	pixel_put(api, xpxl2 + 1, ypxl2, get_percent_color(api->color, fpart_(yend) * xgap));
	while (++xpxl1 < xpxl2)
	{
		pixel_put(api, xpxl1, ipart_(err), get_percent_color(api->color, rfpart_(err)));
		pixel_put(api, xpxl1, ipart_(err) + 1, get_percent_color(api->color, fpart_(err)));
		err += gradi;
	}
}

void			hardline(t_api *api, t_line *line)
{
	double		dx;
	double		dy;
	double		gradi;
	double		xend;
	double		yend;
	double		ygap;
	int 		xpxl1;
	int 		ypxl1;
	int			xpxl2;
	int			ypxl2;
	double		err;


	if (line->y2 < line->y1)
	{
		ft_swap(&line->x1, &line->x2);
		ft_swap(&line->y1, &line->y2);
	}
	dx = (double)line->x2 - (double)line->x1;
	dy = (double)line->y2 - (double)line->y1;
	gradi = dx / dy;
	yend = round_(line->y1);
	xend = line->x1 + gradi * (yend - line->y1);
	ygap = rfpart_(line->y1 + 0.5);
	ypxl1 = yend;
	xpxl1 = ipart_(xend);
	pixel_put(api, xpxl1, ypxl1, get_percent_color(api->color, rfpart_(xend) * ygap));
	pixel_put(api, xpxl1 + 1, ypxl1, get_percent_color(api->color, fpart_(xend) * ygap));
	err = xend + gradi;
	yend = round_(line->y2);
	xend = line->x2 + gradi * (yend - line->y2);
	ygap = fpart_(line->y2 + 0.5);
	ypxl2 = yend;
	xpxl2 = ipart_(xend);
	pixel_put(api, xpxl2, ypxl2, get_percent_color(api->color, rfpart_(xend) * ygap));
	pixel_put(api, xpxl2 + 1, ypxl2, get_percent_color(api->color, fpart_(xend) * ygap));
	while (++ypxl1 < ypxl2)
	{
		pixel_put(api, ipart_(err), ypxl1, get_percent_color(api->color, rfpart_(err)));
		pixel_put(api, ipart_(err) + 1, ypxl1, get_percent_color(api->color, fpart_(err)));
		err += gradi;
	}
}

static void		choose_your_destiny(t_api *api, t_line *line)
{
	if (abs(line->x2 - line->x1) >= abs(line->y2 - line->y1))
		easyline(api,line);
	else
		hardline(api,line);
}

/*
**	Connect two points by a Wu's line
*/
void		connect_pixels(t_api *api)
{
	int		y;
	int		x;
	t_line	*line;

	y = -1;
	while (++y < api->fig_y)
	{
		x = -1;
		while (++x < api->fig_x)
		{
			if (y < api->fig_y - 1)
			{
				line = (t_line*)malloc(sizeof(t_line));
				line->x1 = POINT.x;
				line->y1 = POINT.y;
				line->x2 = POINTD.x;
				line->y2 = POINTD.y;
				choose_your_destiny(api, line);
				free(line);
			}
			if (x < api->fig_x - 1)
			{
				line = (t_line*)malloc(sizeof(t_line));
				line->x1 = POINT.x;
				line->y1 = POINT.y;
				line->x2 = POINTR.x;
				line->y2 = POINTR.y;
				choose_your_destiny(api, line);
				free(line);
			}
		}
	}
	mlx_put_image_to_window(api->mlx, api->win, api->img, 0, 0);
	ft_bzero(api->img_arr, sizeof(int) * api->win_x * api->win_y);
}

/*
**	Make ready and draw
*/
void			draw(t_api *api)
{
	double	xyz[3];
	int		x;
	int		y;

	y = -1;
	while (++y < api->fig_y)
	{
		x = -1;
		while (++x < api->fig_x)
		{
			xyz[0] = (x - api->fig_x / 2) * api->zoom;
			xyz[1] = (y - api->fig_y / 2) * api->zoom;
			xyz[2] = api->points[y][x].z * api->zoom;
			make_isometric(api, xyz, 30);
			POINT.x = (int)xyz[0] + api->win_x / 2;
			POINT.y = (int)xyz[1] + api->win_y / 2;
		}
	}
	connect_pixels(api);
}