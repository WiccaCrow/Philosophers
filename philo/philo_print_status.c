#include "philo.h"

void	ft_think(t_philo *ph)
{
	print_status(ph, 0, MESS_THINK);
		// printf("%s%ld %d%s%s\n", ph->d->colors[i], time, ph->id, MESS_THINK, ph->d->colors[6]);
}

void	ft_sleep(t_philo *ph)
{
	print_status(ph, 0, MESS_SLEEP);
	ft_usleep(ph->d->time_to_sleep);
}

void	print_status(t_philo *ph, long int does_eat, char *message)
{
// int		i;

// i = ph->id % 6;

// ft_usleep(50);

	long int	timestap_in_ms;

	pthread_mutex_lock(&(ph->d->mutex_die));
	timestap_in_ms = ft_gettime(ph);
	if (does_eat)
		ph->eat_start_time = timestap_in_ms;
// timestap_in_ms /= 1000;
	printf("%s%ld %d%s%s\n", ph->print_color, timestap_in_ms / 1000, ph->id, message, ph->d->colors[6]);

// write(STDOUT_FILENO, ph->print_color, ft_strlen(ph->print_color));
// ft_putnbr_fd(timestap_in_ms, STDOUT_FILENO);
// write(STDOUT_FILENO, " ", 1);
// ft_putnbr_fd(ph->id, STDOUT_FILENO);
// write(STDOUT_FILENO, message, ft_strlen(message));
// write(STDOUT_FILENO, ph->d->colors[6], ft_strlen(ph->d->colors[6]));
// write(STDOUT_FILENO, "\n", 1);

	pthread_mutex_unlock(&(ph->d->mutex_die));
}
