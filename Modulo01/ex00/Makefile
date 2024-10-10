# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 23:21:41 by aeid              #+#    #+#              #
#    Updated: 2024/10/09 23:47:21 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie
SRC = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)

CPP = g++
CPPFLAGS = -Wall -Wextra -Werror

BLUE = \033[0;34m
NC = \033[0m
GREEN = \033[0;32m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling $(NAME) Complete...$(NC)"
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@echo "$(BLUE)Hello Darkness My Old Friend $<...$(NC)"
	@$(CPP) $(CPPFLAGS) -c $< -o $@

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