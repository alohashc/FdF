/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:35:24 by alohashc          #+#    #+#             */
/*   Updated: 2017/02/25 12:36:20 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_string_put(t_img put)
{
	mlx_string_put(put.mlx, put.win, 50, 50, 11674146, "MOVE:");
	mlx_string_put(put.mlx, put.win, 50, 70, 2263842, "left     <");
	mlx_string_put(put.mlx, put.win, 50, 90, 2263842, "right    >");
	mlx_string_put(put.mlx, put.win, 50, 110, 2263842, "up       ^");
	mlx_string_put(put.mlx, put.win, 50, 130, 2263842, "down     v");
	mlx_string_put(put.mlx, put.win, 50, 150, 11674146, "ZOOM:");
	mlx_string_put(put.mlx, put.win, 50, 170, 49151, "in       +");
	mlx_string_put(put.mlx, put.win, 50, 190, 49151, "out      -");
	mlx_string_put(put.mlx, put.win, 50, 210, 11674146, "ROTATION:");
	mlx_string_put(put.mlx, put.win, 50, 230, 16753920, "axis Y - A,D");
	mlx_string_put(put.mlx, put.win, 50, 250, 16753920, "axis X - W,S");
	mlx_string_put(put.mlx, put.win, 525, 800, 16753920, "RESET: SPACE");
}

t_pos	ft_size_window(t_map *map, t_pos pos)
{
	t_map *tmp;

	tmp = map;
	pos.n = 1200 / (pos.width + pos.height);
	if (pos.n < 1)
		pos.n = 1;
	else if (pos.n > 20)
		pos.n = 20;
	while (tmp)
	{
		tmp->x1 = tmp->x;
		tmp->y1 = tmp->y;
		tmp->z1 = tmp->z;
		tmp->x = tmp->x * pos.n - pos.width * pos.n / 2;
		tmp->y = tmp->y * pos.n - pos.height * pos.n / 2;
		tmp->z = tmp->z * pos.n;
		tmp = tmp->next;
	}
	pos.a = 0;
	pos.b = 0;
	pos.d = 0;
	return (pos);
}
