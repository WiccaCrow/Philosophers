#include "philo.h"

/********************************************
 * 		3.2.1.2. print_status				*
 * ******************************************
*/
/* Description:
 * 		The function print in philosophers status.
 * 
 * Includes functions:
 * 		3.2.1.2.1. ft_gettime;
*/

int	print_status(t_philo *ph, long int does_eat, char *message)
{
	long int	timestap_in_ms;

	if (!ph->d->sim_stop_int && !pthread_mutex_lock(&(ph->d->mutex_die)))
	{
		timestap_in_ms = ft_gettime(ph);
		if (does_eat)
			ph->eat_start_time = timestap_in_ms;
		printf("%s%ld %d%s%s\n", ph->print_color, timestap_in_ms / 1000,
			ph->id, message, ph->d->colors[6]);
		pthread_mutex_unlock(&(ph->d->mutex_die));
	}
	return (ph->d->sim_stop_int);
}

/********************************************
 * 		3.2.1.4. ft_eat						*
 * ******************************************
*/
/* Description:
 * 		The function simulates in philosophers life:
 * 		eat.
*/

int	ft_eat(t_philo *ph)
{
	if (print_status(ph, 1, MESS_EAT))
		return (1);
	ft_usleep(ph->d->time_to_eat);
	++ph->eat_nb;
	return (ph->d->sim_stop_int);
}
