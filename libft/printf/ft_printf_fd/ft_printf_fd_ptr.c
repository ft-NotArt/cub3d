/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 04:56:05 by albillie          #+#    #+#             */
/*   Updated: 2025/01/03 08:23:51 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	ft_putnbr_hex_fd(unsigned long num, int fd)
{
	if (num >= 16)
	{
		ft_putnbr_hex_fd(num / 16, fd);
		ft_putnbr_hex_fd(num % 16, fd);
	}
	else
	{
		if (num < 10)
		{
			ft_printchar_fd(num + '0', fd);
		}
		else
		{
			ft_printchar_fd(num - 10 + 'a', fd);
		}
	}
}

int	ft_print_pointer_fd(void *ptr, int fd)
{
	unsigned long	address;
	size_t			print_length;

	if (ptr == 0)
	{
		return (ft_print_str_fd("(nil)", fd));
	}
	address = (unsigned long) ptr;
	print_length = 0;
	ft_print_str_fd("0x", fd);
	print_length += 2;
	ft_putnbr_hex_fd(address, fd);
	while (address)
	{
		address /= 16;
		print_length++;
	}
	return (print_length);
}

/* int main()
{
	int *ptr = NULL;

	ft_printf("%p\n", &ptr);
} */
