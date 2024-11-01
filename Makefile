SRC			= ft_printf.c \
			  ft_printf_utils.c \
			  ft_printf_put.c \
			  ft_itoa_base.c \
			  ft_putnbrstr.c \
			  ft_printf_calloc.c

SRCS_DIR	= srcs/
SRCS		= $(addprefix ${SRCS_DIR}, ${SRC})

OBJS_DIR	= objets/
OBJS		= $(addprefix ${OBJS_DIR}, ${SRC:.c=.o})

NAME		= libftprintf.a
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
CC			= cc

#Colors
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
RESET		= \033[0m

all:			${NAME}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
				@${CC} ${CFLAGS} -c $< -o $@

bonus:			${NAME}

${NAME}:		${OBJS}
				@ar rcs $@ -o $^
				@echo "${YELLOW}'${NAME}' is compiled !${RESET}"

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR}

clean:
				@${RM} ${OBJS}
				@${RM} -r ${OBJS_DIR}
				@echo "${RED}'${NAME}' objects are deleted !${RESET}"

fclean:			clean
				@${RM} ${NAME}
				@echo "${RED}'${NAME}' is deleted !${RESET}"

re:				fclean all

.PHONY:			all clean fclean re bonus
