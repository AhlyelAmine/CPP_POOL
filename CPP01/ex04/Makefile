# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 00:55:32 by aahlyel           #+#    #+#              #
#    Updated: 2023/10/18 01:35:09 by aahlyel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = 
NAME = replace
SRCS =  main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) *.replace

re: clean fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re