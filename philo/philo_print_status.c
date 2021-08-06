#include "philo.h"

void	ft_think(t_philo *ph)
{
	long int	time;

		int	i;
		i = ph->id % 6;
	time = ft_gettime(ph);
	if (time != -1)
		print_status(ph, time, MESS_THINK);
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
		print_status(ph, time, MESS_SLEEP);
		// printf("%s%ld %d%s%s\n", ph->d->colors[i], time, ph->id, MESS_SLEEP, ph->d->colors[6]);
		ft_usleep(ph->d->time_to_sleep / 1000);// в ft_usleep милисекунды, поэтому не нужно переводить из в микросекунды
	}
}

void	ft_died(t_philo *ph)
{
	long int	time;

		int	i;
		i = ph->id % 6;
	time = ft_gettime(ph);
	if (time != -1 && !ph->d->died)
	{
		ph->d->died_time = time;
		print_status(ph, time, MESS_DIED);
		// printf("%s%ld %d%s%s\n", ph->d->colors[i], time, ph->id, MESS_DIED, ph->d->colors[6]);
	}
}

void	print_status(t_philo *ph, long int timestap_in_ms, char *message)
{
	int		i;

	i = ph->id % 6;
	printf("%s%ld %d%s%s\n", ph->d->colors[i], timestap_in_ms, ph->id, message, ph->d->colors[6]);
}
