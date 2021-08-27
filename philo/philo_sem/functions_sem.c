#include "philo_sem.h"

/************************************
 * 		2.1.2.1. ft_mutex_lock		*
 * **********************************
*/
/* Description:
 * 		The function lock mutex (use for forks mutex).
*/

void	ft_sem_down(t_sem *sem_forks)
{
	sem_wait(sem_forks->data);
	--(sem_forks->sem_up);
}

/************************************
 * 		2.1.2.2. ft_mutex_unlock	*
 * **********************************
*/
/* Description:
 * 		The function unlock mutex (use for forks mutex).
*/

void	ft_sem_up(t_sem *sem_forks)
{
	sem_post(sem_forks->data);
	++(sem_forks->sem_up);
}

/************************************
 * 		 ft_mutex_init				*
 * **********************************
*/
/* Description:
 * 		The function destroy mutexes (use for forks mutex).
*/

void	ft_sem_free(t_all *all)
{
	sem_close(all->data.sem_forks->data);
	sem_unlink(SEM_FORK);
	sem_close(all->data.sem_die);
	sem_unlink(SEM_DIE);
}
