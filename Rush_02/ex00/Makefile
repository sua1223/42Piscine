TARGET = rush-02

DIR = ./srcs/

SRCS = ${wildcard ./srcs/*.c}

OBJ = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${TARGET}: ${OBJ}
	${CC} -o $@ $^

all: ${TARGET} clean

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${TARGET}

re: fclean all

.PHONY: all clean fclean re