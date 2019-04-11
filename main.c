#include <stdio.h>
# include "filler_func.h"
#include <fcntl.h>

t_place		ft_init_coord()
{
	t_place		coord;

	coord.x = 6666;
	coord.y = 6666;
	coord.min = 10000;
	return (coord);
}

void		find_your_player(t_filler *fill)
{
	char		*line;

	get_next_line(0, &line);
	free(line);
	line = ft_strchr(line, 'p');
	fill->player = (*(++line) == '1') ? 'O' : 'X';
	fill->enemy = (fill->player == 'X') ? 'O' : 'X';
	fill->fd = open("file_test", O_WRONLY);///todo del
}

int main()
{
	t_filler	fill;
	char		**map = NULL;
	t_piece		*token ;
	int 		flag = 1;
	t_place		coord;

	find_your_player(&fill);
	while (flag)
	{
		coord = ft_init_coord();
		fill = ft_read(fill, map);
		token = read_token(&fill);
		flag = ft_put_token(&fill, token, coord);
	}
	return (0);
}