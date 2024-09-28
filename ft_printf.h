/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:53:35 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/28 14:42:31 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F
# define FT_PRINT_F 

# include <stdarg.h>
# include "./libft/libft.h"

int ft_putchar(char c);
int ft_printstr(char *str);
int ft_print_int(int n);
int ft_printhex(unsigned int, const char format);
int    ft_putnbr_base(unsigned int n, const char format);
int ft_printp(unsigned long ptr);

#endif