#include "philo.h"

void	put_fork(t_philo *ph)
{
	ph->d->mutex_forks[ph->nb_mutex_left_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
	ph->d->mutex_forks[ph->nb_mutex_right_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_right_fork]));
}

void	take_forks_eat_put_forks(t_philo *ph)
{
	ph->d->mutex_forks[ph->nb_mutex_left_fork].lock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
	if (ph->d->mutex_forks[ph->nb_mutex_right_fork].mutex_lock)
	{
		usleep(100);
		ph->d->mutex_forks[ph->nb_mutex_left_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
		take_forks_eat_put_forks(ph);
	}
	else
	{
		ph->d->mutex_forks[ph->nb_mutex_right_fork].lock(&(ph->d->mutex_forks[ph->nb_mutex_right_fork]));
		print_status(ph, 0, MESS_FORK);
		print_status(ph, 0, MESS_FORK);
		ft_eat(ph);
		put_fork(ph);
	}
}

void	ft_eat(t_philo *ph)
{
	print_status(ph, 1, MESS_EAT);
	ft_usleep(ph->d->time_to_eat);
	// ph->eat_end_time = ft_gettime(ph);
}

void	*philosopher(void *ph)
{
	((t_philo *)ph)->nb_mutex_right_fork = ((t_philo *)ph)->id - 1;
	if (((t_philo *)ph)->nb_mutex_right_fork == 0)
		((t_philo *)ph)->nb_mutex_left_fork = ((t_philo *)ph)->d->nb_philo - 1;
	else
		((t_philo *)ph)->nb_mutex_left_fork = ((t_philo *)ph)->id - 2;
	while (1)
	{
		take_forks_eat_put_forks(ph);
		ft_sleep((t_philo *)ph);
		ft_think((t_philo *)ph);
	}
}
