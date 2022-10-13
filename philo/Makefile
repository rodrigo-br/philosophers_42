NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror -g3 -pthread
OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

SRCS	=	$(MAIN)
MAIN	=	main.c check_args.c architect.c ft_atoi.c time_now.c \
			enter_the_matrix.c knock_knock_neo.c very_important_file.c

VPATH	=	src
HEADER	=	philosophers.h please_dont_open_me.h
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

git:
	git add .
	git commit -m "$(m)"
	git push

.PHONY:	all clean fclean re