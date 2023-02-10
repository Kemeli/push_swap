SRC =		src/main.c \
			src/start_values.c \
			src/args_checker.c \
			src/get_index.c \
			src/linked_list.c\
			src/sort.c \
			src/radix.c \
			src/operations.c \
			src/sorted_checker.c \
			src/end.c \

LIBFT =		libft/libft.a

NAME =		push_swap
FLAGS =		-Wall -Wextra -Werror

OBJS = ${SRC:%.c=%.o} 

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	cc -g ${FLAGS} ${OBJS} ${LIBFT} -o $@

%.o: %.c
	cc -g -c ${FLAGS} $< -o $@

${LIBFT}:
	make -sC libft/

clean: 
	rm -f ${OBJS}
	make clean -sC libft/

fclean: clean
	rm -rf ${NAME}
	rm -f ${OBJS}
	make fclean -sC libft/

re: fclean all

PHONY: all clean fclean re
