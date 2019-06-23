/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:01:40 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/28 18:33:04 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# define IMG			((t_vis*)param)->image
# define IMG_PTR		((t_vis*)param)->img_ptr
# define BITS_PER_PIXEL ((t_vis*)param)->bits_per_pixel
# define SIZE_LINE	  ((t_vis*)param)->size_line
# define ENDIAN		 ((t_vis*)param)->endian
# define _DATA		  ((t_vis*)param)->data
# define WIN_PTR		((t_vis*)param)->win_ptr
# define MLX_PTR		((t_vis*)param)->mlx_ptr
# define SCREEN_WID	 ((t_vis*)param)->screen_width
# define SCREEN_HEI	 ((t_vis*)param)->screen_height
# define COLOR_P1  0x735a82///FD4D0C purpur
# define COLOR_PP1 0xc0a6cf//FF571A
# define COLOR_FILL2 0x42334a//832401

# define COLOR_P2 0x5a7d82//FCBA12 akvamarin
# define COLOR_PP2 0xa6cacf//FFBB0F
# define COLOR_FILL1 0x33484a//A38948

# define COLOR_BACKGROUND 0x191e28//a2b0af//464646
# define COLOR_MAP 0x0f1218//191e28//191e28////515B6B

# define COLOR_LINE 0x232a38//414141
# define COLOR_WIN 0x9E0F0F

# include "visualizer.h"
# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <mlx.h>

typedef struct	s_coord
{
	int x1;
	int	y1;
	int x2;
	int	y2;
}				t_coord;

typedef struct	s_vec
{
	int		*x;
	int		*y;
	int		*start_x;
	int		*start_y;
	size_t	cap;
	size_t	len;
}				t_vec;

typedef struct	s_game
{
	char		who;
	char		p1;
	char		p2;
	int			map_x;
	int			map_y;
	int			piece_x;
	int			piece_y;
	char		*player1;
	char		*player2;
	char		**map;
	char		**piece;
	int			player1_step;
	int			player2_step;
	int			scale;
	int			**int_map;
	int			token_scale;
	int			score1;
	int			score2;
	float		area1;
	float		area2;
	int			centre_x;
	int			centre_y;
	unsigned	dead1:1;
	unsigned	dead2:1;
}				t_game;

typedef struct	s_visualize
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
	t_game	*game;
}				t_vis;

/*
**area.c
*/
t_vec			*fill_matrix(int **matrix, char enemy, char player,
				t_game *fill);
int				**check_displacement(t_vec *vec_coord, int **matrix,
				int map_x, int map_y);
int				count_area(t_game *game, int **map);
void			print_area_string(t_game *game, t_vis *param);
/*
**draw_helper.c
*/
t_coord			*init_coord(int x1, int y1, int x2, int y2);
/*
**draw_lines_color.c
*/
void			draw_line(void *param, t_coord *coord);
void			print_matrix(t_game *game, void *param);
int				ft_exp_background(void *p, t_game *game);
void			color_cell(void *param, int color, int x, int y);
void			paint_area(t_vis *param, t_game *game, int **int_map);
/*
**ft_game.c
*/
void			ranking_players(void *param, t_game *game);
void			check_area(t_game *game, t_vis *param);
int				game_over(t_vis *param, t_game *game);
void			maybe_sm1_dead(t_vis *param, t_game *game);
void			count_score(t_game *game);
/*
**ft_makevec.c
*/
t_vec			*ft_makevec(void);
void			ft_vec_pop_front(t_vec *vec);
void			help_push_back(t_vec *vec, int x, int y);
void			ft_vec_push_back(t_vec *vec, int x, int y);
void			ft_free_vec(t_vec **vec);
/*
**init.c
*/
t_vis			*init(t_game *game);
/*
**main.c
*/
int				ft_game_loop(void *p);
/*
**map_creater.c
*/
void			del_char_arr(char ***arr, int len);
void			del_int_arr(int ***arr, int len);
char			**create_char_map(int matrix_x, int matrix_y);
char			**create_map(t_game *fill, char **map);
int				**int_map(t_game *fill);
/*
**parse_start_game.c
*/
int				key_press(int keycode, void *param);
void			ft_hook_loop(t_vis *map);
void			find_map_size(t_game *game);
char			*player_name();
void			read_gamers(t_game *game);
/*
**print_string.c
*/
void			dead_string(t_vis *param, t_game *game);
void			print_string(t_game *game, t_vis *param);
void			who_line(t_vis *param, size_t len, t_game *game, int f);
/*
**token_manipulation.c
*/
void			read_token(t_game *token);
void			paint_token(t_game *token, void *param, int color);
void			color_cell_token(void *param, int color, int x, int y);
#endif
