CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

NAME	= push_swap
INCS    = include

SRCS    = $(wildcard utils/*.c) $(wildcard *.c)
DIR_O	= file_o

SRC_BONUS =	

BLUE := \033[96m
GREEN := \033[32m

OBJ    = $(patsubst %.c,file_o/%.o,$(SRCS))
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: ${NAME}

$(DIR_O):
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/utils

file_o/%.o: %.c | $(DIR_O)
	@${CC} ${CFLAGS} -I ${INCS} -c $< -o $@

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME}
	@echo "${GREEN}COMPILATION SUCEED"


bonus: ${OBJ} ${OBJ_BONUS}
	@${CC} ${CFLAGS} ${OBJ} ${OBJ_BONUS} -o ${NAME}

clean:
	@rm -rf $(DIR_O)
	@echo "ALL IS CLEAN"

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus