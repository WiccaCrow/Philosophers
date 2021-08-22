#include "philo.h"

/************************************
 * 		main						*
 * **********************************
*/
/* Includes functions:
 * 		1. valid_ac_av;
 * 		2. initialization;
 * 		3. simulation;
 * 		4. simulation_stop;
 * 		5. ft_mutex_free;
 * 		6. ft_clean_all;
*/

int main(int ac, char **av)
{
	t_all			all;
	int				i;
	
	if (valid_ac_av(ac, av))
		return (2);
	if (initialization(&all, av))
		return (1);
	i = 0;
	i = simulation(&all);
	if (pthread_create(&all.sim_stop, NULL, simulation_stop, (void *)&all))
			return (i);
	pthread_join(all.sim_stop, 0);
	while (i > -1)
		pthread_join(all.data.ph[i--], NULL);
	ft_mutex_free(&all);
	ft_clean_all(&all);
	return (0);
}

/************************************
 * 		1. valid_ac_av				*
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
 * Includes functions:
 * 		1.1. valid_av;
*/

int	valid_ac_av(int ac, char **av)
{
	int	nb_arg;

	if (ac < 5 || ac > 6)
		return (write(STDERR_FILENO, "Error: wrong number of arguments\n", 33));
	nb_arg = 0;
	while (av[++nb_arg])
	{
		if (valid_av(av[nb_arg]))
			return (1);
	}
	return (0);
}

/************************************
 * 		1.1. valid_av				*
 * **********************************
*/
/* Description:
 * 		The function checks the entered 
 * 		arguments for validity.
 * 		Arguments must be numbers.
 * 
 * Returned value:
 * 		If the arguments are valid, 0.
 * 		Otherwise, 1.
*/

int	valid_av(char *av)
{
	int	i;

	if (av[0] == '\0')
		return (write(STDERR_FILENO, "Error: arguments must be a number\n", 34));
	i = 0;
	while (av[i])
	{
		while (av[i] != '\0' && av[i] <= 32)
			++i;
		while (av[i] && (av[i] >= '0' && av[i] <= '9'))
			++i;
		if (av[i] && (av[i] < '0' || av[i] > '9'))
		{
			while (av[i] && av[i] <= 32)
				++i;
			if (av[i])				
				return (write(STDERR_FILENO, "Error: arguments must be a number\n", 34));
		}
	}
	return (0);
}
