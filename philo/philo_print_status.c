#include "philo.h"

long int	ft_gettime(t_philo *ph)
{
	long int	timestap_in_ms;	

	if (gettimeofday(&ph->tv, NULL))
	{
		(write(STDERR_FILENO, "Error: gettimeofday error\n", 26));
		ph->d->comp_code = 1;
		return (-1);
	}
	timestap_in_ms = ph->tv.tv_sec * 1000 + ph->tv.tv_usec / 1000;
	return (timestap_in_ms);
}

int	ft_think(t_philo *ph)
{
	long int	time;
	time = ft_gettime(ph);
	if (time != -1)
		print_status(ph, time, MESS_THINK);
	return (time);
}

void	ft_sleep(t_philo *ph)
{
	long int	time;

	time = ft_gettime(ph);
	if (time != -1)
		print_status(ph, time, MESS_SLEEP);
	usleep(ph->d->time_to_sleep);
}

void	ft_eat(t_philo *ph)
{
	long int	time;
	long int	time_hungry;

	time = ft_gettime(ph);
	time_hungry = time - ph->eat_end_time;
	if (time != -1)
	{
		if (time_hungry >= ph->d->time_to_die)
		{
			printf("%ld\n", time_hungry);
			ft_died(ph);
			ph->died = 1;
			return ;
		}
		print_status(ph, time, MESS_EAT);
	}
	usleep(ph->d->time_to_eat);
	ph->eat_end_time = ft_gettime(ph);
}

void	ft_died(t_philo *ph)
{
	long int	time;

	time = ft_gettime(ph);
	if (time != -1)
		print_status(ph, time, MESS_DIED);
}

void	print_status(t_philo *ph, long int timestap_in_ms, char *message)
{
	int		i;
	char	*str_nb;

	i = ph->id % 6;
	printf("%s%ld %d%s%s", ph->d->colors[i], timestap_in_ms, ph->id, message, ph->d->colors[6]);

	// write(STDOUT_FILENO, ph->d->colors[i], ft_strlen(ph->d->colors[i]));
	// str_nb = ft_itoa(timestap_in_ms);
	// write(STDOUT_FILENO, str_nb, ft_strlen(str_nb));
	// free(str_nb);
	// write(STDOUT_FILENO, " ", 1);
	// str_nb = ft_itoa(ph->id);
	// write(STDOUT_FILENO, str_nb, ft_strlen(str_nb));
	// free(str_nb);
	// write(STDOUT_FILENO, message, ft_strlen(message));
	// write(STDOUT_FILENO, ph->d->colors[6], ft_strlen(ph->d->colors[6]));
	// write(STDOUT_FILENO, "\n", 1);
}
