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
	api->img_arr[y * api->win_x + x] = api->color;
}

// void			easyline(t_api *api, int x1, int y1, int x2, int y2)
// {
// 	double	gradi;
// 	double	xend;
// 	double	yend;
// 	double 	xgap;
// 	int 	xpxl1;
// 	int 	ypxl1;
// 	int		xpxl2;
// 	int		ypxl2;
// 	double	err;
// 	double	dx;
// 	double	dy;

// 	if (x2 <= x1)
//     {
//         ft_swap(&x1, &x2);
//         ft_swap(&y1, &y2);
//     }
// 	dx = (double)x2 - (double)x1;
// 	dy = (double)y2 - (double)y1;
// 	gradi = dy / dx;
// 	xend = round_(x1);
// 	yend = y1 + gradi * (xend - x1);
// 	xgap = rfpart_(x1 + 0.5);
// 	xpxl1 = xend;
// 	ypxl1 = ipart_(yend);
// 	pixel_put(api, xpxl1, ypxl1, get_percent_color(api->color, rfpart_(yend) * xgap));
// 	pixel_put(api, xpxl1, ypxl1 + 1, get_percent_color(api->color, fpart_(yend) * xgap));
// 	err = yend + gradi;
// 	xend = round_(x2);
// 	yend = y2 + gradi * (xend - x2);
// 	xgap = fpart_(x2 + 0.5);
// 	ypxl2 = ipart_(yend);
// 	xpxl2 = xend;
// 	pixel_put(api, xpxl2, ypxl2, get_percent_color(api->color, rfpart_(yend) * xgap));
// 	pixel_put(api, xpxl2 + 1, ypxl2, get_percent_color(api->color, fpart_(yend) * xgap));
// 	while (++xpxl1 < xpxl2)
// 	{
// 		pixel_put(api, xpxl1, ipart_(err), get_percent_color(api->color, rfpart_(err)));
// 		pixel_put(api, xpxl1, ipart_(err) + 1, get_percent_color(api->color, fpart_(err)));
// 		err += gradi;
// 	}
// }

// void			hardline(t_api *api, int x1, int y1, int x2, int y2)
// {
// 	double		dx;
// 	double		dy;
// 	double		gradi;
// 	double		xend;
// 	double		yend;
// 	double		ygap;
// 	int 		xpxl1;
// 	int 		ypxl1;
// 	int			xpxl2;
// 	int			ypxl2;
// 	double		err;


// 	if (y2 < y1)
// 	{
// 		ft_swap(&x1, &x2);
// 		ft_swap(&y1, &y2);
// 	}
// 	dx = (double)x2 - (double)x1;
// 	dy = (double)y2 - (double)y1;
// 	gradi = dx / dy;
// 	yend = round_(y1);
// 	xend = x1 + gradi * (yend - y1);
// 	ygap = rfpart_(y1 + 0.5);
// 	ypxl1 = yend;
// 	xpxl1 = ipart_(xend);
// 	pixel_put(api, xpxl1, ypxl1, get_percent_color(api->color, rfpart_(xend) * ygap));
// 	pixel_put(api, xpxl1 + 1, ypxl1, get_percent_color(api->color, fpart_(xend) * ygap));
// 	err = xend + gradi;
// 	yend = round_(y2);
// 	xend = x2 + gradi * (yend - y2);
// 	ygap = fpart_(y2 + 0.5);
// 	ypxl2 = yend;
// 	xpxl2 = ipart_(xend);
// 	pixel_put(api, xpxl2, ypxl2, get_percent_color(api->color, rfpart_(xend) * ygap));
// 	pixel_put(api, xpxl2 + 1, ypxl2, get_percent_color(api->color, fpart_(xend) * ygap));
// 	while (++ypxl1 < ypxl2)
// 	{
// 		pixel_put(api, ipart_(err), ypxl1, get_percent_color(api->color, rfpart_(err)));
// 		pixel_put(api, ipart_(err) + 1, ypxl1, get_percent_color(api->color, fpart_(err)));
// 		err += gradi;
// 	}
// }

t_line		*save_line(double x1, double y1, double x2, double y2)
{
	t_line	*line;

	line = (t_line*)malloc(sizeof(t_line));
	line->x1 = x1;
	line->y1 = y1;
	line->x2 = x2;
	line->y2 = y2;
	return (line);
}

/*
**	Connect two points by a Wu's line
*/
static void		connect_pixels(t_api *api, t_line *line)
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;

	x1 *= size_
	if (fabs(x2 - x1) >= fabs(y2 - y1))
		easyline(api, x1, y1, x2, y2);
	else
		hardline(api, x1, y1, x2, y2);
}

/*
**	Collect 2 points to draw it
*/
void			draw(t_api *api)
{
	t_list		*points;
	t_point		*p;

	points = api->points;
	while (points)
	{
		p = (t_point*)points->content;
		connect_pixels(api, p, ())
		points = points->next;
	}
	mlx_put_image_to_window(api->mlx, api->win, api->img, 0, 0);
	ft_bzero(api->img_arr, sizeof(int) * api->win_x * api->win_y);
}