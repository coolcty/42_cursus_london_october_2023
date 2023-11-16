.DEFAULT_GOAL := all
MANDATORY	= calloc isdigit  memcpy   strdup   strncmp  tolower isalnum  isprint  memmove  strlcat \
strnstr  toupper atoi   isalpha  memchr   memset   strlcpy  strrchr  bzero  isascii  memcmp   strchr  \
strlen   substr strjoin strtrim split itoa strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd
BONUS		= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
CFLAGS		= -Wall -Wextra -Werror
CC			= cc
NAME 		= libft.a 
RM          = rm -f
COM			= ar rc


%.o: %.c		
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME}: 	${MANDATORY:%=ft_%.o}
			${COM} ${NAME} ${MANDATORY:%=ft_%.o}
			ranlib ${NAME}

all:		${NAME}

bonus:		${NAME} ${BONUS:%=ft_%.o}
			${COM} ${NAME} ${BONUS:%=ft_%.o}
			ranlib ${NAME}
clean:		
			${RM} ${MANDATORY:%=ft_%.o} ${BONUS:%=ft_%.o}

fclean:		clean
			${RM} ${NAME}

re:         fclean all

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) *.c
#	gcc -nostartfiles -shared -o libft.so *.o

.PHONY:		all clean fclean re bonus