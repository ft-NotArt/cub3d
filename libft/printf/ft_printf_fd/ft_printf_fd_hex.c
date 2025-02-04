/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:19:07 by albillie          #+#    #+#             */
/*   Updated: 2025/01/03 07:55:21 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_print_hex_low_fd(unsigned int num, int fd)
{
	size_t	string_length;
	char	*hex;

	string_length = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
	{
		string_length += ft_print_hex_low_fd(num / 16, fd);
	}
	string_length += write(fd, &hex[num % 16], 1);
	return (string_length);
}

int	ft_print_hex_up_fd(unsigned int num, int fd)
{
	size_t	string_length;
	char	*hex;

	string_length = 0;
	hex = "0123456789ABCDEF";
	if (num >= 16)
	{
		string_length += ft_print_hex_up_fd(num / 16, fd);
	}
	string_length += write(fd, &hex[num % 16], 1);
	return (string_length);
}

/* int main()
{
	unsigned int a = 255;

	ft_printf("%X\n", a);
} */
