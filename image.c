/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:22:45 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/06 12:22:49 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_rotate_z(t_map *map, t_pos pos)
{
	t_map	*tmp;
	float	x2;

	tmp = map;
	pos.d *= RAD;
	x2 = tmp->x;
	tmp->x = (x2 * cos(pos.d) + tmp->y * sin(pos.d)) * pos.zoom;
	tmp->y = (tmp->y * cos(pos.d) - x2 * sin(pos.d)) * pos.zoom;
	return (map);
}

t_map	*ft_rotate_x(t_map *map, t_pos pos)
{
	t_map	*tmp;
	float	y2;

	tmp = map;
	pos.b *= RAD;
	y2 = tmp->y;
	tmp->y = (y2 * cos(pos.b) + tmp->z * sin(pos.b)) * pos.zoom;
	tmp->z = (tmp->z * cos(pos.b) - y2 * sin(pos.b)) * pos.zoom;
	return (map);
}

t_map	*ft_rotate_y(t_map *map, t_pos pos)
{
	t_map	*tmp;
	float	x2;

	tmp = map;
	pos.a *= RAD;
	x2 = tmp->x;
	tmp->x = (x2 * cos(pos.a) + tmp->z * sin(pos.a)) * pos.zoom;
	tmp->z = (tmp->z * cos(pos.a) - x2 * sin(pos.a)) * pos.zoom;
	return (map);
}

t_pos	ft_rotation(t_map **map, t_pos pos)
{
	t_map	*tmp;

	tmp = *map;
	while (tmp)
	{
		tmp = ft_rotate_x(tmp, pos);
		tmp = ft_rotate_y(tmp, pos);
		tmp = ft_rotate_z(tmp, pos);
		tmp = tmp->next;
	}
	return (pos);
}

void	ft_image(t_pos pos)
{
	pos = ft_rotation(&pos.map, pos);
	pos = ft_center_cd(pos);
	ft_create_img(pos.map, pos, pos.put);
}
