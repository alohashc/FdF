/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:57:34 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/06 12:28:25 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "./libft/libft.h"
# define RAD		0.017453292519943
# define RAD_F		-5
# define RAD_B		5
# define CEN_X		600
# define CEN_Y		450

typedef struct		s_map
{
	float			x;
	float			y;
	float			z;
	float			x1;
	float			y1;
	float			z1;
	int				color;
	struct s_map	*next;
}					t_map;

typedef struct		s_draw
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	float			e;
	float			e2;
	int				color;
}					t_draw;

typedef struct		s_img
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				endian;
	int				size_l;
	char			*data;
}					t_img;

typedef struct		s_pos
{
	float			width;
	float			height;
	float			zoom;
	float			temp_zoom;
	float			move_x;
	float			move_y;
	float			n;
	float			a;
	float			b;
	float			d;
	t_map			*map;
	t_img			put;
}					t_pos;

void				ft_image(t_pos pos);
void				ft_draw_line(t_map *map, t_map *map1, t_img put);
void				ft_create_img(t_map *map, t_pos pos, t_img put);
int					ft_press_key(int keycode, t_pos *pos);
void				ft_string_put (t_img put);
void				ft_validation(t_pos *pos, int temp);
void				ft_validation_color(char *str, int i);
void				ft_check_alpha(char *str);
t_pos				ft_size_window(t_map *map, t_pos pos);
t_pos				ft_center_map(t_pos pos);
t_pos				ft_back_cd(t_pos pos);
t_pos				ft_center_cd(t_pos pos);
t_pos				ft_reset_map(t_pos pos);

#endif
