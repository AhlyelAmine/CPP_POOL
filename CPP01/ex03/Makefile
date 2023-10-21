CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = weapon
SRCS = HumanA.cpp  HumanB.cpp   Weapon.cpp  main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp HumanA.hpp  HumanB.hpp Weapon.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re