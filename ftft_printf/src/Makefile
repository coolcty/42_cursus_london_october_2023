.DEFAULT_GOAL := all
MANDATORY	= libftprintf libftprintf_utils1 libftprintf_utils2
BONUS		=
CFLAGS		= -Wall -Wextra -Werror
CC			= cc
NAME 		= libftprintf.a 
RM          = rm -f
COM			= ar rc


%.o: %.c		
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME}: 	${MANDATORY:%=%.o}
			${COM} ${NAME} ${MANDATORY:%=%.o}
			ranlib ${NAME}

all:		${NAME}

bonus:		${NAME} ${BONUS:%=%.o}
			${COM} ${NAME} ${BONUS:%=%.o}
			ranlib ${NAME}
clean:		
			${RM} ${MANDATORY:%=%.o} ${BONUS:%=%.o}

fclean:		clean
			${RM} ${NAME}

re:         fclean all

.PHONY:		all clean fclean re bonus