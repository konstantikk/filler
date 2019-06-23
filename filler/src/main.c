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
	coord.area = 0;
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

void		free_all(t_filler *fill, t_piece *token)
{
	free(token);
	del_char_arr(&(fill->map), fill->map_x);
	del_int_arr(&(fill->int_enemy_map), fill->map_x);
	del_int_arr(&(fill->int_map), fill->map_x);
	free(fill);
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
		if (!(fill = ft_read(fill)))
			return (0);
		if (!(token = read_token(token)))
			return (0);
		flag = ft_put_token(fill, token, coord);
		ft_free_vec(&(token->token));
	}
	free_all(fill, token);
	return (0);
}
