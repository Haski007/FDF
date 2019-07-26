/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:34:46 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/26 18:35:15 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			easyline(t_api *api, int x1, int y1, int x2, int y2)
{
	t_pxl	*pxl;
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
	ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
		rfpart_(yend) * xgap), xpxl1, ypxl1), sizeof(t_pxl)));
	free(pxl);
	ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
		fpart_(yend) * xgap), xpxl1, ypxl1 + 1), sizeof(t_pxl)));
	free(pxl);
	err = yend + gradi;
	xend = round_(x2);
	yend = y2 + gradi * (xend - x2);
	xgap = fpart_(x2 + 0.5);
	xpxl2 = ipart_(yend);
	ypxl2 = xend;
	ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
		rfpart_(yend) * xgap), xpxl2, ypxl2), sizeof(t_pxl)));
	free(pxl);
	ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
		fpart_(yend) * xgap), xpxl2 + 1, ypxl2), sizeof(t_pxl)));
	free(pxl);
	while (++xpxl1 < xpxl2)
	{
		ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
			rfpart_(err)), xpxl1, ipart_(err)), sizeof(t_pxl)));
		free(pxl);
		ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
			fpart_(err)), xpxl1, ipart_(err) + 1), sizeof(t_pxl)));
		free(pxl);
		err += gradi;
	}
}

void			hardline(t_api *api, int x1, int y1, int x2, int y2)
{
	t_pxl		*pxl;
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
	///start
	yend = round_(y1);
	xend = x1 + gradi * (yend - y1);
	ygap = rfpart_(y1 + 0.5);
	ypxl1 = yend;
	xpxl1 = ipart_(xend);
	ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
		rfpart_(xend) * ygap), xpxl1, ypxl1), sizeof(t_pxl)));
	free(pxl);
	ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
		fpart_(xend) * ygap), xpxl1 + 1, ypxl1), sizeof(t_pxl)));
	free(pxl);
	err = xend + gradi;
	///end
	yend = round_(y2);
	xend = x2 + gradi * (yend - y2);
	ygap = fpart_(y2 + 0.5);
	ypxl2 = yend;
	xpxl2 = ipart_(xend);
	ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
		rfpart_(xend) * ygap), xpxl2, ypxl2), sizeof(t_pxl)));
	free(pxl);
	ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
		fpart_(xend) * ygap), xpxl2 + 1, ypxl2), sizeof(t_pxl)));
	free(pxl);
	while (++ypxl1 < ypxl2)
	{
		ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
			rfpart_(err)), ipart_(err), ypxl1), sizeof(t_pxl)));
		free(pxl);
		ft_lstpush(&api->res, ft_lstnew(pxl = make_pxl(get_percent_color(api->color,
			fpart_(err)), ipart_(err) + 1, ypxl1), sizeof(t_pxl)));
		free(pxl);
		err += gradi;
	}
}

void			save_line(t_api *api, int x1, int y1, int x2, int y2)
{
	int 	y;
	int		x;

	if (abs(x2 - x1) >= abs(y2 - y1))
		easyline(api, x1, y1, x2, y2);
	else
		hardline(api, x1, y1, x2, y2);
}
