#include "philo.h"

int	start_all(t_all *all, char **av)
{
	memset(all, 0, sizeof(t_all));
	memset(&all->data, 0, sizeof(t_data));
	all->data.nb_philo = ft_atoi(av[1]);
	if (all->data.nb_philo == 0)
	{
		(write(STDERR_FILENO, "Error: no one philosopher\n", 26));
		return (1);
	}

	all->data.ph = (pthread_t *)malloc(sizeof(pthread_t) * all->data.nb_philo);
	if (!all->data.ph)
	{
		(write(STDERR_FILENO, "Error: malloc error\n", 20));
		return (1);
	}

	all->philo = (t_philo *)malloc(sizeof(t_philo) * all->data.nb_philo);
	if (!all->philo)
	{
		(write(STDERR_FILENO, "Error: malloc error\n", 20));
		return (1);
	}
	memset(all->philo, 0, sizeof(t_philo));
	int	i = -1;
	while (++i < all->data.nb_philo)
	{
		all->philo[i].d = &all->data;
		all->philo[i].id = i + 1;
	}

	all->data.time_to_die = ft_atoi(av[2]);
	all->data.time_to_eat = ft_atoi(av[3]) * 1000;
	all->data.time_to_sleep = ft_atoi(av[4]) * 1000;
	if (av[5])
		all->data.time_stop_eat = ft_atoi(av[5]) * 1000;
	all->data.colors = (char **)malloc(sizeof(char *) * 8);
	all->data.colors[0] = strdup(ANSI_COLOR_RED);
	all->data.colors[1] = strdup(ANSI_COLOR_GREEN);
	all->data.colors[2] = strdup(ANSI_COLOR_YELLOW);
	all->data.colors[3] = strdup(ANSI_COLOR_BLUE);
	all->data.colors[4] = strdup(ANSI_COLOR_MAGENTA);
	all->data.colors[5] = strdup(ANSI_COLOR_CYAN);
	all->data.colors[6] = strdup(ANSI_COLOR_RESET);
	all->data.colors[7] = NULL;
	return (0);
}