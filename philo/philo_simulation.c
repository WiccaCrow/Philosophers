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

void	eat_or_died(t_philo *ph)
{
	take_forks(ph);
	ft_eat(ph);
	put_fork(ph);
}

void	*simulation(void *ph)
{
	((t_philo *)ph)->eat_end_time = ft_gettime((t_philo *)ph);
	while (0 == ((t_philo *)ph)->died)
	{
		eat_or_died((t_philo *)ph);
		if (0 == ((t_philo *)ph)->died) 
		{
			ft_sleep((t_philo *)ph);
			ft_think((t_philo *)ph);
		}
	}
	return (0);
}
