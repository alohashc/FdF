/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:04:59 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/06 11:26:28 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_img put, t_draw draw)
{
	int		i;

	if (draw.x1 > 0 && draw.x1 < 1200)
	{
		i = draw.x1 * put.bpp / 8 + draw.y1 * put.size_l;
		if (i < 900 * put.size_l && i >= 0)
		{
			put.data[i] = draw.color;
			put.data[++i] = draw.color >> 8;
			put.data[++i] = draw.color >> 16;
		}
	}
}

int		ft_sign(int c, int c1)
{
	if (c < c1)
		return (1);
	else
		return (-1);
}

int		ft_color(int color)
{
	if (!color)
		color = 16777215;
	return (color);
}

void	ft_draw_line(t_map *map, t_map *map1, t_img put)
{
	t_draw	draw;

	draw.x1 = map->x;
	draw.y1 = map->y;
	draw.x2 = map1->x;
	draw.y2 = map1->y;
	draw.dx = abs(draw.x2 - draw.x1);
	draw.dy = abs(draw.y2 - draw.y1);
	draw.e = draw.dx - draw.dy;
	draw.color = ft_color(map->color);
	while (draw.x1 != draw.x2 || draw.y1 != draw.y2)
	{
		ft_pixel_put(put, draw);
		draw.e2 = draw.e * 2;
		if (draw.e2 > -draw.dy)
		{
			draw.e -= draw.dy;
			draw.x1 += ft_sign(draw.x1, draw.x2);
		}
		if (draw.e2 < draw.dx)
		{
			draw.e += draw.dx;
			draw.y1 += ft_sign(draw.y1, draw.y2);
		}
	}
}
