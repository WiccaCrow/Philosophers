#include "philo.h"

int	start_all(t_all *all, char **av)
{
	memset(all, 0, sizeof(t_all));
	all->nb_philo = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		all->time_stop_eat = ft_atoi(av[5]);
	return (0);
}