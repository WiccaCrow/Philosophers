#include "philo.h"

void	ft_think(t_philo *ph)
{
	long int	time;
	int	i;

	i = ph->id % 6;
	time = ft_gettime(ph);
	if (time != -1)
		print_status(ph, time / 1000, MESS_THINK);
		// printf("%s%ld %d%s%s\n", ph->d->colors[i], time, ph->id, MESS_THINK, ph->d->colors[6]);
}

void	ft_sleep(t_philo *ph)
{
	long int	time;

		int	i;
		i = ph->id % 6;
	time = ft_gettime(ph);
	if (time != -1)
	{
		print_status(ph, time / 1000, MESS_SLEEP);
		// printf("%s%ld %d%s%s\n", ph->d->colors[i], time, ph->id, MESS_SLEEP, ph->d->colors[6]);
		// ft_usleep(ph->d->time_to_sleep);
		ft_usleep(ph->d->time_to_sleep - 200);
	}
}

void	print_status(t_philo *ph, long int timestap_in_ms, char *message)
{
	int		i;

	i = ph->id % 6;
	pthread_mutex_lock(&(ph->d->mutex_die));
	pthread_mutex_unlock(&(ph->d->mutex_die));
	printf("%s%ld %d%s%s\n", ph->d->colors[i], timestap_in_ms, ph->id, message, ph->d->colors[6]);
}
