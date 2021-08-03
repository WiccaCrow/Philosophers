#include "philo.h"

long int	ft_gettime_simul_start()
{
	long int		timestap_in_ms;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		(write(STDERR_FILENO, "Error: gettimeofday error\n", 26));
		return (-1);
	}
// printf("gettime 1\n");
	timestap_in_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
// printf("gettime 2\n");
	return (timestap_in_ms);
}

long int	ft_gettime(t_philo *ph)
{
	long int	timestap_in_ms;	

	timestap_in_ms = ft_gettime_simul_start();
	if (timestap_in_ms != -1)
		timestap_in_ms -= ph->d->simul_start;
	return (timestap_in_ms);
}
