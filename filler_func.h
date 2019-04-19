/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:42:10 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/18 22:42:10 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FUNC_H
# define FILLER_FUNC_H
# include "ft_filler.h"

/*
**	first_step.c
*/
int				check_place(t_filler *fill, t_vec *token, int x, int y);
int				find_optimal(t_filler *fill, t_vec *vec_coord, int f);
int				ft_vm_overshoot(t_place coord);
int				ft_put_token(t_filler *fill, t_piece *token, t_place coord);
t_vec			*fill_enemy_map(t_filler *fill, int x, int y, t_vec *token);
t_vec			*fill_my_map(t_filler *fill, int x, int y, t_vec *token);
int				recount_int_enemy_map(int **matrix, int map_x, int map_y);
int				recount_int_map(t_filler *fill, int map_x, int map_y);
/*
**	ft_makevec.c
*/
t_vec			*ft_makevec();
void			ft_vec_pop_front(t_vec *vec);
void			ft_vec_push_back(t_vec *vec, int x, int y);
void			ft_free_vec(t_vec **vec);
/*
**	map_creater.c
*/
char			**create_map(t_filler *fill, char **map);
t_vec			*create_coord_token(char **piece, t_piece *token);
int				**int_map(t_filler *fill);
/*
**	parse.c
*/
t_filler		*ft_read(t_filler *fill);
t_piece			*read_token(t_piece *token);
void			del_char_arr(char ***arr, int len);
void			del_int_arr(int ***arr, int len);
char			**create_char_map(int matrix_x, int matrix_y);

#endif
