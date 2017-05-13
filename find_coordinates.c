/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:04:26 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/06 12:03:54 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_remove_last(t_map *map)
{
	t_map *tmp;

	tmp = map;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

int		read_color(char *str)
{
	char	*color;
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			ft_validation_color(str, i);
			while (str[i] != 'x' && str[i] != '\0')
				i++;
			color = ft_strsub(str, i + 1, 6);
			result = ft_atoi_hex(color);
		}
		i++;
	}
	return (result);
}

t_map	*find_cd(t_map *cd, int y, char *line, t_pos *pos)
{
	int		x;
	int		z;
	char	**arr;
	int		temp;

	x = 0;
	arr = ft_strsplit(line, ' ');
	temp = pos->width;
	pos->width = 0;
	while (*arr)
	{
		ft_check_alpha(*arr);
		z = ft_atoi(*arr);
		cd->y = y;
		cd->x = x;
		cd->z = z;
		cd->color = read_color(*arr);
		cd->next = malloc(sizeof(t_map));
		cd = cd->next;
		arr++;
		x++;
		pos->width++;
	}
	ft_validation(pos, temp);
	return (cd);
}

t_pos	read_map(int fd)
{
	t_map	*cd;
	t_map	*tmp;
	int		y;
	char	*line;
	t_pos	pos;

	y = 0;
	pos.height = 0;
	cd = malloc(sizeof(t_map));
	tmp = cd;
	while (get_next_line(fd, &line))
	{
		tmp = find_cd(tmp, y, line, &pos);
		y++;
		pos.height++;
	}
	ft_remove_last(cd);
	pos.map = cd;
	return (pos);
}

int		main(int ac, char **av)
{
	int		fd;
	t_pos	pos;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (-1);
		pos = read_map(fd);
		pos.zoom = 1;
		pos.move_y = 0;
		pos.move_x = 0;
		pos = ft_size_window(pos.map, pos);
		pos.temp_zoom = pos.n;
		pos.put.mlx = mlx_init();
		pos.put.win = mlx_new_window(pos.put.mlx, 1200, 900, "window");
		ft_image(pos);
	}
	else
	{
		ft_putstr("\033\e[91musage: ");
		ft_putstr(av[0]);
		ft_putendl(" input_file.fdf");
	}
	return (0);
}
