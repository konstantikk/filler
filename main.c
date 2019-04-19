/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:11:12 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/19 17:11:23 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_func.h"

t_place		ft_init_coord(void)
{
	t_place		coord;

	coord.x = 6666;
	coord.y = 6666;
	coord.min = INT32_MAX;
	return (coord);
}

char		find_my_player(void)
{
	char	player;
	char	*buff;
	int		i;

	get_next_line(0, &buff);
	i = 0;
	while (buff[i] && buff[i] != 'p')
		i++;
	player = (buff[++i] == '1') ? 'O' : 'X';
	free(buff);
	return (player);
}

int			main(void)
{
	t_filler	*fill;
	t_piece		*token;
	int			flag;
	t_place		coord;

	flag = 1;
	fill = (t_filler *)ft_memalloc(sizeof(t_filler));
	fill->player = find_my_player();
	fill->enemy = (fill->player == 'X') ? 'O' : 'X';
	token = (t_piece *)ft_memalloc(sizeof(t_piece));
	while (flag)
	{
		coord = ft_init_coord();
		fill = ft_read(fill);
		token = read_token(token);
		flag = ft_put_token(fill, token, coord);
		ft_free_vec(&(token->token));
	}
	free(token);
	del_char_arr(&(fill->map), fill->map_x);
	del_int_arr(&(fill->int_enemy_map), fill->map_x);
	del_int_arr(&(fill->int_map), fill->map_x);
	free(fill);
	return (0);
}
