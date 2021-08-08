#include "philo.h"

void	put_fork(t_philo *ph)
{
	if (ph)
		return ;
}

void	take_forks(t_philo *ph)
{
	long int	time;

	time = ft_gettime(ph);
	if (time != -1)
	{
		print_status(ph, time / 1000, MESS_FORK);
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
	// ph->eat_end_time = ph->eat_start_time + ph->d->time_to_eat + 999;
// printf("end eat %d = %ld\n", ph->id, ph->eat_end_time);
}

void	eat_or_died(t_philo *ph)
{
	take_forks(ph);
	ft_eat(ph);
	put_fork(ph);
}

void	*philosopher(void *ph)
{
	int	i;
	i = ((t_philo *)ph)->id;
	while (1)
	{
		eat_or_died((t_philo *)ph);
		ft_sleep((t_philo *)ph);
		ft_think((t_philo *)ph);
	}
}
