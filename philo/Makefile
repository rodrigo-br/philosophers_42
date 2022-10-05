NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror -g3
OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

SRCS	=	$(MAIN) $(TESTE)
MAIN	=	main.c check_args.c get_time_now.c
TESTE	=	teste.c

VPATH	=	src src/teste
HEADER	=	philosophers.h
INCLUDE	=	-I ./

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

.PHONY:	all clean fclean re