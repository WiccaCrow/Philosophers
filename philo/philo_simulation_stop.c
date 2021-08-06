#include "philo.h"

void	check_time_to_die(t_philo *ph, t_data *d, long int time_current);

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
			check_time_to_die(&((t_all *)all)->philo[i], &((t_all *)all)->data, time_current);
		}
		usleep(100);
	}
	return (0);
}

void	check_time_to_die(t_philo *ph, t_data *d, long int time_current)
{
	if (ph->eat_end_time + d->time_to_die <= time_current)
	{
printf("time_cur = %ld | ph->eat_end_time = %ld | hungry = %ld | max time = %ld\n", time_current, ph->eat_end_time, time_current - ph->eat_end_time, d->time_to_die);
		print_status(ph, time_current, MESS_DIED);
		exit (2);
	}
}