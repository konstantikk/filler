# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jziemann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 18:25:39 by jziemann          #+#    #+#              #
#    Updated: 2019/06/23 18:09:05 by jziemann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
COMPILE_FLAGS =  -lmlx -framework OpenGL -framework AppKit -O3
NAME = filler_visualizer
ADD_SRC = ./src/
RESOURCES = area.c draw_helper.c draw_lines_color.c ft_game.c ft_makevec.c init.c main.c map_creater.c parse_start_game.c print_string.c token_manipulation.c
SRC_S = $(addprefix $(ADD_SRC), $(RESOURCES))
OBJ = $(SRC_S:.c=.o)
ADD_INC = ./includes/
ADD_LIB_H = ./libft/
ADD_LIBFT = ./libft/libft.a
ADD_MLX = ./minilibx_macos

all: $(NAME)

$(NAME):  $(OBJ)
	@make  -C ./libft all
	@$(COMPILER) -o $(NAME)  $(COMPILE_FLAGS) $(OBJ) $(ADD_LIBFT) -L $(ADD_MLX)
	@echo ======[Done]======
%.o : %.c
	@echo "$(NAME) >>> Add/Update $<"
	@$(COMPILER) -c -o $@ -I $(ADD_INC) $<
clean:
	@rm -f $(ADD_SRC)$(OBJ)
	@make  -C ./libft clean
fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
re: fclean all
