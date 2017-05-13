/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:46:22 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/06 11:34:03 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line_x(t_map *map, t_img put)
{
	t_map *tmp;
	t_map *tmp1;

	tmp = map;
	tmp1 = tmp->next;
	while (tmp1)
	{
		if (tmp->x1 == tmp1->x1)
		{
			ft_draw_line(tmp, tmp1, put);
			tmp = tmp->next;
			tmp1 = tmp->next;
		}
		else
			tmp1 = tmp1->next;
	}
}

void	ft_draw_line_y(t_map *map, t_img put)
{
	t_map	*tmp;
	t_map	*tmp1;

	tmp = map;
	tmp1 = tmp->next;
	while (tmp->next)
	{
		if (tmp1->y1 == tmp->y1)
			ft_draw_line(tmp, tmp1, put);
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
}

void	ft_create_img(t_map *map, t_pos pos, t_img put)
{
	t_map	*tmp;

	tmp = map;
	put.img = mlx_new_image(put.mlx, 1200, 900);
	put.data = mlx_get_data_addr(put.img, &put.bpp, &put.size_l, &put.endian);
	ft_draw_line_x(tmp, put);
	ft_draw_line_y(tmp, put);
	mlx_put_image_to_window(put.mlx, put.win, put.img, 0, 0);
	mlx_destroy_image(put.mlx, put.img);
	ft_string_put(put);
	pos = ft_back_cd(pos);
	mlx_hook(put.win, 2, 5, ft_press_key, &pos);
	mlx_loop(put.mlx);
}
