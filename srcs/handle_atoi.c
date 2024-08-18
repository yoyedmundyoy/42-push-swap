#include "../includes/push_swap.h"

int	handle_atoi(const char *str)
{
	int		sign;
	char	*ptr;
	int		num;

	sign = 1;
	ptr = (char *)str;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		++ptr;
	if (*ptr == '-' || *ptr == '+')
	{
		if (!ft_isdigit(*(ptr + 1)))
			return (-1);
		else if (*ptr == '-')
			sign *= -1;
		++ptr;
	}
	num = 0;
    if (!ft_isdigit(*ptr))
        return (-1);
	while (ft_isdigit(*ptr))
	{
		num = (num * 10) + (*ptr - '0');
		ptr++;
	}
	return (sign * num);
}