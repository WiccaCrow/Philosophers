#include "philo.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	n;
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