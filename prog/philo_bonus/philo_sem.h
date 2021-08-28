#ifndef PHILO_SEM_H
# define PHILO_SEM_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

# define MESS_FORK " has taken a fork"
# define MESS_EAT " is eating"
# define MESS_SLEEP " is sleeping"
# define MESS_THINK " is thinking"
# define MESS_DIED " died"

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define SEM_DIE "sem_die"
# define SEM_FORK "sem_fork"
# define SEM_BOTH_FORKS "sem_both_fork"

typedef struct s_ft_sem
{
	sem_t	*data;
	int		sem_up;
}				t_sem;

typedef struct s_data
{
	pthread_t		*ph;
	sem_t			*sem_die;
	t_sem			*sem_forks;
	sem_t			*sem_take_both_forks;
	int				nb_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		time_stop_eat;
	char			**colors;
	long int		simul_start;
	int				sim_stop_int;
}				t_data;

typedef struct s_philo
{
	int				id;
	char			*print_color;
	long int		eat_start_time;
	int				eat_nb;
	struct timeval	tv;
	t_data			*d;
}				t_philo;

typedef struct s_all
{
	t_data			data;
	t_philo			*philo;
	pthread_t		sim_stop;
}				t_all;

void		ft_sem_down(t_sem *sem_forks);
void		ft_sem_up(t_sem *sem_forks);
void		ft_sem_free(t_all *all);

long int	ft_atoi(const char *str);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
void		ft_usleep(long int time_stop);

void		ft_clean_all(t_all *all);
void		ft_clean_all_philo(t_all *all);
void		ft_clean_all_data(t_data *data);
void		ft_free(void **pointer);

int			valid_ac_av(int ac, char **av);
int			valid_av(char *av);

int			initialization(t_all *all, char **av);
int			init_all_data(t_data *data, char **av);
int			init_all_data_av(t_data *data, char **av);
int			init_all_data_sem_0(t_data *data);
int			init_all_data_sem_1(t_data *data);
int			init_all_data_colors(t_data *data);
int			init_all_philo(t_all *all, t_philo	**all_philo);

int			simulation(t_all *all);
long int	ft_gettime_simul_start(void);
void		*philosopher(void *all);
int			take_forks_eat_put_forks(t_philo *all);
void		take_forks(t_philo *ph);
int			print_status(t_philo *ph, long int timestap_in_ms, char *message);
long int	ft_gettime(t_philo *ph);
int			put_forks(t_philo *ph);
int			ft_eat(t_philo *all);

void		*simulation_stop(void *all);
int			check_time_to_die(t_philo *ph, t_data *d, long int time_current);
int			check_stop_eat(t_all *all, int nb_max_eat);

#endif