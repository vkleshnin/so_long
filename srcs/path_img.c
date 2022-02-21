/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:55:57 by jkieth            #+#    #+#             */
/*   Updated: 2021/12/15 17:05:25 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	path_img_player(t_data *data_set)
{
	data_set->character->img_stay = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/nezuko_stay1.xpm",
			&data_set->character->width, &data_set->character->height);
	data_set->character->img_walk1r = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/nezuko_walk1r.xpm",
			&data_set->character->width, &data_set->character->height);
	data_set->character->img_walk1l = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/nezuko_walk1l.xpm",
			&data_set->character->width, &data_set->character->height);
}

void	path_img_box(t_data *data_set)
{
	data_set->box->img_box1 = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/box1.xpm",
			&data_set->box->width, &data_set->box->height);
}

void	path_img_coin(t_data *data_set)
{
	data_set->colect->img1 = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/coin1.xpm",
			&data_set->colect->width, &data_set->colect->height);
	data_set->colect->img_take_r = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/take_coin_r.xpm",
			&data_set->colect->width, &data_set->colect->height);
	data_set->colect->img_take_l = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/take_coin_l.xpm",
			&data_set->colect->width, &data_set->colect->height);
}

void	path_img_enemy(t_data *data_set)
{
	data_set->enemy_img->img_stay1 = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/enemy_stay1.xpm",
			&data_set->enemy_img->width, &data_set->enemy_img->height);
	data_set->enemy_img->img_walk1 = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/enemy_walk1.xpm",
			&data_set->enemy_img->width, &data_set->enemy_img->height);
	data_set->enemy_img->img_walk2 = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/enemy_walk2.xpm",
			&data_set->enemy_img->width, &data_set->enemy_img->height);
}

void	path_img(t_data *data_set)
{
	path_img_player(data_set);
	path_img_box(data_set);
	path_img_coin(data_set);
	path_img_enemy(data_set);
	data_set->obstacle->img = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/obstacle.xpm",
			&data_set->obstacle->width, &data_set->obstacle->height);
	data_set->snow->img = mlx_xpm_file_to_image(data_set->mlx,
			"sprites/snow.xpm",
			&data_set->snow->width, &data_set->snow->height);
}
