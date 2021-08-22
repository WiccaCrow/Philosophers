#include "philo.h"

/************************************
 * 		2. initialization			*
 * **********************************
*/
/* Description:
 * 		The function allocate the memory  for 
 * 		t_all structure pointers and sets start 
 * 		value for other elements.
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
 * Includes functions:
 * 		2.1. init_all_data;
 * 		2.2. init_all_philo;
*/

int	initialization(t_all *all, char **av)
{
	memset(all, 0, sizeof(t_all));
	if (init_all_data(&all->data, av) || init_all_philo(all, &all->philo))
		return (1);
	return (0);
}

/************************************
 * 		2.1. init_all_data			*
 * **********************************
*/
/* Description:
 * 		The function allocate the memory  for 
 * 		t_data structure pointers and sets start 
 * 		value for other elements.
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
 * Includes functions:
 * 		2.1.1.	init_all_data_av;
 * 		2.1.2.	ft_mutex_init;
 * 		2.1.3.	init_all_data_colors;
*/

int	init_all_data(t_data *data, char **av)
{
	int	i;

	memset(data, 0, sizeof(t_data));
	data->sim_stop_int = 0;
	if (init_all_data_av(data, av))
		return (1);
	data->ph = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->ph)
		return (write(STDERR_FILENO, "Error: malloc error\n", 20));
	data->mutex_forks = (ft_mutex_t *)malloc(sizeof(ft_mutex_t) * data->nb_philo);
	data->mutex_die = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	i = -1;
	while (++i < data->nb_philo)
		ft_mutex_init(&data->mutex_forks[i]);
	if (init_all_data_colors(data))
		return (write(STDERR_FILENO, "Error: malloc error\n", 20));
	return (0);
}

/************************************
 * 		2.1.1. init_all_data_av		*
 * **********************************
*/
/* Description:
 * 		The function initializes elements from arguments (av).
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
 * Includes functions:
 * 		2.1.1.1. ft_atoi;
*/

int	init_all_data_av(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]) * 1000;
	data->time_to_eat = ft_atoi(av[3]) * 1000;
	data->time_to_sleep = ft_atoi(av[4]) * 1000;
	if (av[5])
		data->time_stop_eat = ft_atoi(av[5]);
	if (data->nb_philo < 1)
		return (write(STDERR_FILENO, "Error: no one philosopher\n", 26));
	return (0);
}

/************************************
 * 		2.1.3. init_all_data_colors	*
 * **********************************
*/
/* Description:
 * 		The function initializes an array of colors for color output to 
 * 		the philosophers statuses terminal.
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
 * Includes functions:
 * 		2.1.3.1. ft_strdup;
*/

int	init_all_data_colors(t_data *data)
{
	data->colors = (char **)malloc(sizeof(char *) * 8);
	if (data->colors)
	{
		data->colors[0] = ft_strdup(ANSI_COLOR_RED);
		data->colors[1] = ft_strdup(ANSI_COLOR_GREEN);
		data->colors[2] = ft_strdup(ANSI_COLOR_YELLOW);
		data->colors[3] = ft_strdup(ANSI_COLOR_BLUE);
		data->colors[4] = ft_strdup(ANSI_COLOR_MAGENTA);
		data->colors[5] = ft_strdup(ANSI_COLOR_CYAN);
		data->colors[6] = ft_strdup(ANSI_COLOR_RESET);
		data->colors[7] = NULL;
		if (data->colors[0] && data->colors[1] && data->colors[2]
			&& data->colors[3] && data->colors[4] && data->colors[5]
			&& data->colors[6])
			return (0);
	}
	return (1);
}

/************************************
 * 		init_all_philo				*
 * **********************************
*/
/* Description:
 * 		The function allocate the memory  for 
 * 		t_philo structure pointers and sets start 
 * 		value for other elements.
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
*/

int	init_all_philo(t_all *all, t_philo	**all_philo)
{
	int	i;
	int	i_col;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * all->data.nb_philo);
	if (!philo)
		return (write(STDERR_FILENO, "Error: malloc error\n", 20));
	memset(philo, 0, sizeof(t_philo));
	i = -1;
	while (++i < all->data.nb_philo)
	{
		philo[i].d = &all->data;
		philo[i].id = i + 1;
		i_col = philo[i].id % 6;
		philo[i].print_color = all->data.colors[i_col];
	}
	*all_philo = philo;
	return (0);
}
