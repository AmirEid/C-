# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 23:45:59 by aeid              #+#    #+#              #
#    Updated: 2024/10/11 01:13:57 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = SedLosers
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CC = g++
FLAGS = -Wall -Wextra -Werror

BLUE = \033[0;34m
NC = \033[0m
GREEN = \033[0;32m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME) Complete...$(NC)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@echo "$(BLUE)Hello Darkness My Old Friend $<...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)Looking for object files? 😛$(NC)"
	@echo "$(GREEN)DELETED!$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Looking for binary files? 😛$(NC)"
	@echo "$(GREEN)DELETED!$(NC)"

re: fclean all

.PHONY: all clean fclean re
