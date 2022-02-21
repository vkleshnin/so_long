/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:38:15 by jkieth            #+#    #+#             */
/*   Updated: 2022/01/25 18:14:30 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_data *data_set)
{
	mlx_destroy_window(data_set->mlx, data_set->mlx_win);
	free_data(data_set);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data_set)
{
	int	x;
	int	y;

	x = data_set->character->x;
	y = data_set->character->y;
	if ((keycode == W || keycode == UP) && data_set->map[y - 1][x] != '1')
		move_right(data_set, x, y - 1);
	if ((keycode == S || keycode == DOWN) && data_set->map[y + 1][x] != '1')
		move_right(data_set, x, y + 1);
	if ((keycode == A || keycode == LEFT) && data_set->map[y][x - 1] != '1')
		move_left(data_set, x - 1, y);
	if ((keycode == D || keycode == RIGHT) && data_set->map[y][x + 1] != '1')
		move_right(data_set, x + 1, y);
	if (keycode == ESC)
		exit_game(data_set);
	return (0);
}

int	stay(t_data *data_set)
{
	int		i;
	t_list	*copy_enemies;

	i = 0;
	while (i < 70000000)
		i++;
	mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
		data_set->character->img_stay, data_set->character->x * 80,
		data_set->character->y * 80);
	if (data_set->count_enemy > 0)
	{
		copy_enemies = data_set->enemies;
		while (copy_enemies)
		{
			mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
				data_set->enemy_img->img_stay1, copy_enemies->enemy->x * 80,
				copy_enemies->enemy->y * 80);
			copy_enemies = copy_enemies->next;
		}
	}
	return (0);
}

int	func_error(int num_error, t_data *data_set)
{
	if (num_error == 1)
		printf("Memory allocation error\n");
	if (num_error == 2)
	{
		printf("Invalid map\n");
		free_data(data_set);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	*data_set;

	if (argc != 2)
		return (1);
	data_set = data_generate(argv[1]);
	if (data_set == NULL)
		return (func_error(1, data_set));
	if (check_valid_map(data_set) == 0)
	{
		data_set->mlx = mlx_init();
		path_img(data_set);
		data_set->mlx_win = mlx_new_window(data_set->mlx,
				(data_set->symbols_in_line * 80),
				(data_set->count_lines * 80), "so_long");
		fill_window(data_set);
		mlx_key_hook(data_set->mlx_win, key_hook, data_set);
		mlx_hook(data_set->mlx_win, 17, 0, exit_game, data_set);
		mlx_loop_hook(data_set->mlx, stay, data_set);
		mlx_loop(data_set->mlx);
	}
	else
		func_error(2, data_set);
	free_data(data_set);
	return (0);
}
