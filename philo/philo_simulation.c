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
		print_status(ph, time, MESS_FORK);
	}
}


void	ft_eat(t_philo *ph)
{
	long int	time;
	long int	time_hungry;

	time = ft_gettime(ph);
	if (time != -1)
	{
		print_status(ph, time, MESS_EAT);
	}
	ft_usleep(ph->d->time_to_eat / 1000);// в ft_usleep милисекунды, поэтому не нужно переводить из в микросекунды
	ph->eat_end_time = ft_gettime(ph);

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
