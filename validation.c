/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:23:08 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/06 12:23:12 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		my_isalpha(char c)
{
	if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

void	ft_validation_color(char *str, int i)
{
	int	count;

	count = 0;
	i++;
	while (str[i])
	{
		count++;
		if ((str[i] != '0' && count == 1) || (str[i] != 'x' && count == 2))
		{
			ft_putendl("\033\e[91mNot valid color");
			exit(0);
		}
		if (count >= 3 && (my_isalpha(str[i]) == 0 && my_isdigit(str[i]) == 0))
		{
			ft_putendl("\033\e[91mNot valid color");
			exit(0);
		}
		i++;
	}
	if (count < 3 && count > 8)
	{
		ft_putendl("\033\e[91mNot valid color");
		exit(0);
	}
}

void	ft_check_alpha(char *str)
{
	while (*str && *str != ',')
	{
		if (ft_isalpha(*str) == 1)
		{
			ft_putendl("\033\e[91mNot valid map");
			exit(0);
		}
		str++;
	}
}

void	ft_validation(t_pos *pos, int temp)
{
	if (pos->width != temp && pos->height != 0)
	{
		ft_putendl("\033\e[91mNot valid map");
		exit(0);
	}
}
