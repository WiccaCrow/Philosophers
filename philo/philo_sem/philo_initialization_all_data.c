#include "philo_sem.h"

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
 * 		2.1.2.	init_all_data_sem_0;
 * 		2.1.3.	init_all_data_colors;
*/

int	init_all_data(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->sim_stop_int = 0;
	if (init_all_data_av(data, av))
		return (1);
	data->ph = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->ph)
		return (write(STDERR_FILENO, "Error: malloc error\n", 20));
	if (init_all_data_sem_0(data))
		return (1);
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
 * 		2.1.2. init_all_data_sem_0	*
 * **********************************
*/
/* Description:
 * 		The function initializes semaphores. Part 1. SEM_DIE.
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
 * Includes functions:
 * 		2.1.2.1. init_all_data_sem_1;
*/

int	init_all_data_sem_0(t_data *data)
{
	sem_unlink(SEM_DIE);
	data->sem_forks = (t_sem *)malloc(1 * sizeof(t_sem));
	if (!data->sem_forks)
		return (write(STDERR_FILENO, "Error:malloc\n", 15));
	data->sem_die = sem_open(SEM_DIE, O_CREAT, 0600, 1);
	if (data->sem_die == SEM_FAILED)
	{
		free(data->sem_forks);
		return (write(STDERR_FILENO, "Error:sem_open\n", 16));
	}
	data->sem_forks->sem_up = data->nb_philo;
	return (init_all_data_sem_1(data));
}

/****************************************
 * 		2.1.2.1. init_all_data_sem_1	*
 * **************************************
*/
/* Description:
 * 		The function initializes semaphores. Part 2. SEM_FORK, SEM_BOTH_FORKS.
 * 
 * Returned value:
 * 		In case of successful initialization, 
 * 		the function returns 0, otherwise 1.
*/

int	init_all_data_sem_1(t_data *data)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_BOTH_FORKS);
	data->sem_forks->data = sem_open(SEM_FORK, O_CREAT, 0600, data->nb_philo);
	if (data->sem_forks->data == SEM_FAILED)
	{
		free(data->sem_forks);
		sem_close(data->sem_forks->data);
		sem_unlink(SEM_FORK);
		return (write(STDERR_FILENO, "Error:sem_open\n", 15));
	}
	data->sem_forks->sem_up = data->nb_philo;
	data->sem_take_both_forks = sem_open(SEM_BOTH_FORKS, O_CREAT, 0600, 1);
	if (data->sem_take_both_forks == SEM_FAILED)
	{
		free(data->sem_forks);
		sem_close(data->sem_forks->data);
		sem_unlink(SEM_FORK);
		sem_close(data->sem_die);
		sem_unlink(SEM_DIE);
		return (write(STDERR_FILENO, "Error:sem_open\n", 15));
	}
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
