#include "philo.h"

long int	ft_gettime(t_all *all)
{
	long int	timestap_in_ms;	

	if (gettimeofday(&all->tv, NULL))
	{
		(write(STDERR_FILENO, "Error: gettimeofday error\n", 26));
		all->comp_code = 1;
		return (-1);
	}
	timestap_in_ms = all->tv.tv_sec * 1000 + all->tv.tv_usec / 1000;
	return (timestap_in_ms);
}

void	ft_think(t_all *all)
{
	long int	time;

	time = ft_gettime(all);
	if (time != -1)
		print_status(all, time, 1, MESS_THINK);	
}

void	ft_sleep(t_all *all)
{
	long int	time;

	time = ft_gettime(all);
	if (time != -1)
		print_status(all, time, 1, MESS_SLEEP);	
}

void	ft_eat(t_all *all)
{
	long int	time;

	time = ft_gettime(all);
	if (time != -1)
		print_status(all, time, 1, MESS_EAT);	
}

void	ft_died(t_all *all)
{
	long int	time;

	time = ft_gettime(all);
	if (time != -1)
		print_status(all, time, 1, MESS_DIED);	
}

void	print_status(t_all *all, long int timestap_in_ms, int nb_philo, char *message)
{
	int	i;

	i = nb_philo % 6;
	printf("%s%ld %d%s%s", all->colors[i], timestap_in_ms, nb_philo, message, all->colors[6]);
}
