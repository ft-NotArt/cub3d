/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:02:36 by albillie          #+#    #+#             */
/*   Updated: 2025/01/03 08:23:09 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_format_handler_fd(va_list args, char str, int fd)
{
	size_t	print_length;

	print_length = 0;
	if (str == 'c')
		print_length += ft_printchar_fd(va_arg(args, int), fd);
	else if (str == 's')
		print_length += ft_print_str_fd(va_arg(args, char *), fd);
	else if (str == 'p')
		print_length += ft_print_pointer_fd(va_arg(args, void *), fd);
	else if (str == 'd' || str == 'i')
		print_length += ft_print_nbr_fd(va_arg(args, int), fd);
	else if (str == 'u')
		print_length += ft_print_unsigned_fd(va_arg(args, unsigned int), fd);
	else if (str == 'x')
		print_length += ft_print_hex_low_fd(va_arg(args, unsigned int), fd);
	else if (str == 'X')
		print_length += ft_print_hex_up_fd(va_arg(args, unsigned int), fd);
	else if (str == '%')
		print_length += ft_printchar_fd('%', fd);
	return (print_length);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	size_t	i;
	size_t	print_length;
	va_list	args;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_format_handler_fd(args, str[i + 1], fd);
			i++;
		}
		else
		{
			print_length += ft_printchar_fd(str[i], fd);
		}
		i++;
	}
	va_end(args);
	return (print_length);
}

/* int main()
{
	int num = 14;

	ft_printf("%c\n%s\n%i\n%d\n", 'c', "string", num, num);
} */
