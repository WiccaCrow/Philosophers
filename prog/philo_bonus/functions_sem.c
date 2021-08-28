#include "philo_sem.h"

/************************************
 * 		3.2.1.1.1. ft_sem_down		*
 * **********************************
*/
/* Description:
 * 		The function semaphore down.
*/

void	ft_sem_down(t_sem *sem_forks)
{
	--(sem_forks->sem_up);
	sem_wait(sem_forks->data);
}

/************************************
 * 		3.2.1.1.2. ft_sem_up		*
 * **********************************
*/
/* Description:
 * 		The function semaphore up.
*/

void	ft_sem_up(t_sem *sem_forks)
{
	sem_post(sem_forks->data);
	++(sem_forks->sem_up);
}

/************************************
 * 		5. ft_sem_free				*
 * **********************************
*/
/* Description:
 * 		The function close and unlink semaphore.
*/

void	ft_sem_free(t_all *all)
{
	sem_close(all->data.sem_forks->data);
	sem_unlink(SEM_FORK);
	sem_close(all->data.sem_die);
	sem_unlink(SEM_DIE);
	sem_close(all->data.sem_take_both_forks);
	sem_unlink(SEM_BOTH_FORKS);
}
