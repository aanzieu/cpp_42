# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/05 12:05:27 by aanzieu           #+#    #+#              #
#    Updated: 2018/10/05 16:21:48 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= day03

SRC		= FragTrap.cpp \
			ScavTrap.cpp \
			ClapTrap.cpp \
			NinjaTrap.cpp \
			SuperTrap.cpp \
			main.cpp 

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CFLAG) $(SRC) $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created"

./objects/%.o: ./sources/%.cpp
	mkdir -p objects
	clang++ -c $< -o $@

clean:
	rm -rf objects
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned"

re: fclean all

.PHONY: clean fclean re all test