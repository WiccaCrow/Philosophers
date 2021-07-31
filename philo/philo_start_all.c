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
	all->colors = (char **)malloc(sizeof(char *) * 8);
	all->colors[0] = ANSI_COLOR_RED;
	all->colors[1] = ANSI_COLOR_GREEN;
	all->colors[2] = ANSI_COLOR_YELLOW;
	all->colors[3] = ANSI_COLOR_BLUE;
	all->colors[4] = ANSI_COLOR_MAGENTA;
	all->colors[5] = ANSI_COLOR_CYAN;
	all->colors[6] = ANSI_COLOR_RESET;
	all->colors[7] = NULL;
	return (0);
}