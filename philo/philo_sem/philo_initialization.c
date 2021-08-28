#include "philo_sem.h"

/************************************
 * 		2. initialization			*
 * **********************************
*/
/* Description:
 * 		The function allocate the memory  for 
 * 		t_all structure pointers and sets start 
 * 		value for other elements.
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
 * Includes functions:
 * 		2.1. init_all_data;
 * 		2.2. init_all_philo;
*/

int	initialization(t_all *all, char **av)
{
	memset(all, 0, sizeof(t_all));
	if (init_all_data(&all->data, av) || init_all_philo(all, &all->philo))
		return (1);
	return (0);
}

/************************************
 * 		init_all_philo				*
 * **********************************
*/
/* Description:
 * 		The function allocate the memory  for 
 * 		t_philo structure pointers and sets start 
 * 		value for other elements.
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
*/

int	init_all_philo(t_all *all, t_philo	**all_philo)
{
	int		i;
	int		i_col;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * all->data.nb_philo);
	if (!philo)
		return (write(STDERR_FILENO, "Error: malloc error\n", 20));
	memset(philo, 0, sizeof(t_philo));
	i = -1;
	while (++i < all->data.nb_philo)
	{
		philo[i].d = &all->data;
		philo[i].id = i + 1;
		i_col = philo[i].id % 6;
		philo[i].print_color = all->data.colors[i_col];
		philo[i].eat_nb = 0;
		philo[i].eat_start_time = 0;
	}
	*all_philo = philo;
	return (0);
}
