#include "philo.h"

int main(int ac, char **av)
{
	t_all	all;
	int		i;

	if (valid_ac(ac, av))
		return (2);
	if (start_all(&all, av))
		return (1);
	i = simulation(&all);
	while (i--)
		pthread_join(all.data.ph[i], NULL);

	usleep(3000000);
	return (0);
}

int	simulation(t_all *all)
{
	int		i;

	i = -1;
	watching_every_alive(all);
	while (++i < all->data.nb_philo)
	{
		if (pthread_create(&all->data.ph[i], NULL, philosopher, (void *)&all->philo[i]))
			break ;
	}
	if (i != all->data.nb_philo)
		write(STDERR_FILENO, "Error: pthread_create\n", 22);
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
		i = -1;
		while (av[nb_arg][++i])
			if (av[nb_arg][i] < '0' || av[nb_arg][i] > '9')
				return (write(STDERR_FILENO, "Error: arguments must be a number\n", 34));
	}
	return (0);
}
