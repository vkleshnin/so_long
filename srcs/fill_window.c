/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:15:13 by jkieth            #+#    #+#             */
/*   Updated: 2021/12/03 17:26:29 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_data *data_set, int x, int y)
{
	if (data_set->map[y][x] == '1')
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->obstacle->img, x * 80, y * 80);
	if (data_set->map[y][x] == '0')
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->snow->img, x * 80, y * 80);
	if (data_set->map[y][x] == 'P')
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->character->img_stay, x * 80, y * 80);
	if (data_set->map[y][x] == 'E')
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->box->img_box1, x * 80, y * 80);
	if (data_set->map[y][x] == 'C')
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->colect->img1, x * 80, y * 80);
	if (data_set->map[y][x] == 'X')
		mlx_put_image_to_window(data_set->mlx, data_set->mlx_win,
			data_set->enemy_img->img_stay1, x * 80, y * 80);
}

void	fill_window(t_data *data_set)
{
	int	y;
	int	x;

	y = 0;
	while (y < data_set->count_lines)
	{
		x = -1;
		while (++x < data_set->symbols_in_line)
			check_map(data_set, x, y);
		y++;
	}
}
