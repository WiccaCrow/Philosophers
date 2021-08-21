#include "philo.h"

void	*simulation_stop(void *all)
{
	int			i;
	long int	time_current;

	while (1)
	{
		i = -1;
		while (++i < ((t_all *)all)->data.nb_philo)
		{
			time_current = ft_gettime(((t_all *)all)->philo);
			pthread_mutex_lock(&(((t_all *)all)->data.mutex_die));
			if (2 == check_time_to_die(&((t_all *)all)->philo[i], &((t_all *)all)->data, time_current))
			{
				pthread_mutex_unlock(&(((t_all *)all)->data.mutex_die));
				return (0);
			}
			
			// if ((time_current - ((t_all *)all)->philo[i].eat_start_time) > ((t_all *)all)->data.time_to_die)
			// {
			// 	printf("%s%ld %d%s%s\n", ((t_all *)all)->philo[i].print_color, time_current / 1000, ((t_all *)all)->philo[i].id, MESS_DIED, ((t_all *)all)->data.colors[6]);
			// 	return (0);
			// }
			pthread_mutex_unlock(&(((t_all *)all)->data.mutex_die));
		}
		usleep(100);
	}
	return (0);
}

int	check_time_to_die(t_philo *ph, t_data *d, long int time_current)
{
	// if ((time_current - ph->eat_end_time) / 1000 > d->time_to_die / 1000
	// 	&& (time_current - ph->eat_start_time) / 1000 > d->time_to_die / 1000
	// 	&& ph->eat_start_time < ph->eat_end_time
	// 	) // условие на голод - между концом приема пищи и началом след приема пищи проверяю время
	if ((time_current - ph->eat_start_time) / 1000 > d->time_to_die / 1000)
	{
		printf("%s%ld %d%s%s\n", ph->print_color, time_current / 1000, ph->id, MESS_DIED, ph->d->colors[6]);
		d->sim_stop_int = 1;
		return (2);
	}
	return (0);
}