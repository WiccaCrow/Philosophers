#include "philo.h"

void	*simulation_stop(void *all)
{
	int			i;
	long int	time_current;

	while (1)
	{
		i = - 1;
		time_current = ft_gettime(((t_all *)all)->philo);
		while (++i < ((t_all *)all)->data.nb_philo)
		{
			if (2 == check_time_to_die(&((t_all *)all)->philo[i], &((t_all *)all)->data, time_current))
				return (0);
		}
		usleep(50);
	}
	return (0);
}

int	check_time_to_die(t_philo *ph, t_data *d, long int time_current)
{
	int	i;

	i = ph->id % 6;
	if ((time_current - ph->eat_end_time) / 1000 > d->time_to_die / 1000
		&& (time_current - ph->eat_start_time) / 1000 > d->time_to_die / 1000
		&& ph->eat_start_time < ph->eat_end_time
		// && (ph->eat_start_time - ph->eat_end_time) / 1000 > d->time_to_die / 1000
		// && (ph->eat_end_time && (time_current - ph->eat_end_time) / 1000)
		// && (ph->eat_start_time && (time_current - ph->eat_start_time) / 1000)
		)
	{
		pthread_mutex_lock(&(ph->d->mutex_die));
printf("start_eat - end_eat = %ld | max time = %ld\n\n", ph->eat_start_time - ph->eat_end_time, d->time_to_die);
printf("time_cur = %ld | ph->eat_start_time = %ld | hungry_start = %ld | max time = %ld\n", time_current, ph->eat_start_time, time_current - ph->eat_start_time, d->time_to_die);
printf("time_cur = %ld | ph->eat_start_time = %ld | hungry_start = %ld | max time = %ld\n\n", time_current / 1000, ph->eat_start_time / 1000, (time_current - ph->eat_start_time) / 1000, d->time_to_die / 1000);
printf("time_cur = %ld | ph->eat_end_time = %ld | hungry_end = %ld | max time = %ld\n", time_current, ph->eat_end_time, time_current - ph->eat_end_time, d->time_to_die);
printf("time_cur = %ld | ph->eat_end_time = %ld | hungry_end = %ld | max time = %ld\n\n", time_current / 1000, ph->eat_end_time / 1000, (time_current - ph->eat_end_time) / 1000, d->time_to_die / 1000);
		printf("%s%ld %d%s%s\n", ph->d->colors[i], time_current / 1000, ph->id, MESS_DIED, ph->d->colors[6]);
		return (2);
	}
	return (0);
}