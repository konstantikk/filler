/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 22:13:31 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/25 22:13:31 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int			key_press(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void		ft_hook_loop(t_vis *map)
{
	mlx_hook(map->win_ptr, 2, 0, key_press, map);
}

void		find_map_size(t_game *game)
{
	char	*line;
	char	*buff;

	get_next_line(0, &buff);
	line = ft_strchr(buff, ' ');
	game->map_x = ft_atoi(line);
	line += (ft_intlen(game->map_x) + 1);
	game->map_y = ft_atoi(line);
	free(buff);
	game->scale = (1000) /
			(game->map_x > game->map_y ? game->map_x : game->map_y);
}

char		*player_name(void)
{
	char	*line;
	char	*buff;
	char	*subline;

	get_next_line(0, &buff);
	line = ft_strchr(buff, '/');
	subline = ft_strchr(buff, '.');
	ft_strdel(&buff);
	return (ft_strsub(line, 1, subline - line - 1));
}

void		read_gamers(t_game *game)
{
	char	*line;
	char	*buff;
	int		i;

	i = -1;
	while (++i < 5 && get_next_line(0, &line))
		ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	game->player1 = player_name();
	game->player2 = player_name();
	get_next_line(0, &buff);
	ft_strdel(&buff);
	find_map_size(game);
	game->p1 = 'O';
	game->p2 = 'X';
}
