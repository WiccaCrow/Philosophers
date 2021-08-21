#include "philo.h"

long int	ft_gettime_simul_start()
{
	long int		timestap_in_mcs;
	struct timeval	*tv;

	tv = (struct timeval *)malloc(sizeof(struct timeval) * 1);
	if (gettimeofday(tv, NULL))
	{
		write(STDERR_FILENO, "Error: gettimeofday error\n", 26);
		return (-1);
	}
	timestap_in_mcs = tv->tv_sec * 1000000 + tv->tv_usec;
	return (timestap_in_mcs);
}

long int	ft_gettime(t_philo *ph)
{
	long int	timestap_in_ms;

	timestap_in_ms = ft_gettime_simul_start();
	if (timestap_in_ms != -1)
		timestap_in_ms -= ph->d->simul_start;
	return (timestap_in_ms);
}
