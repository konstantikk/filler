/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:41:20 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/11 18:41:20 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_func.h"

void		del_char_arr(char ***arr, int len)
{
	int i;

	i = 0;
	if (!*arr || !**arr)
		return ;
	while (i < len)
		free(*((*arr) + i++));
	free(*arr);
}

void		del_int_arr(int ***arr, int len)
{
	int i;

	i = 0;
	if (!*arr || !**arr)
		return ;
	while (i <= len)
		free(*((*arr) + i++));
	free(*arr);
}

char		**create_char_map(int matrix_x, int matrix_y)
{
	char	**matrix;
	int		i;

	i = 0;
	if (!(matrix = (char **)ft_memalloc(matrix_x + 1)))
		return (NULL);
	while (i < matrix_x)
		if (!(*(matrix + i++) = (char *)ft_memalloc(matrix_y + 1)))
			return (NULL);
	return (matrix);
}

char		**create_map(t_filler *fill, char **map)
{
	char	*line;
	char	*buff;
	int		i;

	if (!map)
		if (!(map = create_char_map(fill->map_x, fill->map_y)) ||
		!(fill->int_map = int_map(fill)) ||
		!(fill->int_enemy_map = int_map(fill)))
			return (NULL);
	i = 0;
	while (i < fill->map_x)
	{
		get_next_line(0, &buff);
		line = ft_strchr(buff, ' ');
		*(map + i) = ft_strcpy(*(map + i), ++line);
		i++;
		ft_strdel(&buff);
	}
	return (map);
}

int			**int_map(t_filler *fill)
{
	int **arr;
	int i;

	if (!(arr = (int **)ft_memalloc(sizeof(int) * (fill->map_x + 1))))
		return (NULL);
	i = -1;
	while (++i < fill->map_x)
		if (!(*(arr + i) = (int *)ft_memalloc(sizeof(int) * (fill->map_y + 1))))
			return (NULL);
	return (arr);
}
