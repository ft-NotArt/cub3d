/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:33:04 by albillie          #+#    #+#             */
/*   Updated: 2025/01/03 08:21:15 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"
#include "libft.h"

int	ft_printchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_print_str_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_printchar_fd(str[i], fd);
		i++;
	}
	return (i);
}

int	ft_print_nbr_fd(int nbr, int fd)
{
	int	print_length;

	print_length = 0;
	if (nbr == -2147483648)
	{
		return (ft_print_str_fd("-2147483648", fd));
	}
	if (nbr < 0)
	{
		print_length += ft_printchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		print_length += ft_print_nbr_fd(nbr / 10, fd);
		print_length += ft_printchar_fd((nbr % 10) + '0', fd);
	}
	else
	{
		print_length += ft_printchar_fd(nbr + '0', fd);
	}
	return (print_length);
}

int	ft_print_unsigned_fd(unsigned int n, int fd)
{
	int	print_length;

	print_length = 0;
	if (n >= 10)
	{
		print_length += ft_print_unsigned_fd(n / 10, fd);
		print_length += ft_printchar_fd((n % 10) + '0', fd);
	}
	else
	{
		print_length += ft_printchar_fd(n + '0', fd);
	}
	return (print_length);
}
