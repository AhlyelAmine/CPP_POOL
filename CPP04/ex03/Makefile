CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = animal 
SRCS = AMateria.cpp ICharacter.cpp IMateriaSource.cpp  Character.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp IMateriaSource.hpp ICharacter.hpp AMateria.hpp Character.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re