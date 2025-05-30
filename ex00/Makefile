NAME=convert
TESTS = 1

CC = c++
FLAGS = -g3 -Wall -Werror -Wextra -std=c++98

INCLUDE = includes
SRC =	ScalarConverter.cpp\
		main.cpp
SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -I$(INCLUDE) -o $(NAME) $(OBJS)

src/%.o: src/%.cpp
	@echo "\033[1;32mCompiling	->	$<\033[0m"
	@$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

run: all
	@valgrind ./$(NAME)

test: all
	@valgrind ./$(NAME)
	@valgrind ./$(NAME) 0
	@valgrind ./$(NAME) 1
	@valgrind ./$(NAME) 42
	@valgrind ./$(NAME) -42.0
	@valgrind ./$(NAME) 42.0f
	@valgrind ./$(NAME) 15.4007
	@valgrind ./$(NAME) 15.4007f
	@valgrind ./$(NAME) c
	@valgrind ./$(NAME) hello
	@valgrind ./$(NAME) 97.435435435535543
	@valgrind ./$(NAME) nan
	@valgrind ./$(NAME) -inf
	@valgrind ./$(NAME) +inf
	@valgrind ./$(NAME) .5f
	@valgrind ./$(NAME) ""
	@valgrind ./$(NAME) "`printf '\t'`"
	@valgrind ./$(NAME) "`printf '\n'`"
	@valgrind ./$(NAME) "`printf '\a'`"
	@valgrind ./$(NAME) "`printf '\b'`"
	@valgrind ./$(NAME) '.'
	@valgrind ./$(NAME) -42
	@valgrind ./$(NAME) -hello

clean:
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		OBJECTS REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		$(NAME) REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"	
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run test
