CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = form 
SRCS =	Bureaucrat.cpp main.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) *_shrubbery

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re