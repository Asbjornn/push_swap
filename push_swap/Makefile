CC        = gcc
CFLAGS    = -Wall -Wextra -Werror -g

NAME    = push_swap
INCS    = includes

SRCS    =	ft_print_char.c ft_print_int.c ft_print_string.c ft_printf.c\
			ft_strlen.c ft_push_swap.c ft_list.c ft_atoi.c ft_split.c\
			ft_to_swap.c ft_to_rotate.c ft_push_list.c ft_to_reverse_rotate.c \
			sort.c algo.c

SRC_BONUS =	

BLUE := \033[96m
GREEN := \033[32m

OBJ    = ${SRCS:.c=.o}
OBJ_BONUS = $(SRC_BONUS:.c=.o)

.c.o:
	@${CC} ${CFLAGS} -I ${INCS} -c $< -o $@

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME}
	@echo "${GREEN}COMPILATION SUCEED"

all: ${NAME}

bonus: ${OBJ} ${OBJ_BONUS}
	@${CC} ${CFLAGS} ${OBJ} ${OBJ_BONUS} -o ${NAME}

clean:
	@rm -f ${OBJ} ${OBJ_BONUS}
	@echo "ALL IS CLEAN"

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus