#include "philo_sem.h"

/************************************
 * 		3. simulation				*
 * **********************************
*/
/* Description:
 * 		The function run simulation in threads.
 * 
 * Returned value:
 * 		Number of threads.
 * Includes functions:
 * 		3.1. ft_gettime_simul_start;
 * 		3.2. philosopher;
*/

int	simulation(t_all *all)
{
	int			i;

	all->data.simul_start = ft_gettime_simul_start();
	i = -1;
	while (++i < all->data.nb_philo)
	{
		if (pthread_create(&all->data.ph[i], NULL, philosopher,
				(void *)&all->philo[i]))
		{
			write(STDERR_FILENO, "Error: pthread_create\n", 22);
			return (i);
		}
	}
	return (i);
}

/************************************
 * 		3.2. philosopher			*
 * **********************************
*/
/* Description:
 * 		The function simulates the life of each philosopher within the thread.
 * 
 * Includes functions:
 * 		3.2.1. take_forks_eat_put_forks;
*/

void	*philosopher(void *ph)
{
	while (1)
	{
		if (take_forks_eat_put_forks(ph))
			return (0);
		if (((t_philo *)ph)->d->sim_stop_int)
			return (0);
		if (print_status(ph, 0, MESS_SLEEP))
			return (0);
		ft_usleep(((t_philo *)ph)->d->time_to_sleep);
		if (((t_philo *)ph)->d->sim_stop_int)
			return (0);
		if (print_status(ph, 0, MESS_THINK))
			return (0);
	}
}

/********************************************
 * 		3.2.1. take_forks_eat_put_forks		*
 * ******************************************
*/
/* Description:
 * 		The function simulates in philosophers life:
 * 		take forks, eat, put forks.
 * 
 * Includes functions:
 * 		3.2.1.1. take_forks_left;
 * 		3.2.1.2. print_status;
 * 		3.2.1.3. put_fork;
 * 		3.2.1.4. ft_eat; 
*/

int	take_forks_eat_put_forks(t_philo *ph)
{
	take_forks(ph);
	if (print_status(ph, 0, MESS_FORK) || print_status(ph, 0, MESS_FORK)
		|| ft_eat(ph))
		return (put_forks(ph));
	put_forks(ph);
	return (ph->d->sim_stop_int);
}

/********************************************
 * 		3.2.1.1. take_forks			*
 * ******************************************
*/
/* Description:
 * 		The function simulates in philosophers life:
 * 		take left forks. If philosopher can't take right fork, 
 * 		he throw left fork.
 * 
 * Return value:
 * 		1 - if philosopher can't take right fork.
 * 		0 - if philosopher can take right fork.
*/

void	take_forks(t_philo *ph)
{
	while (!ph->d->sim_stop_int)
	{
		ft_sem_down(ph->d->sem_forks);
		if (ph->d->sem_forks->sem_up > 0)
		{
			ft_sem_down(ph->d->sem_forks);
			break ;
		}
		// usleep(100);
		// usleep(100 + ph->id/100);
		ft_sem_up(ph->d->sem_forks);
	}
}

/********************************************
 * 		3.2.1.3. put_forks					*
 * ******************************************
*/
/* Description:
 * 		The function simulates in philosophers life:
 * 		put both forks.
*/

int	put_forks(t_philo *ph)
{
	ft_sem_up(ph->d->sem_forks);
	ft_sem_up(ph->d->sem_forks);
	return (1);
}
