#include "philo.h"

/************************************
 * 		3.1. ft_gettime_simul_start	*
 * **********************************
*/
/* Description:
 * 		The function return microseconds since Jan. 1, 1970.
 * 
 * Returned value:
 * 		The function return microseconds since Jan. 1, 1970. if sucsess.
 * 		If failure -1.
*/

long int	ft_gettime_simul_start(void)
{
	long int		timestap_in_mcs;
	struct timeval	*tv;

	tv = (struct timeval *)malloc(sizeof(struct timeval) * 1);
	if (!gettimeofday(tv, NULL))
	{
		timestap_in_mcs = tv->tv_sec * 1000000 + tv->tv_usec;
		free(tv);
		tv = NULL;
		return (timestap_in_mcs);
	}
	write(STDERR_FILENO, "Error: gettimeofday error\n", 26);
	return (-1);
}

/************************************
 * 		3.2.1.2.1. ft_gettime		*
 * **********************************
*/
/* Description:
 * 		The function return microseconds since simulation start.
 * 
 * Returned value:
 * 		The function return miliseconds since Jan. 1, 1970. if sucsess.
 * 		If failure -1.
 * Includes functions:
 * 		3.1. ft_gettime_simul_start;
*/

long int	ft_gettime(t_philo *ph)
{
	long int	timestap_in_ms;

	timestap_in_ms = ft_gettime_simul_start();
	if (timestap_in_ms != -1)
		timestap_in_ms -= ph->d->simul_start;
	return (timestap_in_ms);
}
