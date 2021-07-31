#include "philo.h"

int	simulation(t_all *all)
{
	// ◦ timestamp_in_ms X has taken a fork
	// ◦ timestamp_in_ms X is eating
	// ◦ timestamp_in_ms X is sleeping
	// ◦ timestamp_in_ms X is thinking
	// ◦ timestamp_in_ms X died
	print_status(all, 1, MESS_EAT);

	return (0);
}

void	print_status(t_all *all, int nb_philo, char *message)
{
	int	i;

	i = nb_philo % 6;
	write(STDOUT_FILENO, all->colors[i], ft_strlen(all->colors[i]));
	write(STDOUT_FILENO, message, ft_strlen(message));
	write(STDOUT_FILENO, all->colors[6], ft_strlen(all->colors[6]));
}