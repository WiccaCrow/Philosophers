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

typedef struct	s_ft_mutex
{
	pthread_mutex_t		data;
	// atomic int			mutex_lock;
	int			mutex_lock;
	struct s_ft_mutex	*self;

	void				(*lock)(struct s_ft_mutex *self);
	void				(*unlock)(struct s_ft_mutex *self);
}				ft_mutex_t;

typedef struct	s_data
{
	pthread_t		*ph;
	pthread_mutex_t	mutex_die;
	ft_mutex_t		*mutex_forks;
	int				nb_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		time_stop_eat;
	char			**colors;
	int				died;
	long int		died_time;
	long int		simul_start;
	// struct timeval	tv;
	int				sim_stop_int;
}				t_data;

typedef struct	s_philo
{
	int				id;
	char			*print_color;
	long int		eat_end_time;
	long int		eat_start_time;
	struct timeval	tv;
	t_data			*d;
	int				nb_mutex_left_fork;
	int				nb_mutex_right_fork;
}				t_philo;

typedef struct	s_all
{
	t_data			data;
	t_philo			*philo;
	pthread_t		sim_stop;
}				t_all;

void	ft_mutex_init(ft_mutex_t *m);
void	ft_mutex_unlock(ft_mutex_t *m);
void	ft_mutex_lock(ft_mutex_t *m);

void			ft_putnbr_fd(long int n, int fd);
long int		ft_atoi(const char *str);
int				ft_strlen(const char *s);
char			*ft_itoa(long int n);
void			ft_usleep(long int time_stop);
void			exit_clean(t_all *all);

int			valid_ac(int ac, char **av);
int			start_all(t_all *all, char **av);
int			simulation(t_all *all);
void		*simulation_stop(void *all);
int			check_time_to_die(t_philo *ph, t_data *d, long int time_current);

void		*philosopher(void *all);
long int	ft_gettime_simul_start();
long int	ft_gettime(t_philo *all);
void		take_forks_eat_put_forks(t_philo *all);
void		ft_eat(t_philo *all);
void		ft_sleep(t_philo *all);
void		ft_think(t_philo *all);
void		print_status(t_philo *all, long int timestap_in_ms, char *message);

#endif