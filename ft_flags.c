/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleon-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:33:14 by bleon-ba          #+#    #+#             */
/*   Updated: 2021/09/29 19:05:06 by bleon-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(char flag, va_list list, int *len)
{
	if (flag == 'c')
		ft_putchar_fd(va_arg(list, int), 1, len); 
	else if (flag == 's')
		ft_putstr_fd(va_arg(list, char *), 1, len);
	else if (flag == 'p')
	else if (flag == 'd' || flag == 'i' )
		ft_putnbr_fd(va_arg(list, int), 1, len);
	else if (flag == 'u')
		ft_putuns_fd(va_arg(list, unsigned int), 1, len);
	else if (flag == 'x')
	else if (flag == 'X')
	else if (flag == '%')
}
