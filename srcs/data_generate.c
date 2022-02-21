/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_generate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:40:42 by jkieth            #+#    #+#             */
/*   Updated: 2022/01/25 18:03:47 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

void	free_lists(t_list *enemies)
{
	t_list	*tmp;

	while (enemies)
	{
		tmp = enemies->next;
		free(enemies->enemy);
		free(enemies);
		enemies = tmp;
	}
	enemies = NULL;
}

void	free_data(t_data *data_set)
{
	if (data_set->character)
		free(data_set->character);
	data_set->character = NULL;
	if (data_set->obstacle)
		free(data_set->obstacle);
	data_set->obstacle = NULL;
	if (data_set->snow)
		free(data_set->snow);
	data_set->snow = NULL;
	if (data_set->colect)
		free(data_set->colect);
	data_set->colect = NULL;
	if (data_set->enemy_img)
		free(data_set->enemy_img);
	data_set->enemy_img = NULL;
	if (data_set->enemies)
		free_lists(data_set->enemies);
	data_set->enemies = NULL;
	if (data_set->box)
		free(data_set->box);
	data_set->box = NULL;
	if (data_set->map)
		free_matrix(data_set->map);
	free(data_set);
	data_set = NULL;
}

int	data_characters_generate(t_data *data_set)
{
	data_set->character = malloc(sizeof(t_character));
	if (data_set->character == NULL)
		return (1);
	data_set->obstacle = malloc(sizeof(t_obstacle));
	if (data_set->obstacle == NULL)
		return (1);
	data_set->snow = malloc(sizeof(t_snow));
	if (data_set->snow == NULL)
		return (1);
	data_set->colect = malloc(sizeof(t_colect));
	if (data_set->colect == NULL)
		return (1);
	data_set->box = malloc(sizeof(t_exit));
	if (data_set->box == NULL)
		return (1);
	data_set->enemy_img = malloc(sizeof(t_enemy_path));
	if (data_set->enemy_img == NULL)
		return (1);
	data_set->enemies = malloc(sizeof(t_list));
	if (data_set->enemies == NULL)
		return (1);
	data_set->enemies->enemy = NULL;
	data_set->enemies->next = NULL;
	return (0);
}

t_data	*data_generate(char *filename)
{
	t_data	*data_set;

	data_set = malloc(sizeof(t_data));
	if (data_set == NULL)
		return (NULL);
	data_set->count_lines = 0;
	data_set->symbols_in_line = 0;
	data_set->player = 0;
	data_set->exit = 0;
	data_set->collectible = 0;
	data_set->count_move = 0;
	if (data_characters_generate(data_set) == 1)
		free_data(data_set);
	data_set->map = pars_map(filename);
	if (data_set->map == NULL)
		func_error(2, data_set);
	return (data_set);
}
