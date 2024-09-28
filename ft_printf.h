/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:53:35 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/28 00:53:44 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F
# define FT_PRINT_F 

# include <stdarg.h>
# include "./libft/libft.h"

int ft_putchar(char c);
int ft_printstr(char *str);
int ft_printnumber(int n);
int ft_printhex(unsigned int, const char format);

#endif