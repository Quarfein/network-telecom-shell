#Fichier makefile créé par Akim
#Remarque : attention à ne pas utiliser d'espace à la place de tabulation.

NAME    =       Minishell

CC      =       gcc -o

RM      =       rm -f

CFLAGS  +=      -Wall -Wextra -Werror

CFLAGS  +=      -I./include/ -g3

SRCS    =		exec.c \
				deconcat.c \
				base.c \

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean: clean
				$(RM) $(NAME)

re:     fclean all

.PHONY: all re clean fclean


