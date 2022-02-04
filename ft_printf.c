/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleon-ba <bleon-ba@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:31:58 by bleon-ba          #+#    #+#             */
/*   Updated: 2021/10/18 18:06:15 by bleon-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *len)
{
	write(fd, &c, 1);
	*len += 1;
}

void	ft_putnbr_fd(int n, int fd, int *len)
{
	long	number;

	number = n;
	while (number < 0)
	{
		ft_putchar_fd('-', fd, len);
		number = number * -1;
	}
	if (number >= 10)
		ft_putnbr_fd (number / 10, fd, len);
	ft_putchar_fd ((number % 10) + '0', fd, len);
}

void	ft_putuns_fd(int n, int fd, int *len)
{
	unsigned int	num;

	num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd, len);
	ft_putchar_fd((num % 10) + '0', fd, len);
}

void	ft_putstr_fd(char *s, int fd, int *len)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd, len);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	parameters;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(parameters, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_flags(str[i], parameters, &len);
		}
		else
			ft_putchar_fd(str[i], 1, &len);
		i++;
	}
	va_end(parameters);
	return (len);
}
