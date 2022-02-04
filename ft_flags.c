/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleon-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:33:14 by bleon-ba          #+#    #+#             */
/*   Updated: 2022/02/04 12:35:13 by bleon-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_baseconvert(unsigned long int nbr, int base, int *len)
{
	if (nbr / base > 0)
	{
		ft_baseconvert(nbr / base, base, len);
		if (nbr % base < 10)
			ft_putnbr_fd(nbr % base, 1, len);
		else
			ft_putchar_fd(nbr %  base + 87, 1, len);
	}
	else
	{
		if (nbr < 10)
			ft_putnbr_fd(nbr, 1, len);
		else
			ft_putchar_fd(nbr + 87, 1, len);
	}
}

void	ft_baseconvertup(unsigned int nbr, int base, int *len)
{
	if (nbr / base > 0)
	{
		ft_baseconvertup(nbr / base, base, len);
		if (nbr % base < 10)
			ft_putnbr_fd(nbr % base, 1, len);
		else
			ft_putchar_fd(nbr % base + 55, 1, len);
	}
	else
	{
		if (nbr < 10)
			ft_putnbr_fd(nbr, 1, len);
		else
			ft_putchar_fd(nbr + 55, 1, len);
	}
}

void	ft_flags(char flag, va_list list, int *len)
{
	if (flag == 'c')
		ft_putchar_fd(va_arg(list, int), 1, len); 
	else if (flag == 's')
		ft_putstr_fd(va_arg(list, char *), 1, len);
	else if (flag == 'p')
	{
		ft_putstr_fd("0x", 1, len);
		ft_baseconvert(va_arg(list, uintptr_t), 16, len);
	}
	else if (flag == 'd' || flag == 'i' )
		ft_putnbr_fd(va_arg(list, int), 1, len);
	else if (flag == 'u')
		ft_putuns_fd(va_arg(list, unsigned int), 1, len);
	else if (flag == 'x')
		ft_baseconvert(va_arg(list, unsigned int), 16, len);
	else if (flag == 'X')
		ft_baseconvertup(va_arg(list, unsigned int), 16, len);
	else if (flag == '%')
		ft_putchar_fd('%', 1, len);
}
