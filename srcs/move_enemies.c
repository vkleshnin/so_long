/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:40 by jkieth            #+#    #+#             */
/*   Updated: 2022/01/19 18:25:26 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_move_down(t_data *data_set, int x, int y)
{
	mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
		data_set->snow->img, x * 80, y * 80);
	mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
		data_set->enemy_img->img_walk1, x * 80, (y + 1) * 80);
	data_set->enemies->enemy->y += 1;
	data_set->map[y][x] = '0';
	data_set->map[y + 1][x] = 'X';
}

void	enemy_move_up(t_data *data_set, int x, int y)
{
	mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
		data_set->snow->img, x * 80, y * 80);
	mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
		data_set->enemy_img->img_walk2, x * 80, (y - 1) * 80);
	data_set->enemies->enemy->y -= 1;
	data_set->map[y][x] = '0';
	data_set->map[y - 1][x] = 'X';
}

int	check_symbol(char symbol)
{
	if (symbol == '1' || symbol == 'C' || symbol == 'E' || symbol == 'X')
		return (0);
	return (1);
}

void	direction(int direction, t_data *data_set, int x, int y)
{
	if (direction == 0)
	{
		if (check_symbol(data_set->map[y + 1][x]) == 1)
			enemy_move_down(data_set, x, y);
		else
			data_set->enemies->enemy->direction = 1;
	}
	else if (direction == 1)
	{
		if (check_symbol(data_set->map[y - 1][x]) == 1)
			enemy_move_up(data_set, x, y);
		else
			data_set->enemies->enemy->direction = 0;
	}
}

void	move_enemies(t_data *data_set)
{
	int		x;
	int		y;
	t_list	*copy_enemies;

	copy_enemies = data_set->enemies;
	while (data_set->enemies)
	{
		x = data_set->enemies->enemy->x;
		y = data_set->enemies->enemy->y;
		direction(data_set->enemies->enemy->direction, data_set, x, y);
		data_set->enemies = data_set->enemies->next;
	}
	data_set->enemies = copy_enemies;
}
