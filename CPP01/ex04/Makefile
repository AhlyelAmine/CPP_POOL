CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
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