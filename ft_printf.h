/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleon-ba <bleon-ba@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:36:43 by bleon-ba          #+#    #+#             */
/*   Updated: 2021/10/06 17:01:21 by bleon-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

void	ft_baseconvert(unsigned long int nbr, int base, int *len);
void	ft_baseconvertup(unsigned int nbr, int base, int *len);
void	ft_putchar_fd(char c, int fd, int *len);
void	ft_putnbr_fd(int n, int fd, int *len);
void	ft_putuns_fd(int n, int fd, int *len);
void	ft_putstr_fd(char *s, int fd, int *len);
int		ft_printf(const char *str, ...);
void	ft_flags(char flag, va_list parameters, int *len);

#endif
