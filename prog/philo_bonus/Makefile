
NAME			=	philo_bonus

CCF				=	gcc $(CFLAGS)
CFLAGS			=	-Wall -Wextra -Werror -I./

SRCS			=	philo_main.c philo_initialization.c philo_initialization_all_data.c\
					philo_simulation.c philo_simulation_stop.c \
					philo_gettime.c philo_simulation_and_print_status.c \
					functions.c functions_sem.c \
					philo_clean_all.c

HDR				=	philo_sem.h

OBJS			=	$(SRCS:.c=.o)
%.o:		%.c $(HDR)
			@$(CCF) -c $< -o $@
			@echo "$(GREEN)"$@ "compilled$(ENDCOLOR)"

GREEN			=	\033[92m
ENDCOLOR		=	\033[0m

all:	$(NAME)

$(NAME):	$(OBJS) $(HDR)
			@$(CCF) $(OBJS) -o $(NAME) -pthread
			@echo "$(GREEN)$(NAME) is compiled $(ENDCOLOR)"

clean:		;	@rm -f $(OBJS)

fclean:			clean	;	@rm -f $(NAME)

re:				fclean all