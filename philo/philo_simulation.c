#include "philo.h"

void	put_fork(t_philo *ph)
{
	ph->d->mutex_forks[ph->nb_mutex_left_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
	ph->d->mutex_forks[ph->nb_mutex_right_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_right_fork]));
}

void	take_forks_eat_put_forks(t_philo *ph)
{
	while (1) 
	{
		ph->d->mutex_forks[ph->nb_mutex_left_fork].lock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
		if (ph->d->mutex_forks[ph->nb_mutex_right_fork].mutex_lock)
		{
			// ft_usleep(10000);
			usleep(100);
			ph->d->mutex_forks[ph->nb_mutex_left_fork].unlock(&(ph->d->mutex_forks[ph->nb_mutex_left_fork]));
			if (ph->d->sim_stop_int)
				return ;
			continue ;
		}
		else
		{
			ph->d->mutex_forks[ph->nb_mutex_right_fork].lock(&(ph->d->mutex_forks[ph->nb_mutex_right_fork]));
			print_status(ph, 0, MESS_FORK);
			if (ph->d->sim_stop_int)
			{
				put_fork(ph);
				return ;
			}
			print_status(ph, 0, MESS_FORK);
			if (ph->d->sim_stop_int)
			{
				put_fork(ph);
				return ;
			}
			ft_eat(ph);
			if (ph->d->sim_stop_int)
			{
				put_fork(ph);
				return ;
			}
			put_fork(ph);
			break ;
		}
	}
}

void	ft_eat(t_philo *ph)
{
	print_status(ph, 1, MESS_EAT);
	if (ph->d->sim_stop_int)
			return ;
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
		if (((t_philo *)ph)->d->sim_stop_int)
			return 0;
		// ft_sleep((t_philo *)ph);
		print_status(ph, 0, MESS_SLEEP);
		if (((t_philo *)ph)->d->sim_stop_int)
			return 0;
		ft_usleep(((t_philo *)ph)->d->time_to_sleep);
		if (((t_philo *)ph)->d->sim_stop_int)
			return 0;
		// ft_think((t_philo *)ph);
		print_status(ph, 0, MESS_THINK);
		if (((t_philo *)ph)->d->sim_stop_int)
			return 0;
	}
}
