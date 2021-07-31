#include "philo.h"

void	put_fork(t_all *all)
{
	if (all)
		return ;
}

void	take_forks(t_all *all)
{
	long int	time;

	time = ft_gettime(all);
	if (time != -1)
	{
		print_status(all, time, 1, MESS_FORK);
		ft_died(all);
	}
}

void	eat_or_died(t_all *all)
{
	take_forks(all);
	ft_eat(all);
	put_fork(all);
}

int	simulation(t_all *all)
{
	ft_think(all);
	ft_sleep(all);
	eat_or_died(all);
	return (0);
}
