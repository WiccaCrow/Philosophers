#include "philo.h"

void	put_fork(t_philo *ph)
{
	if (ph)
		return ;
}

void	take_forks(t_philo *ph)
{
	long int	time;

	time = ft_gettime(ph) - ph->d->simul_start;
	if (time != -1)
	{
		print_status(ph, time, MESS_FORK);
	}
}


void	ft_eat(t_philo *ph)
{
	long int	time;
	long int	time_hungry;

	time = ft_gettime(ph) - ph->d->simul_start;
	time_hungry = time - ph->eat_end_time;
printf("time = %ld | ph->eat_end_time = %ld | hungry = %ld | max time = %ld\n", time, ph->eat_end_time, time_hungry, ph->d->time_to_die);
	if (time != -1)
	{
		if (time_hungry >= ph->d->time_to_die)
		{
			ft_died(ph);
			ph->d->died = 1;
			exit(2) ;
		}
		print_status(ph, time, MESS_EAT);
	}
	usleep(ph->d->time_to_eat);
	ph->eat_end_time = ft_gettime(ph) - ph->d->simul_start;
	printf("ph->eat_end_time = %ld\n", ph->eat_end_time);
}

void	eat_or_died(t_philo *ph)
{
	take_forks(ph);
	ft_eat(ph);
	put_fork(ph);
}

void	*philosopher(void *ph)
{
	while (0 == ((t_philo *)ph)->d->died)
	{
		eat_or_died((t_philo *)ph);
		if (0 == ((t_philo *)ph)->d->died) 
		{
			ft_sleep((t_philo *)ph);
			ft_think((t_philo *)ph);
		}
	}
}
