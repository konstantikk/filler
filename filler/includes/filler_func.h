/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 13:21:44 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/28 14:53:27 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FUNC_H
# define FILLER_FUNC_H

# include <stdio.h>
# include "filler_func.h"
# include "libft.h"

extern int		g_count;

typedef struct	s_filler
{
	char	player;
	char	enemy;
	char	**map;
	int		map_x;
	int		map_y;
	int		**int_map;
	int		**int_enemy_map;
}				t_filler;

typedef struct	s_vec
{
	int		*x;
	int		*y;
	int		*start_x;
	int		*start_y;
	size_t	cap;
	size_t	len;
}				t_vec;

typedef struct	s_best_place
{
	int		min;
	int		x;
	int		y;
	int		area;
}				t_place;

typedef struct	s_piece
{
	int		piece_x;
	int		piece_y;
	t_vec	*token;
	char	**piece;
}				t_piece;

/*
**find_optimal_place.c
*/
t_vec			*fill_matrix(int **matrix, char enemy, char player,
			t_filler *fill);
t_vec			*fill_enemy_map(t_filler *fill, int x, int y, t_vec *token);
t_vec			*fill_my_map(t_filler *fill, int x, int y, t_vec *token);
int				**check_displacement(t_vec *vec_coord, int **matrix,
			int map_x, int map_y);
int				find_optimal(t_filler *fill, t_vec *vec_coord, int f);
/*
**first_step.c
*/
int				check_place(t_filler *fill, t_vec *token, int x, int y);
int				recount_int_map(t_filler *fill, int map_x, int map_y);
int				recount_int_enemy_map(int **matrix, int map_x, int map_y);
int				ft_vm_overshoot(t_place coord);
int				ft_put_token(t_filler *fill, t_piece *token, t_place coord);
/*
**ft_makevec.c
*/
t_vec			*ft_makevec(void);
void			ft_vec_pop_front(t_vec *vec);
int				help_push_back(t_vec *vec, int x, int y);
int				ft_vec_push_back(t_vec *vec, int x, int y);
void			ft_free_vec(t_vec **vec);
/*
**main.c
*/
t_place			ft_init_coord(void);
char			find_my_player(void);
/*
**map_creater.c
*/
void			del_char_arr(char ***arr, int len);
void			del_int_arr(int ***arr, int len);
char			**create_char_map(int matrix_x, int matrix_y);
char			**create_map(t_filler *fill, char **map);
int				**int_map(t_filler *fill);
/*
**max_area.c
*/
int				max_area(int **matrix, int map_x, int map_y);
void			fill_coord(t_place *coord, t_filler *fill, int i, int j);
/*
**parse.c
*/
t_filler		*ft_read(t_filler *fill);
t_piece			*read_token(t_piece *token);
t_vec			*create_coord_token(char **piece, t_piece *token);
#endif
