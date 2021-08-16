#include "philo.h"

void	put_fork(t_philo *ph)
{
	ph->d->mutex_forks[ph->nb_mutex_left_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
	ph->d->mutex_forks[ph->nb_mutex_right_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_right_fork]));
}
// 
// void	take_forks(t_philo *ph)
// {
// 	long int	time;

// 	time = ft_gettime(ph);
// 	if (time != -1)
// 	{
// 		print_status(ph, time / 1000, MESS_FORK);
// 	}
// }
//m.lock(m);

void	take_forks_eat_put_forks(t_philo *ph)
{
	long int	time;

	ph->d->mutex_forks[ph->nb_mutex_left_fork].lock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
	if (ph->d->mutex_forks[ph->nb_mutex_right_fork].mutex_lock)
	{
		ph->d->mutex_forks[ph->nb_mutex_left_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
		usleep(50);
		take_forks_eat_put_forks(ph);
	}
	else
	{
		ph->d->mutex_forks[ph->nb_mutex_right_fork].lock(&(ph->d->mutex_forks[ph->nb_mutex_right_fork]));
		time = ft_gettime(ph);
		if (time != -1)
		{
			print_status(ph, time / 1000, MESS_FORK);
			print_status(ph, time / 1000, MESS_FORK);
			ft_eat(ph);
			put_fork(ph);
		}
	}
}

void	ft_eat(t_philo *ph)
{
	long int	time_hungry;

	ph->eat_start_time = ft_gettime(ph);
	if (ph->eat_start_time != -1)
	{
		print_status(ph, ph->eat_start_time / 1000, MESS_EAT);
	}
	ft_usleep(ph->d->time_to_eat);
	ph->eat_end_time = ft_gettime(ph);
}

void	*philosopher(void *ph)
{
	((t_philo *)ph)->nb_mutex_right_fork = ((t_philo *)ph)->id - 1;
	if (((t_philo *)ph)->nb_mutex_right_fork == 0)
		((t_philo *)ph)->nb_mutex_left_fork = ((t_philo *)ph)->d->nb_philo - 1;
	else
		((t_philo *)ph)->nb_mutex_left_fork = ((t_philo *)ph)->id - 2;
write(1, "test \n", 6);
	while (1)
	{
		take_forks_eat_put_forks(ph);
		ft_sleep((t_philo *)ph);
		ft_think((t_philo *)ph);
	}
}
