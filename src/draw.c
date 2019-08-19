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

void			easyline(t_api *api, int x1, int y1, int x2, int y2)
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

	if (x2 <= x1)
    {
        ft_swap(&x1, &x2);
        ft_swap(&y1, &y2);
    }
	dx = (double)x2 - (double)x1;
	dy = (double)y2 - (double)y1;
	gradi = dy / dx;
	xend = round_(x1);
	yend = y1 + gradi * (xend - x1);
	xgap = rfpart_(x1 + 0.5);
	xpxl1 = xend;
	ypxl1 = ipart_(yend);
	mlx_pixel_put(api->mlx, api->win, xpxl1, ypxl1, get_percent_color(api->color, rfpart_(yend) * xgap));
	mlx_pixel_put(api->mlx, api->win, xpxl1, ypxl1 + 1, get_percent_color(api->color, fpart_(yend) * xgap));
	err = yend + gradi;
	xend = round_(x2);
	yend = y2 + gradi * (xend - x2);
	xgap = fpart_(x2 + 0.5);
	ypxl2 = ipart_(yend);
	xpxl2 = xend;
	mlx_pixel_put(api->mlx, api->win, xpxl2, ypxl2, get_percent_color(api->color, rfpart_(yend) * xgap));
	mlx_pixel_put(api->mlx, api->win, xpxl2 + 1, ypxl2, get_percent_color(api->color, fpart_(yend) * xgap));
	while (++xpxl1 < xpxl2)
	{
		mlx_pixel_put(api->mlx, api->win, xpxl1, ipart_(err), get_percent_color(api->color, rfpart_(err)));
		mlx_pixel_put(api->mlx, api->win, xpxl1, ipart_(err) + 1, get_percent_color(api->color, fpart_(err)));
		err += gradi;
	}
}

void			hardline(t_api *api, int x1, int y1, int x2, int y2)
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


	if (y2 < y1)
	{
		ft_swap(&x1, &x2);
		ft_swap(&y1, &y2);
	}
	dx = (double)x2 - (double)x1;
	dy = (double)y2 - (double)y1;
	gradi = dx / dy;
	yend = round_(y1);
	xend = x1 + gradi * (yend - y1);
	ygap = rfpart_(y1 + 0.5);
	ypxl1 = yend;
	xpxl1 = ipart_(xend);
	mlx_pixel_put(api->mlx, api->win, xpxl1, ypxl1, get_percent_color(api->color, rfpart_(xend) * ygap));
	mlx_pixel_put(api->mlx, api->win, xpxl1 + 1, ypxl1, get_percent_color(api->color, fpart_(xend) * ygap));
	err = xend + gradi;
	yend = round_(y2);
	xend = x2 + gradi * (yend - y2);
	ygap = fpart_(y2 + 0.5);
	ypxl2 = yend;
	xpxl2 = ipart_(xend);
	mlx_pixel_put(api->mlx, api->win, xpxl2, ypxl2, get_percent_color(api->color, rfpart_(xend) * ygap));
	mlx_pixel_put(api->mlx, api->win, xpxl2 + 1, ypxl2, get_percent_color(api->color, fpart_(xend) * ygap));
	while (++ypxl1 < ypxl2)
	{
		mlx_pixel_put(api->mlx, api->win, ipart_(err), ypxl1, get_percent_color(api->color, rfpart_(err)));
		mlx_pixel_put(api->mlx, api->win, ipart_(err) + 1, ypxl1, get_percent_color(api->color, fpart_(err)));
		err += gradi;
	}
}


void			draw(t_api *api)
{
	t_list	*list;
	t_line	*line;

	list = api->res;
	while (list)
	{
		line = (t_line*)list->content;
		if (fabs(line->x2 - line->x1) >= fabs(line->y2 - line->y1))
			easyline(api, line->x1, line->y1, line->x2, line->y2);
		else
			hardline(api, line->x1, line->y1, line->x2, line->y2);
		list = list->next;
	}
}