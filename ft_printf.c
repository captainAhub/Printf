/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleon-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:46:35 by bleon-ba          #+#    #+#             */
/*   Updated: 2021/09/29 18:30:19 by bleon-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putchar_fd(char c, int fd, int *len)
{
	write(fd, &c, 1);
	*len += 1;
}

void	ft_putnbr_fd(int n, int fd, int *len)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd((n/10), fd, len);
		ft_putchar_fd('8', fd, len);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, len);
		ft_putnbr_fd(-n, fd, len);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd, len);
		ft_putchar_fd(n % 10 + '0', fd, len);
	}
}

void	ft_putuns_fd(int n, int fd, int *len)
{
	unsigned int	num;

	num = n;
	if (num > 9)
		ft_putnbr_fd(num / 10, fd, len);
	ft_putchar_fd((num % 10) + '0', fd, len);
}

void	ft_putstr_fd(char *s, int fd, int *len)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s)
	{
		ft_putchar_fd(s[i], fd, len);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_flags(str[i], list, &len);
		}
		else
			ft_putchar_fd(str[i], 1, len);
		i++:
	}
	va_end(list);
	return (len);
}
