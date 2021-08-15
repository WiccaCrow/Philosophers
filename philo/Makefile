NAME		=		philo

CCF			=		gcc $(FLAGS)
# CFLAGS		=		-Wall -Wextra -Werror -lpthread -g -I./
CFLAGS		=		-Wall -Wextra -Werror -g -I./

SRCS		=		philo_main.c philo_start_all.c \
					philo_simulation.c philo_simulation_stop.c\
					philo_gettime.c philo_print_status.c\
					functions.c functions_mutex.c
OBJS		=		$(SRCS:.c=.o)
%.o:		%.c $(HDR)
			@$(CCF) -c $< -o $@
			@echo "$(GREEN)"$@ "compilled$(ENDCOLOR)"

HDR			=		philo.h

GREEN		=		\033[92m
ENDCOLOR	=		\033[0m

all:	$(NAME)

$(NAME):	$(OBJS) $(HDR)
			@$(CCF) $(OBJS) -o $(NAME) -pthread
			@echo "$(GREEN)$(NAME) is compiled $(ENDCOLOR)"

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

# clang -g -o philo *.c -pthread