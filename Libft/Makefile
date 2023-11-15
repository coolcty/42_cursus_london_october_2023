LIST 		= ft_calloc.c   ft_isdigit.c  ft_memcpy.c   ft_strdup.c   ft_strncmp.c  ft_tolower.c ft_isalnum.c  ft_isprint.c  ft_memmove.c  ft_strlcat.c  ft_strnstr.c  ft_toupper.c ft_atoi.c   ft_isalpha.c  ft_memchr.c   ft_memset.c   ft_strlcpy.c  ft_strrchr.c  ft_bzero.c  ft_isascii.c  ft_memcmp.c   ft_strchr.c   ft_strlen.c   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c# ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
CFLAGS		= -Wall -Wextra -Werror
CC			= cc
INC			= -I./includes
SRC_DIRS    = ./
OBJ_DIRS    = ${SRC_DIRS}
SRCS		= ${addprefix ${SRC_DIRS}/, ${LIST}}
OBJS 		= ${SRCS:${SRC_DIRS}/%.c=${OBJ_DIRS}/%.o}
NAME 		= libft.a 
RM          = rm -f
COM			= ar rc

${OBJ_DIRS}/%.o: ${SRC_DIRS}/%.c		
			${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}: 	${OBJS}
			${COM} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:         fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)