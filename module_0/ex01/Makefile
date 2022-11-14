NAME	= phonebook

OBJS	= ${SRCS:.cpp=.o}
SRCS	= phonebook.cpp contact.cpp main.cpp

CFLAGS	= -Wall -Wextra -Werror -std=c++98
CC		= g++

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re