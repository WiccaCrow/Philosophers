#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define MESS_FORK " has taken a fork\n"
# define MESS_EAT " is eating\n"
# define MESS_SLEEP " is sleeping\n"
# define MESS_THINK " is thinking\n"
# define MESS_DIED " died\n"

# define MASS (1 ,2, 3)
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct	s_all
{
    int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_stop_eat;
	char	**colors;
}				t_all;

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);

int		valid_ac(int ac, char **av);
int		start_all(t_all *all, char **av);
int		simulation(t_all *all);
void	print_status(t_all *all, int nb_philo, char *message);

#endif