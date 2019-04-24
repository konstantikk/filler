/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:14:58 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/19 22:01:25 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VISUALIZER_H
# define _VISUALIZER_H

# include "./libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>

# define IMG            ((t_vis*)param)->image
# define IMG_PTR        ((t_vis*)param)->img_ptr
# define BITS_PER_PIXEL ((t_vis*)param)->bits_per_pixel
# define SIZE_LINE      ((t_vis*)param)->size_line
# define ENDIAN         ((t_vis*)param)->endian
# define _DATA          ((t_vis*)param)->data

# define WIN_PTR		((t_vis*)param)->win_ptr
# define MLX_PTR		((t_vis*)param)->mlx_ptr
# define SCREEN_WID     ((t_vis*)param)->screen_width
# define SCREEN_HEI     ((t_vis*)param)->screen_height

typedef struct	s_image
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		*data;
}				t_image;

typedef struct  s_visualize
{   
	void	*mlx_ptr;
	void	*win_ptr;
	int		screen_width;
	int		screen_height;
	int		*data;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}               t_vis;

typedef struct	s_game
{
	char 	p1;
	char 	p2;
	int 	map_x;
	int 	map_y;
	int		piece_x;
	int 	piece_y;
	char 	*player1;
	char 	*player2;
	char 	**map;
	char 	**piece;
	int 	player1_step;
	int 	player2_step;
	int 	scale_x;
	int		scale_y;
}				t_game;

t_vis	*init(void);
int 	ft_exp_background(void *p, t_game *game);
char	**create_map(t_game *fill, char **map);
char	**create_char_map(int matrix_x, int matrix_y);
void	del_char_arr(char ***arr, int len);
void	ranking_players(void *param, t_game *game);
void	read_gamers(t_game *game, void *param);
void	find_map_size(t_game *game, void *param);
void	print_matrix(t_game *game, void	*param);
void	draw_line(void *param, int x1, int y1, int x2, int y2);
void	color_cell(void *param, int color, int x, int y, t_game *game);

#endif
