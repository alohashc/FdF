/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:48:55 by alohashc          #+#    #+#             */
/*   Updated: 2017/02/23 15:31:36 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_rotation(int keycode, t_pos *pos)
{
	if (keycode == 13 || keycode == 1)
	{
		pos->b = 0;
		pos->b += keycode == 13 ? RAD_F : RAD_B;
		pos->a = 0;
		pos->zoom = 1;
	}
	else if (keycode == 0 || keycode == 2)
	{
		pos->b = 0;
		pos->a = 0;
		pos->a += keycode == 0 ? RAD_F : RAD_B;
		pos->zoom = 1;
	}
	mlx_clear_window(pos->put.mlx, pos->put.win);
	ft_image(*pos);
}

void	ft_key_zoom(int keycode, t_pos *pos)
{
	if (keycode == 69 || keycode == 78)
	{
		pos->a = 0;
		pos->b = 0;
		pos->zoom = keycode == 69 ? 1.1 : 0.9;
		pos->n *= pos->zoom;
		if ((pos->n < 2 || pos->n > 40) && pos->temp_zoom >= 3)
		{
			if (pos->n > 40)
				pos->n = 40;
			if (pos->n < 2)
				pos->n = 2;
			pos->zoom = 1;
		}
		if ((pos->n < 0.5 || pos->n > 8) && pos->temp_zoom < 2)
		{
			if (pos->n > 8)
				pos->n = 8;
			if (pos->n < 0.5)
				pos->n = 0.5;
			pos->zoom = 1;
		}
	}
	mlx_clear_window(pos->put.mlx, pos->put.win);
	ft_image(*pos);
}

void	ft_key_move(int keycode, t_pos *pos)
{
	if (keycode == 126)
		pos->move_y -= 10;
	if (keycode == 125)
		pos->move_y += 10;
	if (keycode == 123)
		pos->move_x -= 10;
	if (keycode == 124)
		pos->move_x += 10;
	mlx_clear_window(pos->put.mlx, pos->put.win);
	ft_center_cd(*pos);
	ft_create_img(pos->map, *pos, pos->put);
}

int		ft_press_key(int keycode, t_pos *pos)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		ft_key_rotation(keycode, pos);
	if (keycode == 69 || keycode == 78)
		ft_key_zoom(keycode, pos);
	if (keycode == 125 || keycode == 126 || keycode == 123 || keycode == 124)
		ft_key_move(keycode, pos);
	if (keycode == 49)
	{
		pos->zoom = 1;
		pos->move_y = 0;
		pos->move_x = 0;
		mlx_clear_window(pos->put.mlx, pos->put.win);
		*pos = ft_reset_map(*pos);
		ft_size_window(pos->map, *pos);
		ft_center_cd(*pos);
		ft_create_img(pos->map, *pos, pos->put);
	}
	return (0);
}
