/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:04:20 by albillie          #+#    #+#             */
/*   Updated: 2025/01/03 08:23:23 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf_fd(int fd, const char *str, ...);
int		ft_printchar_fd(int c, int fd);
int		ft_print_str_fd(char *str, int fd);
int		ft_print_nbr_fd(int nbr, int fd);
int		ft_print_unsigned_fd(unsigned int n, int fd);
int		ft_print_pointer_fd(void *ptr, int fd);
int		ft_print_hex_low_fd(unsigned int num, int fd);
int		ft_print_hex_up_fd(unsigned int num, int fd);
void	ft_putnbr_hex_fd(unsigned long num, int fd);

#endif
