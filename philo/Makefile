NAME	=	philo
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -pthread# -fsanitize=thread

SRC_DIR	=	src
OBJ_DIR	=	obj

SRC		=	main.c 

HEADER	=	philosophers.h


OBJ		=	${SRC:%.c=${OBJ_DIR}/%.o}

VPATH	=	src
INCLUDE	=	-I ./


all: ${NAME}

${NAME}: ${OBJ_DIR} ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o $@

${OBJ_DIR}/%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE}

${OBJ_DIR}:
	mkdir -p $@

clean:
	rm -rf ${OBJ_DIR}

fclean:	clean
	rm -rf ${NAME}

re:		fclean all

.PHONY:	all clean fclean re run