#include "philo.h"

/************************************
 * 		ft_clean_all				*
 * **********************************
*/
/* Description:
 * 		The function clears the memory allocated for 
 * 		t_all structure elements.
 * 
 * Includes functions:
 * 		1. ft_clean_all_data;
 * 		2. ft_clean_all_philo;
*/

void	ft_clean_all(t_all *all)
{
	if (all)
	{
		ft_clean_all_data(&all->data);
		ft_clean_all_philo(all);
	}
}

/************************************
 * 		1. ft_clean_all_data		*
 * **********************************
*/
/* Description:
 * 		The function clears the memory allocated for 
 * 		t_data structure elements.
 * 
 * Includes functions:
 * 		1.1. ft_free;
*/

void	ft_clean_all_data(t_data *data)
{
	int	i;

	ft_free((void **)&data->ph);
	ft_free((void **)&data->mutex_forks);
	i = 7;
	while (data->colors[i--])
		ft_free((void **)data->colors[i]);
	free(data->colors);
	data->colors = NULL;
}

/************************************
 * 		1.1. ft_free				*
 * **********************************
*/
/* Description:
 * 		The function clears the memory allocated
 * 		for pointer.
 * Rule to use:
 * 		pass addres of your pointer in this function.
 * example:
 * 		int *pointer;
 * 		pointer = (int *)malloc(sizeof(int) * nb);
 * 		ft_free((void **)&pointer);
*/

void	ft_free(void **pointer)
{
	if (*pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}

/************************************
 * 		2. ft_clean_all_philo		*
 * **********************************
*/
/* Description:
 * 		The function clears the memory allocated in 
 * 		t_all struct for t_philo structure elements.
 * 
 * Includes functions:
 * 		1.1. ft_free;
*/

void	ft_clean_all_philo(t_all *all)
{
	if (all->philo)
	{
		free(all->philo);
		all->philo = NULL;
	}
}
