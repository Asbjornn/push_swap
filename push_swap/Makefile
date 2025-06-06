CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

NAME		= push_swap

INCS_DIR    = include
LIBFT_DIR	= libft
PRINTF_DIR	= libft/printf
DIR_O		= file_o

LIBFT_A		= ${LIBFT_DIR}/libft.a
PRINFT_A	= ${PRINTF_DIR}/libftprintf.a

SRCS    	=	ft_push_swap.c ft_push_list.c ft_to_rotate.c ft_to_reverse_rotate.c\
				ft_to_swap.c ft_error_manager.c chunk_sort.c sort.c radix_bitwise.c
SRCS_UTILS	=	utils/ft_free.c utils/ft_list.c utils/ft_atol.c

BLUE=\033[0;94m
GREEN=\033[1;92m

OBJ    = $(patsubst %.c,file_o/%.o,$(SRCS) $(SRCS_UTILS))

all: ${NAME}

$(DIR_O):
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/utils

file_o/%.o: %.c | $(DIR_O)
	@${CC} ${CFLAGS} -I ${INCS_DIR} -c $< -o $@

${NAME}: ${OBJ}
	@${MAKE} -C ${LIBFT_DIR}
	@${CC} ${CFLAGS} ${OBJ} ${LIBFT_A} ${PRINFT_A} -o ${NAME}
	@echo -e "${GREEN}COMPILATION SUCEED"

clean:
	@rm -rf $(DIR_O)
	@${MAKE} -C ${LIBFT_DIR} clean
	@echo -e "${GREEN}ALL IS CLEAN"

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY:	all clean fclean re bonus