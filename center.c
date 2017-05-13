/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:18:06 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/06 12:18:11 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	ft_reset_map(t_pos pos)
{
	t_map *tmp;

	tmp = pos.map;
	while (tmp)
	{
		tmp->x = tmp->x1;
		tmp->y = tmp->y1;
		tmp->z = tmp->z1;
		tmp = tmp->next;
	}
	return (pos);
}

t_pos	ft_center_cd(t_pos pos)
{
	t_map *tmp;

	tmp = pos.map;
	while (tmp)
	{
		tmp->x = tmp->x + CEN_X + pos.move_x;
		tmp->y = tmp->y + CEN_Y + pos.move_y;
		tmp = tmp->next;
	}
	return (pos);
}

t_pos	ft_back_cd(t_pos pos)
{
	t_map *tmp;

	tmp = pos.map;
	while (tmp)
	{
		tmp->x = tmp->x - CEN_X - pos.move_x;
		tmp->y = tmp->y - CEN_Y - pos.move_y;
		tmp = tmp->next;
	}
	return (pos);
}
