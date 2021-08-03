#include "philo.h"

long int	ft_atoi(const char *str)
{
	int					i;
	long int	n;
	int					sign;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	str[i] == '+' && str[i + 1] != '-' ? i++ : 0;
	str[i] == '-' ? sign = -1 : 0;
	str[i] == '-' ? i++ : 0;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	if (n > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	return (sign == -1 ? n = -n : n);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_charnbr(char *s, int n, int i, int flag)
{
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	if (n == 0)
		*s = '0';
	while (--i >= 0 && n != 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
	}
	if (flag)
		s[10] = '8';
	return (s);
}

char		*ft_itoa(long int n)
{
	char	*s;
	int		i;
	int		c;
	int		flag;

	flag = 0;
	i = 1;
	if (n == -2147483648)
	{
		flag = 1;
		n++;
	}
	c = n;
	while ((c /= 10))
		i++;
	n < 0 ? i++ : 0;
	if (!(s = (char *)malloc(sizeof(char) * ++i)))
		return (NULL);
	s[--i] = 0;
	s = ft_charnbr(s, n, i, flag);
	return (s);
}

void	ft_usleep(long int time_stop)
{
	long int		time_start;
	long int		time_last;
	struct timeval	tv;	

	time_start = ft_gettime_simul_start();
// printf("usleep 0 %ld\n", time_start);
	time_last = time_start;
	while (time_last - time_start < time_stop)
	{
		time_last = ft_gettime_simul_start();
// printf("usleep 1\n");
		usleep(100);
		usleep(100);
		usleep(100);
		usleep(100);
		usleep(100);
// printf("usleep 2 %ld\n", time_last);
	}
// printf("usleep 3\n");
}