#include "philo.h"

long int	ft_gettime_simul_start(t_philo *ph)
{
	long int	timestap_in_ms;	

	if (gettimeofday(&ph->tv, NULL))
	{
		(write(STDERR_FILENO, "Error: gettimeofday error\n", 26));
		ph->d->comp_code = 1;
		return (-1);
	}
	timestap_in_ms = ph->tv.tv_sec * 1000 + ph->tv.tv_usec / 1000;
	return (timestap_in_ms);
}

long int	ft_gettime(t_philo *ph)
{
	long int	timestap_in_ms;	

	timestap_in_ms = ft_gettime_simul_start(ph);
	if (timestap_in_ms != -1)
		timestap_in_ms -= ph->d->simul_start;
	return (timestap_in_ms);
}
