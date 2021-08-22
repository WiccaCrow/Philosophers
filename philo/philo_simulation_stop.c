#include "philo.h"

/************************************
 * 		4. simulation_stop			*
 * **********************************
*/
/* Description:
 * 		The function checks the conditions for stopping the simulation.
 * 
 * Includes functions:
 * 		4.1. check_time_to_die;
 * 		4.2. check_stop_eat;
 * 		3.2.1.2.1. ft_gettime;
*/

void	*simulation_stop(void *all)
{
	int			i;
	long int	time_current;
	int			nb_max_eat;

	while (1)
	{
		nb_max_eat = 0;
		i = -1;
		while (++i < ((t_all *)all)->data.nb_philo)
		{
			time_current = ft_gettime(((t_all *)all)->philo);
			if (2 == check_time_to_die(&((t_all *)all)->philo[i],
					&((t_all *)all)->data, time_current))
				return (0);
			if (((t_all *)all)->data.time_stop_eat > 0
				&& ((t_all *)all)->philo[i].eat_nb
				>= ((t_all *)all)->data.time_stop_eat)
				++nb_max_eat;
		}
		if (check_stop_eat((t_all *)all, nb_max_eat))
			return (0);
	}
	return (0);
}

/************************************
 * 		4.1. check_time_to_die		*
 * **********************************
*/
/* Description:
 * 		The function checks time to die.
*/

int	check_time_to_die(t_philo *ph, t_data *d, long int time_current)
{
	pthread_mutex_lock(&d->mutex_die);
	if ((time_current - ph->eat_start_time) / 1000 > d->time_to_die / 1000)
	{
		d->sim_stop_int = 1;
		printf("%s%ld %d%s%s\n", ph->print_color, time_current / 1000, ph->id,
			MESS_DIED, ph->d->colors[6]);
		pthread_mutex_unlock(&d->mutex_die);
		return (2);
	}
	pthread_mutex_unlock(&d->mutex_die);
	return (0);
}

/************************************
 * 		4.2. check_stop_eat			*
 * **********************************
*/
/* Description:
 * 		The function checks time to die.
*/

int	check_stop_eat(t_all *all, int nb_max_eat)
{
	if (all->data.time_stop_eat > 0
		&& nb_max_eat == ((t_all *)all)->data.nb_philo)
	{
		all->data.sim_stop_int = 1;
		return (1);
	}
	usleep(100);
	return (0);
}
