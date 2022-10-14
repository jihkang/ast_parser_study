CC = cc
NAME = ast

SRC_INC = ./src/
HDR_INC = ./inc/

CFLAG = -Wall -Wextra -Werror
HFLAG = -fsanitize=address -g3

SRC = node \
	utils \
	utils_add \
	token \
	ast	\
	free \
	main


SRCS = $(addprefix $(SRC_INC), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(SRC_INC), $(addsuffix .o, $(SRC)))

all : $(NAME) clean

$(NAME) : $(OBJS)
	$(CC) $(SRCS) -o $(NAME) -I$(HDR_INC)

wall : $(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(CFLAGS) -I$(HDR_INC)

add : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I$(HDR_INC) $(HFLAG)
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
