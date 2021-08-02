#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<sys/time.h>
# include <pthread.h>

# define MESS_FORK " has taken a fork"
# define MESS_EAT " is eating"
# define MESS_SLEEP " is sleeping"
# define MESS_THINK " is thinking"
# define MESS_DIED " died"

# define MASS (1 ,2, 3)
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct	s_data
{
	int				comp_code;
	pthread_t		*ph;
	int				nb_philo;
	long int		time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_stop_eat;
	char			**colors;
	int				died;
	long int		died_time;
	long int		simul_start;
	// struct timeval	tv;
}				t_data;

typedef struct	s_philo
{
	int				id;
	long int		eat_end_time;
	// int				died;
	struct timeval	tv;
	t_data			*d;
	
}				t_philo;

typedef struct	s_all
{
	t_data	data;
	t_philo	*philo;
}				t_all;

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
char	*ft_itoa(long int n);
void	exit_clean(t_all *all);

int			valid_ac(int ac, char **av);
int			start_all(t_all *all, char **av);
void		*watching_every_alive(void *all);
int			simulation(t_all *all);
void		*philosopher(void *all);

long int	ft_gettime(t_philo *all);
void		ft_think(t_philo *all);
void		ft_sleep(t_philo *all);
void		ft_eat(t_philo *all);
void		ft_died(t_philo *all);
void		print_status(t_philo *all, long int timestap_in_ms, char *message);

#endif