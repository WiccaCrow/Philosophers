NAME		=		philo

CCF			=		gcc $(FLAGS)
CFLAGS		=		-Wall -Wextra -Werror -g -I./

SRCS		=		philo_main.c
OBJS		=		$(SRCS:.c=.o)
%.o:		%.c $(HDR)
			@$(CCF) -c $< -o $@
			@echo "${GREEN}"$@ "compilled${ENDCOLOR}"

HDR			=		philo.h

GREEN		=		\033[92m
ENDCOLOR	=		\x1B[0m

all:	$(NAME)

$(NAME):	$(OBJS) $(HDR)
			@$(CCF) $(OBJS) -o $(NAME)
			@echo "${GREEN}"$(NAME)" is compiled${ENDCOLOR}"

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all