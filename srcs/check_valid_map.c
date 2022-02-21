/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:53:17 by jkieth            #+#    #+#             */
/*   Updated: 2022/01/21 21:26:21 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 ** return values:
 ** 0 - valid
 ** -1 - invalid
*/

void	add_enemy(t_data *data_set, int x, int y)
{
	t_enemy	*enemy;
	t_list	*tmp;

	enemy = malloc(sizeof(t_enemy));
	enemy->x = x;
	enemy->y = y;
	enemy->direction = 0;
	if (!data_set->enemies->enemy)
	{
		tmp = data_set->enemies;
		data_set->enemies = ft_lstnew(enemy);
		free_lists(tmp);
	}
	else
		ft_lstadd_back(&data_set->enemies, ft_lstnew(enemy));
}

void	write_characters(char buf, t_data *data_set, int x, int y)
{
	if (buf == 'P')
	{
		data_set->player += 1;
		data_set->character->x = x;
		data_set->character->y = y;
	}
	if (buf == 'E')
		data_set->exit += 1;
	if (buf == 'C')
		data_set->collectible += 1;
	if (buf == 'X')
	{
		data_set->count_enemy++;
		add_enemy(data_set, x, y);
	}
}

int	check_characters(t_data *data_set)
{
	if (data_set->player != 1)
		return (-1);
	if (data_set->collectible < 1)
		return (-1);
	if (data_set->exit < 1)
		return (-1);
	return (0);
}

int	check_valid_map(t_data *data_set)
{
	int		i;
	int		j;

	while (data_set->map[data_set->count_lines])
		data_set->count_lines++;
	data_set->symbols_in_line = ft_strlen(data_set->map[0]);
	i = -1;
	while (data_set->map[++i])
	{
		j = 0;
		while (data_set->map[i][j])
		{
			if ((i == 0 || i == (data_set->count_lines - 1) || j == 0
					|| j == (data_set->symbols_in_line - 1))
				&& data_set->map[i][j] != '1')
				return (-1);
			write_characters(data_set->map[i][j], data_set, j, i);
			j++;
		}
		if (j != data_set->symbols_in_line)
			return (-1);
	}
	return (check_characters(data_set));
}
