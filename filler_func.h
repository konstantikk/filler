/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:25:55 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/11 19:25:55 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FUNC_H
# define FILLER_FUNC_H
# include "ft_filler.h"

/*
**	first_step.c
*/
int			check_place(t_filler *fill, t_piece *token, int x, int y);
t_vec		*fill_matrix(t_filler *fill, int x, int y, t_piece *token, int f);
int			find_optimal(t_filler *fill, t_vec *vec_coord, int f);
int			ft_vm_overshoot(t_place coord, t_piece *token, t_filler *fill);
int			ft_put_token(t_filler *fill, t_piece *token, t_place coord);
/*
**	ft_makevec.c
*/
t_vec		*ft_makevec();
void		ft_vec_pop_front(t_vec *vec);
void		ft_vec_push_back(t_vec *vec, int x, int y);
void		ft_free_vec(t_vec **vec);
/*
**	map_creater.c
*/
void		del_arr(void ***arr);
char 		**create_map(t_filler *fill, char **map);
t_vec		*create_coord_token(char **piece, t_piece *token);
int 		**int_map(t_filler fill);
/*
**	parse.c
*/
t_filler	ft_read(t_filler fill, char **map);
t_piece		*read_token(t_filler *fill);

#endif
