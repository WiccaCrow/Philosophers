#include "philo.h"

/************************************
 * 		2.1.2. ft_mutex_init		*
 * **********************************
*/
/* Description:
 * 		The function init mutex (use for forks mutex).
 * 
 * Includes functions:
 * 		2.1.2.1. ft_mutex_lock;
 * 		2.1.2.2. ft_mutex_unlock;
*/

void	ft_mutex_init(t_mutex *m)
{
	m->mutex_lock = 0;
	pthread_mutex_init(&m->data, 0);
}

/************************************
 * 		2.1.2.1. ft_mutex_lock		*
 * **********************************
*/
/* Description:
 * 		The function lock mutex (use for forks mutex).
*/

void	ft_mutex_lock(t_mutex *m)
{
	pthread_mutex_lock(&m->data);
	m->mutex_lock = 1;
}

/************************************
 * 		2.1.2.2. ft_mutex_unlock	*
 * **********************************
*/
/* Description:
 * 		The function unlock mutex (use for forks mutex).
*/

void	ft_mutex_unlock(t_mutex *m)
{
	pthread_mutex_unlock(&m->data);
	m->mutex_lock = 0;
}

/************************************
 * 		 ft_mutex_init				*
 * **********************************
*/
/* Description:
 * 		The function destroy mutexes (use for forks mutex).
*/

void	ft_mutex_free(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->data.nb_philo)
	{
		pthread_mutex_destroy(&all->data.mutex_forks[i].data);
	}	
}
