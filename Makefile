CC = cc
NAME = ast

SRC_INC = ./src/
HDR_INC = ./inc/

CFLAG = -Wall -Wextra -Werror

SRC = node \
	utils \
	token \
	ast	\
	main

SRCS = $(addprefix $(SRC_INC), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(SRC_INC), $(addsuffix .o, $(SRC)))

all : $(NAME) clean

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(SRCS) -o $(NAME) -I$(HDR_INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
