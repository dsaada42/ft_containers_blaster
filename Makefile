# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:36:39 by dsaada            #+#    #+#              #
#    Updated: 2023/01/03 14:02:45 by dsaada           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

vector :
	@./run_tests.sh test_container vector

stack :
	@./run_tests.sh test_container stack
	
map :
	@./run_tests.sh test_container map

set :
	@./run_tests.sh test_container set

all :
	@./run_tests.sh test_containers

clean :
	@rm -rf logs
	@rm -rf diffs

fclean : clean

re : fclean all

.PHONY: all vector clean fclean re