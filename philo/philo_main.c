#include "philo.h"

// void	ft_mutex_free(t_all *all)
// {
// 	pthread_mutex_init
// }

int main(int ac, char **av)
{
	t_all			all;
	int				i = 0;

	if (valid_ac(ac, av))
		return (2);
	if (start_all(&all, av))
		return (1);
printf("test main\n");
	i = simulation(&all);
	if (pthread_create(&all.sim_stop, NULL, simulation_stop, (void *)&all))
			return (i);
	pthread_join(all.sim_stop, 0);
	
	while (i > -1)
		pthread_join(all.data.ph[i--], NULL);
	// ft_usleep(3000000);
	// ft_mutex_free(&all);=
	return (0);
}

int	simulation(t_all *all)
{
	int			i;
	// pthread_t	wea;

	all->data.simul_start = ft_gettime_simul_start();
	i = -1;
	while (++i < all->data.nb_philo)
	{
		if (pthread_create(&all->data.ph[i], NULL, philosopher, (void *)&all->philo[i]))
		{
			write(STDERR_FILENO, "Error: pthread_create\n", 22);
			return (i);
		}
		// pthread_detach(all->data.ph[i]);
	}
	return (i);
}
/************************************
 * 				valid_ac			*
 * **********************************
*/
/* Description:
 * 		The function checks the entered 
 * 		arguments for validity.
 * 		There can be 4 or 5 arguments.
 * 		Arguments must be numbers.
 * 
 * Returned value:
 * 		If the arguments are valid, 0.
 * 		Otherwise, 1.
*/

int	valid_ac(int ac, char **av)
{
	int	nb_arg;
	int	i;

	if (ac < 5 || ac > 6)
		return (write(STDERR_FILENO, "Error: wrong number of arguments\n", 33));
	nb_arg = 0;
	while (av[++nb_arg])
	{
		if (av[nb_arg][0] == '\0')
			return (write(STDERR_FILENO, "Error: arguments must be a number\n", 34));
		i = 0;
		while (av[nb_arg][i])
		{
			while (av[nb_arg][i] != '\0' && av[nb_arg][i] <= 32)
				++i;
			while (av[nb_arg][i] && (av[nb_arg][i] >= '0' && av[nb_arg][i] <= '9'))
				++i;
			if (av[nb_arg][i] && (av[nb_arg][i] < '0' || av[nb_arg][i] > '9'))
			{
				while (av[nb_arg][i] && av[nb_arg][i] <= 32)
					++i;
				if (av[nb_arg][i])				
					return (write(STDERR_FILENO, "Error: arguments must be a number\n", 34));
			}
		}
	}
	return (0);
}
