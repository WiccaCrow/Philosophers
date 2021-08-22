#include "philo.h"

void	ft_putnbr_fd(long int n, int fd)
{
	long int		i;
	unsigned int	u_n;
	char			c_num;

	i = 1;
	n == 0 ? write(fd, "0", 1) : 0;
	if (n < 0)
		write(fd, "-", 1);
	u_n = n < 0 ? -n : n;
	while (n / i)
		i *= 10;
	while (i /= 10)
	{
		c_num = u_n / i + '0';
		u_n = u_n % i;
		write(fd, &c_num, 1);
	}
}

/************************************
 * 		2.1.1.1. ft_atoi			*
 * **********************************
*/
/* Description:
 * 		self atoi (man atoi). Convert string to number.
 * 
 * Returned value:
 * 		Number.
 * Includes functions:
 * 		2.1.1.1. ft_atoi;
*/

long int	ft_atoi(const char *str)
{
	int			i;
	long int	n;
	int			sign;

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

/************************************
 * 		2.1.3.1. ft_strdup			*
 * **********************************
*/
/* Description:
 * 		self strdup (man strdup). Do strings copy.
 * 
 * Returned value:
 * 		New string. Need to free.
*/

char	*ft_strdup(const char *s1)
{
	char	*c_copy;
	int		len;

	len = ft_strlen(s1);
	if ((c_copy = malloc((len + 1) * sizeof(char))) == 0)
		return (NULL);
	c_copy[len] = 0;
	while (len--)
	{
		c_copy[len] = s1[len];
	}
	return (c_copy);
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
	// long int		time_last;
	struct timeval	tv;

	// time_st;
	gettimeofday(&tv, NULL);
	time_start = tv.tv_sec * 1000000 + tv.tv_usec;
	// long int t_st = tv.tv_sec * 1000000 + tv.tv_usec;
	while (tv.tv_sec * 1000000 + tv.tv_usec - time_start < time_stop)
	{
		usleep(100);
		gettimeofday(&tv, NULL);
	}
	// if (tv.tv_sec * 1000 + tv.tv_usec /1000 - time_start == time_stop)
	// 	if (tv.tv_sec * 1000000 + tv.tv_usec - t_st <= time_stop * 1000)
	// 		usleep(tv.tv_sec * 1000000 + tv.tv_usec - t_st - time_stop * 1000);
}

