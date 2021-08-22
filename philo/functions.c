#include "philo.h"

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
 * 
 * Includes functions:
 * 		2.1.3.1.1. ft_strlen;
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

/************************************
 * 		2.1.3.1.1. ft_strlen		*
 * **********************************
*/
/* Description:
 * 		Count string length.
 * 
 * Returned value:
 * 		Length of string.
*/

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/************************************
 * 		ft_usleep					*
 * **********************************
*/
/* Description:
 * 		self usleep (man usleep). The function suspends execution of the 
 * 		calling thread until either microseconds have elapsed.
*/

void	ft_usleep(long int time_stop)
{
	long int		time_start;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time_start = tv.tv_sec * 1000000 + tv.tv_usec;
	while (tv.tv_sec * 1000000 + tv.tv_usec - time_start < time_stop)
	{
		usleep(100);
		gettimeofday(&tv, NULL);
	}
}

