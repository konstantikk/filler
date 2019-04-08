#include <stdio.h>
# include "filler_func.h"

int main()
{
	t_filler fill;
	char **map = NULL;
	t_piece *token;

	find_your_player(&fill);
	fill = ft_read(fill);
	printf("\n%c\n%c\nx: %d\ty: %d\n", fill.player,fill.enemy, fill.map_x,
			fill.map_y);
	fill.map = create_map(&fill, map);
	for (int i = 0; i < fill.map_x; i++)
	{
		for (int j = 0; j < fill.map_y; j++)
			printf("%c", fill.map[i][j]);
		printf("\n");
	}
	token = read_token();
	for (int i =0; i < (int) token->token->len; i++)
		printf("%d\t%d\n", token->token->x[i],token->token->y[i]);

	ft_put_token(&fill, token);
	return (0);
}