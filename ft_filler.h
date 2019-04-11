/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:12:16 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/03 20:12:16 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "./libft/libft.h"
# include <stdio.h>

struct		s_filler
{
	char			player;
	char 			enemy;
	char 			**map;
	int				map_x;
	int				map_y;
	int 			**int_map;
	int 			**int_enemy_map;
	int				fd;///todo del

}typedef	t_filler;

struct		s_vec
{
	int		*x;
	int		*y;
	size_t	cap;
	size_t	len;
} typedef	t_vec;

struct		s_piece
{
	int		piece_x;
	int		piece_y;
	t_vec	*token;
}typedef	t_piece;

struct		s_best_place
{
	int min;
	int x;
	int	y;
}typedef	t_place;

#endif
