NAME = ircserv

SRCS = $(wildcard src/*.cpp src/network/*.cpp src/command/*.cpp)
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I ./includes

RM = rm -rf


.cpp.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@echo "\033[0;32mCompiling IRC server..."
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "Done!\033[0m"

clean:
	@echo "\033[0;31mMake clean..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "\033[0;31mMake fclean..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean, fclean, re