/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:54:33 by jkieth            #+#    #+#             */
/*   Updated: 2022/01/25 18:10:00 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# define W 13
# define S 1
# define A 0
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef struct s_obstacle {
	void		*img;
	int			width;
	int			height;
}	t_obstacle;

typedef struct s_snow {
	void		*img;
	int			width;
	int			height;
}	t_snow;

typedef struct s_character {
	void		*img_stay;
	void		*img_walk1r;
	void		*img_walk1l;
	int			width;
	int			height;
	int			x;
	int			y;
}	t_character;

typedef struct s_colect {
	void		*img1;
	void		*img2;
	void		*img_take_r;
	void		*img_take_l;
	int			width;
	int			height;
}	t_colect;

typedef struct s_enemy {
	int		x;
	int		y;
	int		direction;
}	t_enemy;

typedef struct s_enemy_path {
	void		*img_stay1;
	void		*img_walk1;
	void		*img_walk2;
	int			width;
	int			height;
}	t_enemy_path;

typedef struct s_list {
	t_enemy			*enemy;
	struct s_list	*next;
}	t_list;

typedef struct s_exit {
	void		*img_box1;
	int			width;
	int			height;
}	t_exit;

typedef struct s_data {
	void			*mlx;
	void			*mlx_win;
	int				count_lines;
	int				symbols_in_line;
	int				collectible;
	int				exit;
	int				count_enemy;
	int				player;
	int				count_move;
	t_obstacle		*obstacle;
	t_snow			*snow;
	t_character		*character;
	t_colect		*colect;
	t_list			*enemies;
	t_enemy_path	*enemy_img;
	t_exit			*box;
	char			**map;
}	t_data;

int			ft_strlen(const char *s);
char		**pars_map(char *filename);
int			check_valid_map(t_data *data_set);
char		*ft_strdup(const char *s1);
void		free_matrix(char **str);
char		**ft_split(char const *s, char c);
void		fill_window(t_data *data_set);
void		free_data(t_data *data_set);
t_data		*data_generate(char *filename);
void		path_img(t_data *data_set);
void		move_left(t_data *data_set, int x, int y);
void		move_right(t_data *data_set, int x, int y);
void		move_take_coin(t_data *data_set, int x, int y, char s);
void		move_exit(t_data *data_set);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		move_enemies(t_data *data_set);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			func_error(int num_error, t_data *data_set);
void		free_lists(t_list *enemies);

#endif /*SO_LONG_H*/
