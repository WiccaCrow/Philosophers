#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdio.h>
# include<string.h>

# define MESS_FORK " has taken a fork\n"
# define MESS_EAT " is eating\n"
# define MESS_SLEEP " is sleeping\n"
# define MESS_THINK " is thinking\n"
# define MESS_THINK " died\n"

typedef struct	s_all
{
    int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_stop_eat;
}				t_all;

int	ft_atoi(const char *str);

int		valid_ac(int ac, char **av);
int		start_all(t_all *all, char **av);
int		simulation(t_all *all);
void	print_status(int nb_philo, char *message);

#endif