#include "philo.h"

void	ft_mutex_lock(ft_mutex_t *m)
{
	m->mutex_lock = 1;
	pthread_mutex_lock(&m->data);
}

void	ft_mutex_unlock(ft_mutex_t *m)
{
	m->mutex_lock = 0;
	pthread_mutex_unlock(&m->data);
}

void	ft_mutex_init(ft_mutex_t *m)
{
	m->mutex_lock = 0;
	m->self = m;
	m->lock = &ft_mutex_lock;
	m->unlock = &ft_mutex_unlock; 
	pthread_mutex_init(&m->data, 0);
}
