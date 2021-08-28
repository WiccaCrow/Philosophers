
CCF				=	gcc $(CFLAGS)
# CFLAGS		=	-Wall -Wextra -Werror -lpthread -g -I./
CFLAGS			=	-Wall -Wextra -Werror -g -I./

FOLDER_MUTEX	=	./philo/
SRC_MUTEX		=	philo_main.c philo_initialization.c \
					philo_simulation.c philo_simulation_stop.c \
					philo_gettime.c philo_simulation_and_print_status.c \
					functions.c functions_mutex.c \
					philo_clean_all.c

FOLDER_SEM	=		./philo_bonus/
SRC_SEM		=		philo_main.c philo_initialization.c philo_initialization_all_data.c\
					philo_simulation.c philo_simulation_stop.c \
					philo_gettime.c philo_simulation_and_print_status.c \
					functions.c functions_sem.c \
					philo_clean_all.c

ifdef MAKE_BONUS
NAME			=	philo_bonus
SRCS			=	$(addprefix $(FOLDER_SEM), $(SRC_SEM))
HDR				=	$(addprefix $(FOLDER_SEM), philo_sem.h)
else
NAME			=	philo
SRCS			=	$(addprefix $(FOLDER_MUTEX), $(SRC_MUTEX))
HDR				=	$(addprefix $(FOLDER_MUTEX), philo.h)
endif


OBJS		=		$(SRCS:.c=.o)
%.o:		%.c $(HDR)
			@$(CCF) -c $< -o $@
			@echo "$(GREEN)"$@ "compilled$(ENDCOLOR)"


GREEN		=		\033[92m
ENDCOLOR	=		\033[0m

all:	$(NAME)

$(NAME):	$(OBJS) $(HDR)
			@$(CCF) $(OBJS) -o $(NAME) -pthread
			@echo "$(GREEN)$(NAME) is compiled $(ENDCOLOR)"

bonus: ; $(MAKE) MAKE_BONUS=1 all

clean:		;	@rm -f $(OBJS)
cleanbonus:	;	$(MAKE) MAKE_BONUS=1 clean

fclean:			clean	;	@rm -f $(NAME)
fcleanbonus:	;	 $(MAKE) MAKE_BONUS=1 fclean

re:				fclean all
rebonus:			;	 $(MAKE) MAKE_BONUS=1 re

.PHONY: philo