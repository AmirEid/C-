# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 17:32:00 by aeid              #+#    #+#              #
#    Updated: 2024/10/20 17:52:52 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HI_THIS_IS_BRAIN
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

BLUE = \033[0;34m
NC = \033[0m
GREEN = \033[0;32m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling $(NAME) Complete...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@echo "$(BLUE)Hello Darkness My Old Friend $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(GREEN)Looking for object files? 😛$(NC)"
	@echo "$(GREEN)DELETED!$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Looking for binary files? 😛$(NC)"
	@echo "$(GREEN)DELETED!$(NC)"

re: fclean all

.PHONY: all clean fclean re