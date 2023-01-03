# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:36:39 by dsaada            #+#    #+#              #
#    Updated: 2023/01/03 10:55:28 by dsaada           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

VECTOR_TEST_FILES = $(wildcard ./tests/vector/*.cpp)
MAP_TEST_FILES = $(wildcard ./tests/map/*.cpp)
STACK_TEST_FILES = $(wildcard ./tests/stack/*.cpp)
SET_TEST_FILES = $(wildcard ./tests/set/*.cpp)

vector : $(VECTOR_TEST_FILES)
	@./run_vector_tests.sh $(VECTOR_TEST_FILES)
	
all : vector

clean :
	@rm -rf logs
	@rm -rf diffs

fclean : clean

re : fclean all

.PHONY: all vector clean fclean re