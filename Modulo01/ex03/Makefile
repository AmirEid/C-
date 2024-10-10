# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 18:17:55 by aeid              #+#    #+#              #
#    Updated: 2024/10/10 18:18:54 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = UnnecessaryViolence
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror

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