/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:06:04 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/19 22:03:01 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int             key_press(int keycode, void *param)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

void    ft_hook_loop(t_vis      *map)
{
	mlx_hook(map->win_ptr, 2, 0, key_press, map);
}

void	find_map_size(t_game *game, void *param)
{
	char	*line;
	char	*buff;

	get_next_line(0, &buff);
	line = ft_strchr(buff, ' ');
	game->map_x = ft_atoi(line);
	line += (ft_intlen(game->map_x) + 1);
	game->map_y = ft_atoi(line);
	free(buff);
	game->scale_x = SCREEN_HEI / game->map_x;
	game->scale_y = (SCREEN_WID - 500) / game->map_y;
}

void	read_gamers(t_game *game, void *param)
{
	char	*line;
	char 	*buff;
	char 	*subline;
	int 	i;

	i = -1;
	while (++i < 5 && get_next_line(0, &line))
		ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	get_next_line(0, &buff);
	line = ft_strchr(buff, '/');
	subline = ft_strchr(buff, '.');
	game->player1 = ft_strsub(line, 1, subline - line - 1);
	ft_strdel(&buff);
	get_next_line(0, &buff);
	line = ft_strchr(buff, '/');
	subline = ft_strchr(buff, '.');
	game->player2 = ft_strsub(line, 1, subline - line - 1);
	ft_strdel(&buff);
	get_next_line(0, &buff);
	ft_strdel(&buff);
	find_map_size(game, param);
	game->p1 = 'O';
	game->p2 = 'X';
}

void	ranking_players(void *param, t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->map_x)
	{
		j = -1;
		while (++j < game->map_y)
			if (game->map[i][j] == game->p1)
				color_cell(param, COLOR_P1, i, j, game);
			else if (game->map[i][j] == game->p2)
				color_cell(param, COLOR_P2, i, j, game);
	}
}

void	read_token(t_game *token, void *param, int step)
{
	char	*line;
	int		i;
	char	*buff;
	int 	j;

	get_next_line(0, &buff);
	line = buff;
	if (!(line = ft_strchr(line, ' ')))
		return ;
	token->piece_x = ft_atoi(line);
	line = ft_strchr(++line, ' ');
	token->piece_y = ft_atoi(line);
	ft_strdel(&buff);
	if (!(token->piece = create_char_map(token->piece_x, token->piece_y)))
		return ;//todo
	i = -1;
	while (++i < token->piece_x)
	{
		get_next_line(0, &buff);
		*(token->piece + i) = ft_strcpy(*(token->piece + i), buff);
		ft_strdel(&buff);
	}
	i = -1;
/**
 * need calculate scale
 **/
	while (++i < token->piece_x)
	{
		j = -1;
		while (++j < token->piece_y)
		{
			if (token->piece[i][j] == '*')
				color_cell(param, 0x8EB7D1, i + token->scale_x / 10, j + SCREEN_WID - 500, token);
			else
				color_cell(param, COLOR_MAP, i + token->scale_x / 10, j + SCREEN_WID - 500, token);
		}
	}
	del_char_arr(&(token->piece), token->piece_x);
}

int		main()
{
	t_vis	*param;
	t_game	*game;
	int		step;
	int		flag = 1;
	char 	*buff;

	game = (t_game*)ft_memalloc(sizeof(t_game));
	param = init();
	read_gamers(game, param);
	step = (SCREEN_WID - 500 - ft_strlen(game->player1) - ft_strlen(game->player2)) / 6;
	game->player1_step = SCREEN_WID - 500 + step / 2;
	game->player2_step = SCREEN_WID - 500 + 2 * step + ft_strlen(game->player1);
	game->map = create_map(game, game->map);

	ft_exp_background(param, game);
	read_token(game, param, step);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);

	mlx_string_put(MLX_PTR, WIN_PTR, game->player1_step, 80, 0xEDD32B, game->player1);
	mlx_string_put(MLX_PTR, WIN_PTR, game->player2_step, 80, 0x90BBD4, game->player2);
	mlx_string_put(MLX_PTR, WIN_PTR, SCREEN_WID - 500 + 5, 120, 0xffffff, "Score :");
	/*while (1)
	{
		get_next_line(0, &buff);
		ft_strdel(&buff);
		get_next_line(0, &buff);
		if (!(ft_strchr(buff, 'P')))
		{
			ft_hook_loop(param);
			mlx_loop(MLX_PTR);
			return (0); /// game over
		}
		//printf("!!%s\n", buff);
		ft_strdel(&buff);
		//printf("%s\n", buff);
		create_map(game, game->map);
		ranking_players(param, game);
		read_token(game, param, step);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr,
				0, 0);
		mlx_string_put(MLX_PTR, WIN_PTR, game->player1_step, 80, 0xffffff,
				game->player1);
		mlx_string_put(MLX_PTR, WIN_PTR, game->player2_step, 80, 0xffffff,
				game->player2);
		mlx_string_put(MLX_PTR, WIN_PTR, SCREEN_WID - 500 + 5, 120, 0xffffff,
				"Score :");

	}*/
	//mlx_expose_hook(WIN_PTR, ft_exp_background, param);
	//filler_attack(param, game);

	ft_hook_loop(param);
	mlx_loop(MLX_PTR);
	return (0);
}