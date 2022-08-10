/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:52 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/08/10 17:19:53 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h> // va_list, va_start, va_arg, va_end가 정의된 헤더 파일
#include <unistd.h>

int     ft_printf(const char *str, ...);
int    ft_check_flag(va_list args, const char c);
void	ft_putchar(char c, int* res);
void	ft_putstr(char *s, int* res);
void	ft_putnbr(int n, int *res);
void	ft_print_ui(unsigned int n, int* res);
void    ft_print_hex(unsigned int n, char flag, int *res);
void    ft_print_ptr(void *ptr, int *res);
void	ft_print_addr(unsigned long long n, int *res);

#endif
