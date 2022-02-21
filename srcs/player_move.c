/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:37:07 by jkieth            #+#    #+#             */
/*   Updated: 2022/01/25 17:47:08 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_exit(t_data *data_set)
{
	mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
		data_set->snow->img, data_set->character->x * 80,
		data_set->character->y * 80);
	mlx_destroy_window(data_set->mlx, data_set->mlx_win);
	printf("Number of steps - %d\n", ++data_set->count_move);
	free_data(data_set);
	exit(EXIT_FAILURE);
}

void	move_take_coin(t_data *data_set, int x, int y, char s)
{
	if (s == 'R')
	{
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->snow->img, data_set->character->x * 80,
			data_set->character->y * 80);
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->colect->img_take_r, x * 80, y * 80);
	}
	else if (s == 'L')
	{
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->snow->img, data_set->character->x * 80,
			data_set->character->y * 80);
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->colect->img_take_l, x * 80, y * 80);
	}
	data_set->character->y
		= data_set->character->y + (y - data_set->character->y);
	data_set->character->x
		= data_set->character->x + (x - data_set->character->x);
	data_set->map[y][x] = '0';
	data_set->collectible -= 1;
}

void	move_right(t_data *data_set, int x, int y)
{
	if (data_set->map[y][x] == 'C')
		move_take_coin(data_set, x, y, 'R');
	else if (data_set->map[y][x] != 'E' && data_set->map[y][x] != 'X')
	{
		data_set->character->img_stay = mlx_xpm_file_to_image(data_set->mlx,
				"sprites/nezuko_stay1.xpm",
				&data_set->character->width, &data_set->character->height);
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->snow->img, data_set->character->x * 80,
			data_set->character->y * 80);
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->character->img_walk1r, x * 80, y * 80);
		data_set->character->y
			= data_set->character->y + (y - data_set->character->y);
		data_set->character->x
			= data_set->character->x + (x - data_set->character->x);
	}
	else if ((data_set->map[y][x] == 'E'
		&& data_set->collectible == 0) || data_set->map[y][x] == 'X')
		move_exit(data_set);
	if (data_set->count_enemy > 0)
		move_enemies(data_set);
	if (data_set->map[y][x] == 'X')
		move_exit(data_set);
	printf("Number of steps - %d\n", ++data_set->count_move);
}

void	move_left(t_data *data_set, int x, int y)
{
	if (data_set->map[y][x] == 'C')
		move_take_coin(data_set, x, y, 'L');
	else if (data_set->map[y][x] != 'E' && data_set->map[y][x] != 'X')
	{
		data_set->character->img_stay = mlx_xpm_file_to_image(data_set->mlx,
				"sprites/nezuko_stay1l.xpm",
				&data_set->character->width, &data_set->character->height);
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->snow->img, data_set->character->x * 80,
			data_set->character->y * 80);
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->character->img_walk1l, x * 80, y * 80);
		data_set->character->y
			= data_set->character->y + (y - data_set->character->y);
		data_set->character->x
			= data_set->character->x + (x - data_set->character->x);
	}
	else if ((data_set->map[y][x] == 'E'
		&& data_set->collectible == 0) || data_set->map[y][x] == 'X')
		move_exit(data_set);
	if (data_set->count_enemy > 0)
		move_enemies(data_set);
	if (data_set->map[y][x] == 'X')
		move_exit(data_set);
	printf("Number of steps - %d\n", ++data_set->count_move);
}
