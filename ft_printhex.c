/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:25:37 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/28 01:10:06 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static int  ft_hex_len(unsigned int n)
{
    unsigned int len;
    
    len = 0;
    while (n > 0)
    {
        n /= 16;
        len++;
    }
    return (len);
}

static void    ft_putnbr_base(unsigned int n, const char format)
{
    if (n >= 16)
    {
        ft_putnbr_base(n / 16, format);
        ft_putnbr_base(n % 16, format);
    }
    else if (n <= 9)
    {
        ft_putchar_fd((n + '0'), 1);   
    }
    else 
    {
        if (format == 'x')
            ft_putchar_fd((n - 10) + 'a', 1);
        if (format == 'X')
            ft_putchar_fd((n - 10) + 'A', 1);
    }
}

int ft_printhex(unsigned int n, const char format)
{
    if (n == 0)
        return (ft_putchar('0'));
    else
        ft_putnbr_base(n, format);
    return (ft_hex_len(n));
}