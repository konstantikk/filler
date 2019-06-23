# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jziemann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 14:37:42 by jziemann          #+#    #+#              #
#    Updated: 2019/04/28 14:59:14 by jziemann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
CHECK_FLAGS = -Wall -Wextra -Werror
NAME = jziemann.filler
ADD_SRC = ./src/
RESOURCES = find_optimal_place.c main.c parse.c first_step.c map_creater.c ft_makevec.c max_area.c
SRC_S = $(addprefix $(ADD_SRC), $(RESOURCES))
OBJ = $(SRC_S:.c=.o)
ADD_INC = ./includes/
ADD_LIB_H = ./libft/
ADD_LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):  $(OBJ)
	@make  -C ./libft all
	@$(COMPILER) -o $(NAME) $(CHECK_FLAGS) $(OBJ) $(ADD_LIBFT)
	@echo ======[Done]======
	@cp $(NAME) players/
%.o : %.c
	@echo "$(NAME) >>> Add/Update $<"
	@$(COMPILER) -c -o $@ -I $(ADD_INC) $(CHECK_FLAGS) $<
clean:
	@rm -f $(ADD_SRC)$(OBJ)
	@make  -C ./libft clean
fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
re: fclean all
