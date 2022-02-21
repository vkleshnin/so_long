/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:01:26 by jkieth            #+#    #+#             */
/*   Updated: 2022/01/21 19:39:18 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*join_char(char *str, char symbol)
{
	char	*new_str;
	char	*cstr;
	int		i;

	new_str = malloc(sizeof(char) * ft_strlen(str) + 2);
	if (new_str == NULL)
		return (NULL);
	cstr = str;
	i = 0;
	while (*cstr)
		new_str[i++] = *cstr++;
	new_str[i++] = symbol;
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

int	check_file(char *filename)
{
	if (open(filename, O_DIRECTORY) != -1)
		return (1);
	if (open(filename, O_RDONLY) == -1)
		return (1);
	if (ft_strncmp(filename + (ft_strlen(filename) - 4), ".ber", 4) != 0)
		return (1);
	return (0);
}

char	**pars_map(char *filename)
{
	char	*line;
	char	**map;
	int		fd;
	char	buf;

	if (check_file(filename) == 1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	line = ft_strdup("");
	while (read(fd, &buf, 1) > 0)
		line = join_char(line, buf);
	close(fd);
	map = ft_split(line, '\n');
	if (map == NULL)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (map);
}
